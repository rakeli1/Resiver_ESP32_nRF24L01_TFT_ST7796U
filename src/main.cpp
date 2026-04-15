// Перешел на линукс 15 апреля 2026 года 
#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include "MainPage.h"
#include "RadioData.h"
#include "ForecastPage.h"
#include "PageManager.h"
#include "SettingPage.h"
#include "CurrencyPage.h"
#include  <Wire.h>
#include "FT6336U.h"
#include "struct_TouchState.h"
#include "esp_task_wdt.h"
#include "WiFiManager.h"
#include "InternetForecast.h"
#include "DataResiver.h"
#include "InternetTimeData.h"
#include <RTClib.h>
#include "InternetCurrency.h"

#define CE_PIN  26
#define CSN_PIN 27

RTC_DS3231 rtc;
RF24 radio(CE_PIN,CSN_PIN);
byte address[][6] = {"1Node", "2Node", "3Node", "4Node", "5Node", "6Node"}; 

TFT_eSPI tft = TFT_eSPI();
WiFiManager wifi("TP-Link_C810","91891518");
FT6336U gl_touch(5, 34);

///////////////////////////// ТАЧ и КЛАВИАТУРА ДИНАМИЧЕСКИЙ ВВОД    ///////////////////
TFT_eSprite sprite = TFT_eSprite(&tft);
struct Key
{
  int x, y;
  char lower;
  char upper;
};
Key key[] = {{20, 60, 'a', 'A'},
             {60, 60, 'b', 'B'},
             {100, 60, 'c', 'C'},
             {140, 60, 'd', 'D'},
             {180, 60, 'e', 'E'},
             {220, 60, 'f', 'F'},
             {260, 60, 'g', 'G'},
             {300, 60, 'h', 'H'},
             {340, 60, 'i', 'I'},
             {380, 60, 'j', 'J'},
             {420, 60, 'k', 'K'},
             {460, 60, 'l', 'L'},
             {20, 100, 'm', 'M'},
             {60, 100, 'n', 'N'},
             {100, 100, 'o', 'O'},
             {140, 100, 'p', 'P'},
             {180, 100, 'q', 'Q'},
             {220, 100, 'r', 'R'},
             {260, 100, 's', 'S'},
             {300, 100, 't', 'T'},
             {340, 100, 'u', 'U'},
             {380, 100, 'v', 'V'},
             {420, 100, 'w', 'W'},
             {460, 100, 'x', 'X'},
             {20, 140, 'y', 'Y'},
             {60, 140, 'z', 'Z'},
             {100, 140, '1', '1'},
             {140, 140, '2', '2'},
             {180, 140, '3', '3'},
             {220, 140, '4', '4'},
             {260, 140, '5', '5'},
             {300, 140, '6', '6'},
             {340, 140, '7', '7'},
             {380, 140, '8', '8'},
             {420, 140, '9', '9'},
             {460, 140, '0', '0'},
             {20, 180, '.', '.'},
             {60, 180, ',', ','},
             {100, 180, ':', ':'},
             {140, 180, ';', ';'},
             {180, 180, '!', '!'},
             {220, 180, '?', '?'},
             {260, 180, '#', '#'},
             {300, 180, '@', '@'},
             {340, 180, '/', '/'},
             {380, 180, '\\', '\\'},
             {420, 180, '&', '&'},
             {460, 180, '%', '%'},
             {20, 220, '=', '='},                                                    //
             {60, 220, '_', '_'},                                                    //
             {100, 220, '-', '-'},                                                   //
             {140, 220, '(', '('},                                                   //
             {180, 220, ')', ')'},                                                   //                              
             {220, 220, '"', '"'},                                                   //
             {260, 220, '+', '+'},                                                   //
             {300, 220, '$', '$'},                                                   //
             {340, 220, '{', '{'},                                                   //
             {380, 220, '}', '}'},                                                   //
             {420, 220, '*', '*'},                                                   //
             {460, 220, '[', '['},                                                   //
             {20, 260, ']', ']'},                                                    //
             {60, 260, '\'', '\''},                                                  //
             {100, 260, '^', '^'},                                                   //
             {140, 260, '~', '~'},                                                   //
                                                                                     //
};                                                                                   //
int networks = 0;                                                                    //
String ssidList[20];                                                                 //
String selectedSSID = "";                                                            //
String inputBufer = "Zopa"; // Промежуточная переменная ввода пароля                 //
String password = "";       // Переменная для рароля                                 //
bool passwordOk = false;    // Подтверждение ввода пароля                            //
bool shiftstate = false;    // Переключение между регистрами                         //
uint16_t tX = -1;                                                                    //
uint16_t tY = -1;                                                                    //
void getTouchXY(uint16_t& x, uint16_t& y) //функция согласовующая несоответствие реальных координат нажатия с програмными
{                                                                                    //
                                                                                     //
   uint16_t x_lib = gl_touch.read_touch1_x();                                        //
   uint16_t y_lib = gl_touch.read_touch1_y();                                        //
                                                                                     //
   x = (480 - y_lib);                                                                //
   y = x_lib;                                                                        //
}                                                                                    //
                                                                                     //
                                                                                     //
  void drawKeyboard();                                                               //
 // void handleTouchKeyBoard(uint16_t tX, tY, shiftstate, passwordOk);              //
 void handleTouchKeyBoard(uint16_t &tX, uint16_t &tY, bool &shiftState, bool &passwordOk);
                                                                                     //
  void connectWiFi()                                                                 //
  {                                                                                  //
     tft.fillScreen(TFT_BLACK);                                                      //
     tft.setCursor(7, 10);                                                           //
     tft.println("Enter password:");                                                 //
     tft.println(selectedSSID);                                                      //
                                                                                     //
     while(password == "" && passwordOk == false)                                    //
     {                                                                               //
       if(gl_touch.read_td_status() == 1)                                            //
       {                                                                             //
         getTouchXY(tX, tY);                                                         //
         delay(100);       // антидребезг                                            //
       }                                                                             //
                                                                                     //
        drawKeyboard();                                                              //
                                                                                     //
        handleTouchKeyBoard(tX, tY, shiftstate, passwordOk);                         //
       tX = -1;           //НЕ УБИРАТЬ!!!!!!!!!!!!!!                                 //
       tY = -1;           //НЕ УБИРАТЬ!!!!!!!!!!!!!!!!                               //
        sprite.createSprite(280, 25);                                                //
        sprite.fillSprite(TFT_RED);                                                  //
        sprite.setTextColor(TFT_WHITE);                                              //
        sprite.setTextFont(1);                                                       //
        sprite.setTextSize(2);                                                       //
        sprite.drawString(inputBufer, 0, 5);                                         //
        sprite.pushSprite(200, 7);                                                   //
                                                                                     //
      }                                                                              //
                                                                                     //
        /* if(passwordOk)                                                            //
     {                                                                               //
      password = inputBufer; // ввод пароля                                          //
     }else                                                                           //
     {                                                                               //
       WiFi disconected Enter your password                                          //
     }*/                                                                             //
                                                                                     //
     password = inputBufer; // ввод пароля пока тут потом в блоке if() выше.....     //
                                                                                     //
                                                                                     //
      //91891518                                                                     //
      WiFi.begin(selectedSSID.c_str(), password.c_str());                            //
      while(WiFi.status() != WL_CONNECTED)                                           //
      {                                                                              //
        delay(500);                                                                  //
        tft.print(".");                                                              //
      }                                                                              //
                                                                                     //
      tft.fillScreen(TFT_BLACK);                                                     //
      tft.setCursor(10, 10);                                                         //
      tft.setTextFont(1);                                                            //
      tft.setTextSize(2);                                                            //
      tft.println("WiFi connected!");                                                //
      tft.setCursor(220, 10);                                                        //
      tft.println(WiFi.localIP());                                                   //
                                                                                     //
                                                                                     //
  }                                                                                  //
  void checkTouch(uint16_t &tX, uint16_t &tY)                                        //
  {                                                                                  //
    if(gl_touch.read_td_status() == 1)                                               //
    {                                                                                //
      getTouchXY(tX, tY);                                                            //
     for(int i = 0; i < networks; i++)                                               //
     {                                                                               //
       int yStart = 40 + (i * 30);                                                   //
       int yEnd   = yStart + 30;                                                     //
       if(tY > yStart && tY < yEnd)                                                  //
      {                                                                              //
        selectedSSID = ssidList[i];                                                  //
        if(WiFi.status() != WL_CONNECTED)                                            //
        {                                                                            //
           connectWiFi();                                                            //
        }                                                                            //
      }                                                                              //
     }                                                                               //
    }else                                                                            //
    {                                                                                //
      tX = -1;                                                                       //
      tY = -1;                                                                       //
    }                                                                                //
    //tft.println(WiFi.localIP());                                                   //
  }                                                                                  //
                                                                                     //
  void drawWiFiList()  // Вывод списка сетей
  {
    tft.fillScreen(TFT_BLACK);

    tft.setTextSize(2);
    tft.setCursor(10, 10);
    tft.println("Select WiFi:");

    for(int i = 0; i < networks; i++)
    {
      tft.setCursor(20, 40 + (i * 30));
      tft.print(i + 1);
      tft.print(". ");
      tft.println(ssidList[i]);
    }

  }
                                                                                     //
  void drawKeyboard() // отрисовка клавиатуры
  {
     for(int i = 1; i < 8; i++)
    {
      tft.drawFastHLine(0, (i * 40), 480, TFT_WHITE);
    }

    for(int y = 1; y < 12; y++)
    { 
      if(y == 5 || y == 6 || y == 7)
      {
         tft.drawFastVLine((y * 40), 40, 240, TFT_WHITE);
      }
      if(y != 5 && y != 6 && y != 7)
      {
      tft.drawFastVLine((y * 40), 40, 280, TFT_WHITE );
      }
    }

    for(int i = 0; i < 64; i++)
    {
       tft.setTextFont(1);
       tft.setTextSize(2);
       char c = shiftstate ? key[i].upper : key[i].lower;
       tft.setTextDatum(MC_DATUM);
       tft.drawString(String(c), key[i].x, key[i].y);
    }
    
       tft.setTextFont(1);
       tft.setTextSize(2);
       // клавиша SPACE//
       tft.drawString("SPACE", 240, 300);
       // клавиша SHIFT //
       tft.drawString("Sh", 20, 300);
       // клавиша BKSPS
       tft.drawString("Bkp", 420, 300);
       // клавиша EXIT
       tft.drawString("Ext", 460, 300);
       // клавиша OK
       tft.drawString("Ok", 60, 300);
  }
                                                                                     //
  void scanWiFi()
  {
    tft.fillScreen(TFT_BLACK);
    tft.setTextSize(2);
    tft.setCursor(10, 10);
    tft.println("Scaning WiFi...");

    networks = WiFi.scanNetworks();

    for(int i = 0; i < networks; i++)
    {
      ssidList[i] = WiFi.SSID(i); 
    }
     drawWiFiList();
  }
                                                                                     //
  void addChar(char c) // добавление символа
  {
    if(inputBufer.length() < 64)
    {
      inputBufer += c;
    }
  }
                                                                                     //
   void removeChar()  // удаление символа
  {
    if(inputBufer.length() > 0)
     {
        inputBufer.remove(inputBufer.length() - 1);
     }
  }
                                                                                     //
