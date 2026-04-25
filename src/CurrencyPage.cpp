#include "CurrencyPage.h"
#include "MainPage.h"
#include "TFT_eSPI.h"

extern TouchState structtouch;

CurrencyPage::CurrencyPage(TFT_eSPI& tft, DataResiver& _dataresiver) : tft(tft),
 dataresiver(_dataresiver), btn_exit_CurrencyPage(160, 280, 160, 40, TFT_DARKGREY, true, true)
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

void CurrencyPage::upDateAllcellcarrency(DataResiver& dataresiver)
{
   for(int i = 0; i < 45; i++)
   {
      switch(dataresiver.currencyarray[i].currenciid)
      {
        case USD : usd.cellcurrency_rate = dataresiver.currencyarray[i].rate; break;
        case CAD : cad.cellcurrency_rate = dataresiver.currencyarray[i].rate; break;
        case GBP : gbp.cellcurrency_rate = dataresiver.currencyarray[i].rate; break;
        case AUD : aud.cellcurrency_rate = dataresiver.currencyarray[i].rate; break;
        case NZD : nzd.cellcurrency_rate = dataresiver.currencyarray[i].rate; break;
        case EUR : eur.cellcurrency_rate = dataresiver.currencyarray[i].rate; break;
        case CHF : chf.cellcurrency_rate = dataresiver.currencyarray[i].rate; break;
        case JPY : jpy.cellcurrency_rate = dataresiver.currencyarray[i].rate; break;
        case SGD : sgd.cellcurrency_rate = dataresiver.currencyarray[i].rate; break;
        case HKD : hkd.cellcurrency_rate = dataresiver.currencyarray[i].rate; break;
        case SEK : sek.cellcurrency_rate = dataresiver.currencyarray[i].rate; break;
        case SAR_ : sar_.cellcurrency_rate = dataresiver.currencyarray[i].rate; break;
        case TRY : try_.cellcurrency_rate = dataresiver.currencyarray[i].rate; break;
        case NOK : nok.cellcurrency_rate = dataresiver.currencyarray[i].rate; break;
        case MDL : mdl.cellcurrency_rate = dataresiver.currencyarray[i].rate; break;
        case MXN : mxn.cellcurrency_rate = dataresiver.currencyarray[i].rate; break;
        case ILS : ils.cellcurrency_rate = dataresiver.currencyarray[i].rate; break;
        case XAG : xag.cellcurrency_rate = dataresiver.currencyarray[i].rate; break;
        case XPT : xpt.cellcurrency_rate = dataresiver.currencyarray[i].rate; break;
        case XPD : xpd.cellcurrency_rate = dataresiver.currencyarray[i].rate; break;
        case XAU : xau.cellcurrency_rate = dataresiver.currencyarray[i].rate; break;
        case CURRENCYZERO : break;
      }
   }
}

