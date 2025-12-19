#include "ForecastPage.h"


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
  drawHLine(0, 40, 480, TFT_WHITE, 3);
  drawHLine(0, 109, 480, TFT_WHITE, 3);
  drawHLine(0, 179, 480, TFT_WHITE, 3);
  drawHLine(0, 249, 480, TFT_WHITE, 3);

  drawVLine(119, 0, 320, TFT_WHITE, 3);
  drawVLine(239, 0, 320, TFT_WHITE, 3);
  drawVLine(359, 0, 320, TFT_WHITE, 3);
}

void ForecastPage::updateDinamic()
{
    
}