#include "CurrencyPage.h"
#include "MainPage.h"

extern FT6336U gl_touch;
extern PageManager manager;
extern MainPage mainpage;

CurrencyPage::CurrencyPage(TFT_eSPI& tft) : tft(tft), btn_exit_CurrencyPage(0, 240, 480, 80, gl_touch)
{

}

void CurrencyPage::drawcarr_HLine(int32_t x0, int32_t y0, int32_t chirina, int32_t color, int repit)
{
    for(int i = 0; i < repit; i++)
 {
  tft.drawFastHLine(x0, y0 + i, chirina, color);
 }
}

void CurrencyPage::drawcarr_VLine(int32_t x0, int32_t y0, int32_t visota, int32_t color, int repit)
{
   for(int i = 0; i < repit; i++)
 {
  tft.drawFastVLine(x0 + i, y0, visota, color);
 }
}

void CurrencyPage::drawStatic()
{  
    tft.fillScreen(TFT_DARKGREY);
   drawcarr_HLine(0, 240, 480, TFT_WHITE, 3);
   tft.setTextDatum(MC_DATUM);
   tft.setTextColor(TFT_BLACK);
   tft.setTextFont(4);
   tft.drawString("EXIT", 240, 280);
}

void CurrencyPage::updateDinamic()
{
  if(btn_exit_CurrencyPage.isTouched())
  {
    manager.setPage(&mainpage);

  }
}