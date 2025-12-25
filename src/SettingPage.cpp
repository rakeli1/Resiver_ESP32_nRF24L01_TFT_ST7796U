#include "Page.h"
#include "SettingPage.h"
#include "PageManager.h"
#include "MainPage.h"

//extern MainPage mainpage;

SettingPage::SettingPage(TFT_eSPI&_tft) : tft(_tft), btn_exit(0, 240, 480, 80, gl_touch)
{

}                                                                







void SettingPage::set_drawVline(int32_t x0, int32_t y0, int32_t visota, int32_t color, int repit)
{
  for(int i = 0; i < repit; i++)
 {
  tft.drawFastVLine(x0 + i, y0, visota, color);
 }
}

void SettingPage::set_drawHLine(int32_t x0, int32_t y0, int32_t chirina, int32_t color, int repit)
{
  for(int i = 0; i < repit; i++)
 {
  tft.drawFastHLine(x0, y0 + i, chirina, color);
 }
}

void SettingPage::drawStatic() // virtual
{ 
   tft.fillScreen(TFT_DARKGREY);
   set_drawHLine(0, 79, 480, TFT_WHITE, 3);
   set_drawHLine(0, 159, 480, TFT_WHITE, 3);
   set_drawHLine(0, 239, 480, TFT_WHITE, 3);

   tft.setTextDatum(MC_DATUM);
   tft.setTextColor(TFT_BLACK);
   tft.setTextFont(4);
   tft.drawString("TIME & DATA", 240, 40);
   tft.drawString("LOCATION", 240, 120);
   tft.drawString("NETWORK", 240, 200);
   tft.drawString("EXIT", 240, 280);
   
}


void SettingPage::updateDinamic() // virtual
{
   if(btn_exit.isTouched())
   {
     manager.setPage(&mainpage);
   }
}