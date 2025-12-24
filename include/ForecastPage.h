#pragma once
#include "Page.h"
#include "PageManager.h"
#include <stdint.h>
#include <TFT_eSPI.h>
#include "Button.h"

class PageManager;

class ForecastPage : public Page
{
   private:
   TFT_eSPI& tft;
   

   public:
   
   ForecastPage(TFT_eSPI& _tft) : tft(_tft)
   {

   }
   void drawVLine(int32_t x0, int32_t y0, int32_t visota, int32_t color, int repit);
   void drawHLine(int32_t x0, int32_t y0, int32_t chirina, int32_t color, int repit);
   void drawStatic() override;
   void updateDinamic() override;
};