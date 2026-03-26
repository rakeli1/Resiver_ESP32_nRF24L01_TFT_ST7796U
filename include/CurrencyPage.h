#pragma once
#include "Button.h"
#include "Page.h"
#include "TFT_eSPI.h"
#include "FT6336U.h"
#include "PageManager.h"
#include "FileServises.h"
#include "DataResiver.h"

class CurrencyPage : public Page
{
   private:
      TFT_eSPI&   tft;
      DataResiver& dataresiver;
      Button btn_exit_CurrencyPage;

   public:
       
       struct CellCurrency
     {  
      int cellcurrency_data;
      float cellcurrency_rate;
      CurrencyId idCurrency;
      void cellCurrencyDraw(TFT_eSPI& tft);
     }; 

     public:

     CellCurrency usd {0, 0.00, USD};
     CellCurrency cad {0, 0.00, CAD};
     CellCurrency gbp {0, 0.00, GBP};
     CellCurrency aud {0, 0.00, AUD};
     CellCurrency nzd {0, 0.00, NZD};
     CellCurrency eur {0, 0.00, EUR};
     CellCurrency chf {0, 0.00, CHF};
     CellCurrency jpy {0, 0.00, JPY};
     CellCurrency sgd {0, 0.00, SGD};
     CellCurrency hkd {0, 0.00, HKD};
     CellCurrency sek {0, 0.00, SEK};
     CellCurrency sar_ {0, 0.00, SAR_};
     CellCurrency try_ {0, 0.00, TRY};
     CellCurrency nok {0, 0.00, NOK};
     CellCurrency mdl {0, 0.00, MDL};
     CellCurrency mxn {0, 0.00, MXN};
     CellCurrency ils {0, 0.00, ILS};
     CellCurrency xag {0, 0.00, XAG};
     CellCurrency xpt {0, 0.00, XPT};
     CellCurrency xpd {0, 0.00, XPD};
     CellCurrency xau {0, 0.00, XAU};

     
     

       CurrencyPage(TFT_eSPI& tft, DataResiver& _dataresiver);
       void drawcarr_VLine(int32_t x0, int32_t y0, int32_t visota, int32_t color, int repit);
       void drawcarr_HLine(int32_t x0, int32_t y0, int32_t chirina, int32_t color, int repit);
       void upDateAllcellcarrency(DataResiver& dataresiver);

       void drawStatic() override;
       void updateDinamic() override; 

};