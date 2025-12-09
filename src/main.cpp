#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include "MainPage.h"
#include "RadioData.h"
#define CE_PIN  2
#define CSN_PIN 4

RF24 radio(CE_PIN,CSN_PIN);
//DataReciver datareciver(radio); // обьект посредник между радиопередатчиком и страницами использующими данные с передатчика
TFT_eSPI tft = TFT_eSPI(); 
radioPaket paket; // структура в которую заходят данные с радиомодуля

MainPage mainPage(tft, paket);





void setup() 
{
  tft.init();
  tft.setRotation(3); // левый верхний угол - 0 координат(x- вправо , y - вниз). контакты дисплея слева 
  tft.fillScreen(TFT_DARKGREY);
  mainPage.draw();
}

void loop() 
{
  
} 

