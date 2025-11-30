#include <Arduino.h>
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include <TFT_eSPI.h>
#include "DataReciver.h"

RF24 radio(2,4);
DataReciver datareciver(radio); // обьект посредник между радиопередатчиком и страницами использующими данные с передатчика
TFT_eSPI tft = TFT_eSPI(); 

enum DataNRF
{
   TEMPERATURE,
   HUMIDITY,
   PRESSURE,
   BATLEV
};

void drawVline(int32_t x0, int32_t y0, int32_t visota, int32_t color, int repit)
{
  for(int i = 0; i < repit; i++)
 {
  tft.drawFastVLine(x0 + i, y0, visota, color);
 }
}

void drawHLine(int32_t x0, int32_t y0, int32_t chirina, int32_t color, int repit)
{
  for(int i = 0; i < repit; i++)
 {
  tft.drawFastHLine(x0, y0 + 1, chirina, color);
 }
}

void setup() 
{
  tft.init();
  tft.setRotation(3); // левый верхний угол - 0 координат(x- вправо , y - вниз). контакты дисплея слева 
  tft.fillScreen(TFT_DARKGREY);
}

void loop() 
{
  drawVline(160, 0, 320, TFT_WHITE, 2);
  drawVline(320, 220, 100, TFT_WHITE, 2);
  drawVline(320, 70, 250, TFT_WHITE, 2);
  drawHLine(0, 220, 480, TFT_WHITE, 2);
  drawHLine(0, 70, 480, TFT_WHITE, 2);
  drawHLine(0, 145, 160, TFT_WHITE, 2);
  
  tft.fillRect(0, 0, 20, 20, TFT_DARKGREEN);  // ориентир setRotation()
  tft.drawRect(170, 5, 40, 13, TFT_WHITE ); // индикатор батареи
  tft.fillCircle(240, 125, 20, TFT_YELLOW);

  

 
} 

