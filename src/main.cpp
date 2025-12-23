#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include "MainPage.h"
#include "RadioData.h"
#include "ForecastPage.h"
#include "PageManager.h"
#include<Wire.h>
#include "FT6336U.h"
#define CE_PIN  26
#define CSN_PIN 27


RF24 radio(CE_PIN,CSN_PIN);
byte address[][6] = {"1Node", "2Node", "3Node", "4Node", "5Node", "6Node"}; 

TFT_eSPI tft = TFT_eSPI();

FT6336U gl_touch(5, 34);

int touchX = -1;
int touchY = -1;

void getTouchXY(int& x, int& y) //функция согласлвующая несоответствие реальных координат нажатия с програмными
{
  
   int x_lib = gl_touch.read_touch1_x();
   int y_lib = gl_touch.read_touch1_y();

   x = (480 - y_lib);
   y = x_lib;
}



RadioData radiodata (radio);
struc_radioPaket paket; // структура в которую заходят данные с радиомодуля
MainPage mainPage(tft, paket, radiodata);
ForecastPage foreCast(tft);
PageManager pagemanager;




void setup() 
{ 
  Wire.begin(21, 22);
  Serial.begin(9600);
  gl_touch.begin();
 
  tft.init();
  tft.setRotation(3); // левый верхний угол - 0 координат(x- вправо , y - вниз). контакты дисплея слева 
  tft.fillScreen(TFT_DARKGREY);
  mainPage.drawStatic();
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
}

void loop() 
{   
    //getTouchXY( touchX, touchY);
    if(gl_touch.read_touch1_event() == 2)
    {
      getTouchXY(touchX, touchY);
      Serial.print(" X = ");
      Serial.println(touchX);
      Serial.print(" Y = ");
      Serial.println(touchY);
    }
    //pagemanager.update();
    //mainPage.setTouch(touchX, touchY);
    mainPage.updateDinamic();
    //Serial.println(paket.temperature);
    //delay(1000);
    

    
} 

