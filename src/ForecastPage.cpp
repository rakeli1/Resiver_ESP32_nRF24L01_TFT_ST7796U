#include "ForecastPage.h"
#include "MainPage.h"

extern PageManager manager;
extern MainPage mainpage;
extern TouchState structtouch;

void ForecastPage::drawVLine(int32_t x0, int32_t y0, int32_t visota, int32_t color, int repit)
{
  for(int i = 0; i < repit; i++)
 {
  tft.drawFastVLine(x0 + i, y0, visota, color);
 }
}

void ForecastPage::drawHLine(int32_t x0, int32_t y0, int32_t chirina, int32_t color, int repit)
{
  for(int i = 0; i < repit; i++)
 {
  tft.drawFastHLine(x0, y0 + i, chirina, color);
 }
}

void ForecastPage::drawStatic()
{
  tft.fillScreen(TFT_DARKGREY);
  tft.fillRect(0, 0, 239, 39, TFT_RED);

  drawHLine(0, 39, 480, TFT_WHITE, 3);
  drawHLine(0, 79, 480, TFT_WHITE, 3); 
  drawHLine(0, 139, 480, TFT_WHITE, 3);
  drawHLine(0, 199, 480, TFT_WHITE, 3);
  drawHLine(0, 259, 480, TFT_WHITE, 3);

 
  tft.setTextDatum(MC_DATUM);
  tft.setTextColor(TFT_BLACK);
  tft.drawString("EXIT", 120, 20, 4);
  tft.drawString("UPDATE", 360, 20, 4);
  tft.drawString("Data", 60, 60, 4);
  tft.drawString("Night", 60, 110, 4);
  tft.drawString("Morning", 60, 170, 4);
  tft.drawString("Day", 60, 230, 4);
  tft.drawString("Evening", 60, 290, 4);
  

  drawVLine(119, 40, 280, TFT_WHITE, 3);
  drawVLine(191, 40, 280, TFT_WHITE, 3);
  drawVLine(263, 40, 280, TFT_WHITE, 3);
  drawVLine(335, 40, 280, TFT_WHITE, 3);
  drawVLine(407, 40, 280, TFT_WHITE, 3);
}

void ForecastPage::updateDinamic()
{
   if(btn_exit.isTouched())
   {  
      structtouch.pressed = false;
      manager.setPage(&mainpage);
   } 
}