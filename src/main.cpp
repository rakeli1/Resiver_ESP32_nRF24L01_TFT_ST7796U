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
#include "InternetClient.h"
#include "DataResiver.h"

#define CE_PIN  26
#define CSN_PIN 27


RF24 radio(CE_PIN,CSN_PIN);
byte address[][6] = {"1Node", "2Node", "3Node", "4Node", "5Node", "6Node"}; 

TFT_eSPI tft = TFT_eSPI();
WiFiManager wifi("TP-Link_C810","91891518");
FT6336U gl_touch(5, 34);
uint16_t tX = -1;
uint16_t tY = -1;



void getTouchXY(uint16_t& x, uint16_t& y) //функция согласлвующая несоответствие реальных координат нажатия с програмными
{
  
   uint16_t x_lib = gl_touch.read_touch1_x();
   uint16_t y_lib = gl_touch.read_touch1_y();

   x = (480 - y_lib);
   y = x_lib;
}


struc_radioPaket paket; // структура в которую заходят данные с радиомодуля
RadioData radiodata (radio, paket);

TouchState structtouch;
PageManager manager;
InternetClient forecastResponse("https://api.openweathermap.org/data/2.5/forecast?lat=50.4333&lon=30.6167&appid=f2af430fc3518278afe78c607fbf2623&units=metric");
DataResiver dataresiver(forecastResponse);   // InternetClient должен быть создан раньше чем DataResiver

MainPage mainpage(tft, paket, radiodata, manager);
ForecastPage forecastpage(tft, dataresiver);
SettingPage settingpage(tft);
CurrencyPage currencypage(tft);



              
String globResponse;

void setup() 
{ 
  //esp_task_wdt_init(5, true);  // Инициализация WatchDog
  //esp_task_wdt_add(NULL);      // Следим за Loop
  wifi.begin();
  Wire.begin(21, 22);
  Serial.begin(9600);
  gl_touch.begin();
 
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
         //Serial.println(WiFi.localIP());
         // тут можно запускать InternetClien
         forecastResponse.update();//Запрос на сервер!!!!!! НАДО СДЕЛАТЬ ЧТОБЫ ЗАПРОС ДЕЛАЛСЯ ЕДИНОЖДЫ!!!!!!!!
         if ((forecastResponse.doc["cod"] == "200") && dataresiver.iteracia < 39)
          {
         //globResponse = forecastResponse.response;
         //Serial.println(globResponse);
           dataresiver.parseForecastFromJsonDoc(forecastResponse.getDoc(), dataresiver.forecastarray);
          
          }
         
         
         //Serial.println(globResponse);

       } else
       {
         mainpage.lastWiFi = false;
         Serial.println("WiFi disconnected!!!");
       }
    
       getTouchXY(tX, tY);
       structtouch.pressed = true;
       structtouch.x = tX;
       structtouch.y = tY;
      
       manager.update();
      if(dataresiver.iteracia == 39 && serialiter < 46)
      {  
       for(int iter = 0; iter < 46; iter++)
       { 
         Serial.print("serialiter = ");
         Serial.println(serialiter);
         Serial.println(dataresiver.forecastarray[iter].temperature);
         Serial.println(dataresiver.forecastarray[iter].day);
         Serial.println(dataresiver.forecastarray[iter].hour);
         Serial.println(dataresiver.forecastarray[iter].parthdayID); 
         Serial.println(dataresiver.forecastarray[iter].weathertype);
         Serial.println("======================================");
         serialiter++;
         delay(1000);
       }
      }

        
       //esp_task_wdt_reset(); // WatchDog
    
} 

