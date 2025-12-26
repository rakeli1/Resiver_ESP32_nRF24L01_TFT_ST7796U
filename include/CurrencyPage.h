#pragma once
#include "Button.h"
#include "Page.h"
#include "TFT_eSPI.h"
#include "FT6336U.h"
#include "PageManager.h"


class CurrencyPage : public Page
{
   private:
      TFT_eSPI&   tft;
      Button btn_exit_CurrencyPage;

   public:
       CurrencyPage(TFT_eSPI& tft);
       void drawcarr_VLine(int32_t x0, int32_t y0, int32_t visota, int32_t color, int repit);
       void drawcarr_HLine(int32_t x0, int32_t y0, int32_t chirina, int32_t color, int repit);

       void drawStatic() override;
       void updateDinamic() override; 

};