#pragma once
#include "Page.h"
#include "PageManager.h"
#include <stdint.h>
#include <TFT_eSPI.h>
#include "Button.h"
#include "FT6336U.h"

class PageManager;
extern FT6336U gl_touch;

class ForecastPage : public Page
{
   private:
   TFT_eSPI& tft;
   Button btn_exit;

   public:
   
   ForecastPage(TFT_eSPI& _tft) : tft(_tft), btn_exit(0, 0, 239, 39)
   {

   }
   void drawVLine(int32_t x0, int32_t y0, int32_t visota, int32_t color, int repit);
   void drawHLine(int32_t x0, int32_t y0, int32_t chirina, int32_t color, int repit);
   void drawStatic() override;
   void updateDinamic() override;
};