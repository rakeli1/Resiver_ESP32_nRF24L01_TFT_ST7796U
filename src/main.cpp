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
#define CE_PIN  26
#define CSN_PIN 27


RF24 radio(CE_PIN,CSN_PIN);
byte address[][6] = {"1Node", "2Node", "3Node", "4Node", "5Node", "6Node"}; 

TFT_eSPI tft = TFT_eSPI();

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
MainPage mainpage(tft, paket, radiodata, manager);
ForecastPage forecastpage(tft);
SettingPage settingpage(tft);
CurrencyPage currencypage(tft);


WiFiManager wifi("TP-Link_C810","91891518");

void setup() 
{ 
  esp_task_wdt_init(5, true);  // Инициализация WatchDog
  esp_task_wdt_add(NULL);      // Следим за Loop
  wifi.begin();
  Wire.begin(21, 22);
  Serial.begin(9600);
  gl_touch.begin();
 
  tft.init();
  tft.setRotation(3); // левый верхний угол - 0 координат(x- вправо , y - вниз). контакты дисплея слева 
  tft.fillScreen(TFT_DARKGREY);
  //mainPage.drawStatic();
  //foreCast.drawStatic();
  
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
  //settingpage.drawStatic();
}  

void loop() 
{      
       wifi.update();
       if(wifi.isConnected())
       {
         //Serial.println(WiFi.localIP());
         // тут можно запускать InternetClient
       }
    
       getTouchXY(tX, tY);
       structtouch.pressed = true;
       structtouch.x = tX;
       structtouch.y = tY;
      
       manager.update();
    
       esp_task_wdt_reset(); // WatchDog
    
} 

