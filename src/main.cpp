#include <Arduino.h>
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include <TFT_eSPI.h>


TFT_eSPI tft = TFT_eSPI(); 

void drawVline(int32_t x0, int32_t y0, int32_t visota, int32_t color, int repit)
{
  int rep = 0;
  int32_t dubX = x0;
  while(rep < repit)
 {
  tft.drawFastVLine(dubX, y0, visota, color);
  dubX++;
  rep++;
 }
}

void setup() 
{
  tft.init();
  tft.setRotation(3);
  tft.fillScreen(TFT_DARKGREY);
}

void loop()
{
  drawVline(240, 0, 320, TFT_BLACK, 2);
} 

