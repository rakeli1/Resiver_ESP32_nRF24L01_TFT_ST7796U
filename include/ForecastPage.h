#pragma once
#include "Page.h"
#include "PageManager.h"
#include <stdint.h>
#include <TFT_eSPI.h>
#include "Button.h"
#include "FT6336U.h"
#include "DataResiver.h"

class PageManager;
extern FT6336U gl_touch;

class ForecastPage : public Page
{
   

   private:
   TFT_eSPI& tft;
   Button btn_exit; 
   DataResiver& dataresiver;

   public:

   struct Cell
   {  
      int cell_data;
      int cell_temp;
      ParthDayID cell_Id;
      WeatherType cell_Weathertype;

      String cellreturnWeather();
      void cellDraw(TFT_eSPI& tft);
   };
 
  

   public:

   Cell cellData1 {0, 0, PARTHZERO, WEATHER_UNKNOWN};    
   Cell cellData2 {0, 0, PARTHZERO, WEATHER_UNKNOWN};    
   Cell cellData3 {0, 0, PARTHZERO, WEATHER_UNKNOWN};    
   Cell cellData4 {0, 0, PARTHZERO, WEATHER_UNKNOWN};    
   Cell cellData5 {0, 0, PARTHZERO, WEATHER_UNKNOWN};    
   Cell cellData6 {0, 0, PARTHZERO, WEATHER_UNKNOWN};     
   Cell cellNight1 {0, 0, PARTHZERO, WEATHER_UNKNOWN};
   Cell cellNight2 {0, 0, PARTHZERO, WEATHER_UNKNOWN};
   Cell cellNight3 {0, 0, PARTHZERO, WEATHER_UNKNOWN};
   Cell cellNight4 {0, 0, PARTHZERO, WEATHER_UNKNOWN};
   Cell cellNight5 {0, 0, PARTHZERO, WEATHER_UNKNOWN};
   Cell cellNight6 {0, 0, PARTHZERO, WEATHER_UNKNOWN};
   Cell cellMorning1 {0, 0, PARTHZERO, WEATHER_UNKNOWN};
   Cell cellMorning2 {0, 0, PARTHZERO, WEATHER_UNKNOWN};
   Cell cellMorning3 {0, 0, PARTHZERO, WEATHER_UNKNOWN};
   Cell cellMorning4 {0, 0, PARTHZERO, WEATHER_UNKNOWN};
   Cell cellMorning5 {0, 0, PARTHZERO, WEATHER_UNKNOWN};
   Cell cellMorning6 {0, 0, PARTHZERO, WEATHER_UNKNOWN};
   Cell cellDay1 {0, 0, PARTHZERO, WEATHER_UNKNOWN};
   Cell cellDay2 {0, 0, PARTHZERO, WEATHER_UNKNOWN};
   Cell cellDay3 {0, 0, PARTHZERO, WEATHER_UNKNOWN};
   Cell cellDay4 {0, 0, PARTHZERO, WEATHER_UNKNOWN};
   Cell cellDay5 {0, 0, PARTHZERO, WEATHER_UNKNOWN};
   Cell cellDay6 {0, 0, PARTHZERO, WEATHER_UNKNOWN};    
   Cell cellEvening1 {0, 0, PARTHZERO, WEATHER_UNKNOWN};
   Cell cellEvening2 {0, 0, PARTHZERO, WEATHER_UNKNOWN};
   Cell cellEvening3 {0, 0, PARTHZERO, WEATHER_UNKNOWN};
   Cell cellEvening4 {0, 0, PARTHZERO, WEATHER_UNKNOWN};
   Cell cellEvening5 {0, 0, PARTHZERO, WEATHER_UNKNOWN};
   Cell cellEvening6 {0, 0, PARTHZERO, WEATHER_UNKNOWN};
   
   ForecastPage(TFT_eSPI& _tft, DataResiver& _dataresiver) : 
   tft(_tft), dataresiver(_dataresiver), btn_exit(0, 0, 239, 39, TFT_DARKGREY, true, true)
   {

   }
   void drawVLine(int32_t x0, int32_t y0, int32_t visota, int32_t color, int repit);
   void drawHLine(int32_t x0, int32_t y0, int32_t chirina, int32_t color, int repit);
   void updateAllCells(DataResiver& dataresiver);
   void drawStatic() override;
   void updateDinamic() override;
};