void handleTouchKeyBoard(uint16_t &tX, uint16_t &tY, bool &shiftState, bool &passwordOk)
{
  for(int i = 0; i < 64; i++)
 {
  if(tX > (key[i].x - 20) && tX < (key[i].x + 20) && tY > (key[i].y - 20) && tY < (key[i].y + 20))
  {
    char c = shiftstate ? key[i].upper : key[i].lower;
    inputBufer += c;
  }

 }

  if(tX > 0 && tX < 40 && tY > 280 && tY < 320)
    {
      shiftState = !shiftstate;
    }else if(tX > 40 && tX < 80 && tY > 280 && tY < 320)
    {
      passwordOk = true;
    }else if(tX > 400 && tX < 440 && tY > 280 && tY < 320)
    {
      removeChar();
    }else if(tX > 160 && tX < 320 && tY > 280 && tY < 320)
    {
      addChar(' ');
    }

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struc_radioPaket paket; // структура в которую заходят данные с радиомодуля
RadioData radiodata (radio, paket);

String forecastRequest =  "https://api.openweathermap.org/data/2.5/forecast?lat=50.4333&lon=30.6167&appid=f2af430fc3518278afe78c607fbf2623&units=metric";
String timeDataRequest1 = "time.ntp.org.ua";
String timeDataRequest2 = "pool.ntp.org.ua";
String currencyRequest  = "https://bank.gov.ua/NBUStatService/v1/statdirectory/exchangenew?&jsonvalcode=EUR&date=20260403";

TouchState structtouch;
PageManager manager;
InternetForecast forecastResponse(forecastRequest);
InternetCurrency currency(currencyRequest);
InternetTimeData timedata(timeDataRequest1, timeDataRequest2, rtc);
DataResiver dataresiver(forecastResponse, currency);   // InternetClient должен быть создан раньше чем DataResiver


MainPage mainpage(tft, paket, radiodata, manager);
ForecastPage forecastpage(tft, dataresiver);
SettingPage settingpage(tft);
CurrencyPage currencypage(tft, dataresiver);



String globResponseBank = " ";             
String globResponseBank;

void setup() 
{ 
  //esp_task_wdt_init(5, true);  // Инициализация WatchDog
  //esp_task_wdt_add(NULL);      // Следим за Loop
  wifi.begin();
  Wire.begin(21, 22);
  Serial.begin(9600);
  gl_touch.begin();
  if(!rtc.begin())
  {
    Serial.println("RTC not found");
  }else
  {
    Serial.println("RTC RUNED!");
  }
 
  tft.init();
  tft.setRotation(3); // левый верхний угол - 0 координат(x- вправо , y - вниз). контакты дисплея слева 
  tft.fillScreen(TFT_DARKGREY);
  
  
  radio.begin();
  radio.setAutoAck(1);
  radio.setRetries(0,15);
  radio.enableAckPayload();
  radio.setPayloadSize(32);
  radio.openReadingPipe(1, address[0]);
  radio.setChannel(0x60);
  radio.setPALevel(RF24_PA_LOW);
  radio.setDataRate(RF24_250KBPS);
  radio.powerUp();
  radio.startListening();

  
  manager.setPage(&mainpage);
  
  
}  
int serialiter = 0;
void loop() 
{   
  
       
       wifi.update();
       if(wifi.isConnected())
       {
         mainpage.lastWiFi = true;
         timedata.sinhroTimeData();  // Синхронизация должна делаться единожды!!!!!!!!!!
        if(serialiter == 40)
        {
        Serial.println(currency.responseBank); // отладка закоментить после отладки
        dataresiver.parseCurrencyFromJsonDoc(currency.getDocBank(), dataresiver.currencyarray);
        } 

         currency.updateCurrency();        // Запрос на сервер !!!!!! НАДО ДЕЛАТЬ ЕДИНОЖДЫ!!!!!!
         forecastResponse.updateForecast();//Запрос на сервер!!!!!! НАДО СДЕЛАТЬ ЧТОБЫ ЗАПРОС ДЕЛАЛСЯ ЕДИНОЖДЫ!!!!!!!!

         if ((forecastResponse.doc["cod"] == "200") && dataresiver.iteracia < 39)
          {
            dataresiver.parseForecastFromJsonDoc(forecastResponse.getDoc(), dataresiver.forecastarray);
          }
       } else
       {
         mainpage.lastWiFi = false;
         Serial.println("WiFi disconnected!!!");
       }

      
      if(gl_touch.read_td_status() == 1) 
      {
       getTouchXY(tX, tY);
       structtouch.pressed = true;
       structtouch.x = tX;
       structtouch.y = tY;
       Serial.println("Координаты X в касании :"); Serial.println(tX);
       Serial.println("Координаты У в касании :"); Serial.println(tY);
      }else
      {
        tX = 0;
        tY = 0;
        structtouch.x = tX;
        structtouch.y = tY;
        structtouch.pressed = false;
      }

      
       manager.update();
    

      if(millis() - timedata.lastRead >= 1000)             // Время Дата
      {
        timedata.lastRead = millis();                      // Время Дата
        DateTime now = rtc.now();                          // Время Дата
         
        if(mainpage.dayOfWeek != now.dayOfTheWeek())
        {
           mainpage.dayOfWeek = now.dayOfTheWeek();        // день недели
        }
        

        if(now.minute() != timedata.lastMinute)            // Время Дата
        {
          timedata.lastMinute = now.minute();             
          mainpage.minutes = now.minute();                 // Время дата
          mainpage.hours =  now.hour();
        }
      }

       // Serial.println(String(millis()));
       //esp_task_wdt_reset(); // WatchDog
       
      serialiter++;  
      
      
} 

