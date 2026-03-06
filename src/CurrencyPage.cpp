#include "CurrencyPage.h"
#include "MainPage.h"

extern TouchState structtouch;

CurrencyPage::CurrencyPage(TFT_eSPI& tft) : tft(tft), btn_exit_CurrencyPage(160, 280, 160, 40)
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
   drawcarr_HLine(200, 280, 80, TFT_WHITE, 3);
   drawcarr_VLine(160, 280, 40, TFT_WHITE, 3);
   drawcarr_VLine(320, 280, 40, TFT_WHITE, 3);

   drawcarr_VLine(160, 0, 320, TFT_WHITE, 3);
   drawcarr_VLine(320, 0, 320, TFT_WHITE, 3);

   drawcarr_HLine(0, 40, 160, TFT_WHITE, 3);
   drawcarr_HLine(320, 40, 160, TFT_WHITE, 3);
   drawcarr_HLine(0, 80, 480, TFT_WHITE, 3);
   drawcarr_HLine(0, 120, 480, TFT_WHITE, 3);
   drawcarr_HLine(0, 160, 480, TFT_WHITE, 3);
   drawcarr_HLine(0, 200, 480, TFT_WHITE, 3);
   drawcarr_HLine(0, 240, 480, TFT_WHITE, 3);
   drawcarr_HLine(0, 280, 480, TFT_WHITE, 3);

   tft.setTextDatum(MC_DATUM);
   tft.setTextColor(TFT_BLACK);
   tft.setTextFont(4);
   tft.drawString("USD/", 40, 23);
   tft.drawString("CAD/", 40, 65);
   tft.drawString("GBP/", 40, 105);
   tft.drawString("AUD/", 40, 145);
   tft.drawString("NZD/", 40, 185);
   tft.drawString("EUR/", 40, 225);
   tft.drawString("CHF/", 40, 265);
   tft.drawString("JPY/", 40, 305); 
   tft.drawString("SGD/", 200, 105);
   tft.drawString("HKD/", 200, 145);
   tft.drawString("SEK/", 200, 185);
   tft.drawString("SAR/", 200, 225);
   tft.drawString("TRY/", 200, 265);
   tft.drawString("NOK/", 360, 23);
   tft.drawString("MDL/", 360, 65);
   tft.drawString("MXN/", 360, 105);
   tft.drawString("ILS/", 360, 145);
   tft.drawString("XAG/", 360, 185);
   tft.drawString("XPT/", 360, 225);
   tft.drawString("XPD/", 360, 265);
   tft.drawString("XAU/", 360, 305);

   tft.fillRect(163, 283, 157, 37, TFT_RED);
   tft.drawString("EXIT", 240, 305);
}

void CurrencyPage::updateDinamic()
{
  if(btn_exit_CurrencyPage.isTouched())
  {
    manager.setPage(&mainpage);
    structtouch.pressed = false;
  }
}