void CurrencyPage::CellCurrency::cellCurrencyDraw(TFT_eSPI& tft)
{
   switch(idCurrency)
   {  
      case CAD : tft.setTextDatum(MC_DATUM);
                 tft.setTextColor(TFT_BLACK);
                 tft.drawString(String(cellcurrency_rate), 120, 63, 4);
      break;

      case USD : tft.setTextDatum(MC_DATUM);
                 tft.setTextColor(TFT_BLACK);
                 tft.drawString(String(cellcurrency_rate), 120, 23, 4);
      break;

      case GBP : tft.setTextDatum(MC_DATUM);
                 tft.setTextColor(TFT_BLACK);
                 tft.drawString(String(cellcurrency_rate), 120, 103, 4);
      break;

      case AUD : tft.setTextDatum(MC_DATUM);
                 tft.setTextColor(TFT_BLACK);
                 tft.drawString(String(cellcurrency_rate), 120, 143, 4);
      break;

      case NZD : tft.setTextDatum(MC_DATUM);
                 tft.setTextColor(TFT_BLACK);
                 tft.drawString(String(cellcurrency_rate), 120, 183, 4);
      break;

      case EUR : tft.setTextDatum(MC_DATUM);
                 tft.setTextColor(TFT_BLACK);
                 tft.drawString(String(cellcurrency_rate), 120, 223, 4);
      break;

      case CHF : tft.setTextDatum(MC_DATUM);
                 tft.setTextColor(TFT_BLACK);
                 tft.drawString(String(cellcurrency_rate), 120, 263, 4);
      break;

      case JPY : tft.setTextDatum(MC_DATUM);
                 tft.setTextColor(TFT_BLACK);
                 tft.drawString(String(cellcurrency_rate), 120, 303, 4);
      break;

      case SGD : tft.setTextDatum(MC_DATUM);
                 tft.setTextColor(TFT_BLACK);
                 tft.drawString(String(cellcurrency_rate), 280, 103, 4);
      break;

      case HKD : tft.setTextDatum(MC_DATUM);
                 tft.setTextColor(TFT_BLACK);
                 tft.drawString(String(cellcurrency_rate), 280, 143, 4);
      break;

      case SEK : tft.setTextDatum(MC_DATUM);
                 tft.setTextColor(TFT_BLACK);
                 tft.drawString(String(cellcurrency_rate), 280, 183, 4);
      break;

      case SAR_ : tft.setTextDatum(MC_DATUM);
                 tft.setTextColor(TFT_BLACK);
                 tft.drawString(String(cellcurrency_rate), 280, 223, 4);
      break;

      case TRY : tft.setTextDatum(MC_DATUM);
                 tft.setTextColor(TFT_BLACK);
                 tft.drawString(String(cellcurrency_rate), 280, 263, 4);
      break;

      case NOK : tft.setTextDatum(MC_DATUM);
                 tft.setTextColor(TFT_BLACK);
                 tft.drawString(String(cellcurrency_rate), 440, 23, 4);
      break;

      case MDL : tft.setTextDatum(MC_DATUM);
                 tft.setTextColor(TFT_BLACK);
                 tft.drawString(String(cellcurrency_rate), 440, 63, 4);
      break;

      case MXN : tft.setTextDatum(MC_DATUM);
                 tft.setTextColor(TFT_BLACK);
                 tft.drawString(String(cellcurrency_rate), 440, 103, 4);
      break;

      case ILS : tft.setTextDatum(MC_DATUM);
                 tft.setTextColor(TFT_BLACK);
                 tft.drawString(String(cellcurrency_rate), 440, 143, 4);
      break;

      case XAG : tft.setTextDatum(MC_DATUM);
                 tft.setTextColor(TFT_BLACK);
                 tft.drawString(String(cellcurrency_rate), 440, 183, 4);
      break;

      case XPT : tft.setTextDatum(MC_DATUM);
                 tft.setTextColor(TFT_BLACK);
                 tft.drawString(String(cellcurrency_rate), 440, 223, 4);
      break;

      case XPD : tft.setTextDatum(MC_DATUM);
                 tft.setTextColor(TFT_BLACK);
                 tft.drawString(String(cellcurrency_rate), 440, 263, 4);
      break;

      case XAU : tft.setTextDatum(MC_DATUM);
                 tft.setTextColor(TFT_BLACK);
                 tft.drawString(String(cellcurrency_rate), 440, 303, 4);
      break;

      case CURRENCYZERO : break;

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
   upDateAllcellcarrency(dataresiver);
   usd.cellCurrencyDraw(tft);
   cad.cellCurrencyDraw(tft);
   gbp.cellCurrencyDraw(tft);
   aud.cellCurrencyDraw(tft);
   nzd.cellCurrencyDraw(tft);
   eur.cellCurrencyDraw(tft);
   chf.cellCurrencyDraw(tft);
   jpy.cellCurrencyDraw(tft);
   sgd.cellCurrencyDraw(tft);
   hkd.cellCurrencyDraw(tft);
   sek.cellCurrencyDraw(tft);
   sar_.cellCurrencyDraw(tft);
   try_.cellCurrencyDraw(tft);
   nok.cellCurrencyDraw(tft);
   mdl.cellCurrencyDraw(tft);
   mxn.cellCurrencyDraw(tft);
   ils.cellCurrencyDraw(tft);
   xag.cellCurrencyDraw(tft);
   xpt.cellCurrencyDraw(tft);
   xpd.cellCurrencyDraw(tft);
   xau.cellCurrencyDraw(tft);
}


void CurrencyPage::updateDinamic()
{
  if(btn_exit_CurrencyPage.isTouched())
  {
    manager.setPage(&mainpage);
    structtouch.pressed = false;
    //structtouch.x = -1;
    //structtouch.y = -1;

  }
}