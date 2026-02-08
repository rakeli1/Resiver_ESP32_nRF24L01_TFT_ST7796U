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
   public:

   struct Cell
   {  
      int cell_data;
      float cell_temp;
      //int cell_hour;
      ParthDayID Cell_Id;
      WeatherType cell_Weathertype;
      bool cell_special;
      bool cell_valid;

      void cellDraw();
       

      
   };

   private:
   TFT_eSPI& tft;
   Button btn_exit; 
 
  

   public:

   Cell cellData1 {0, 0.0f, DATA1, WEATHER_UNKNOWN, true, false};    
   Cell cellData2 {0, 0.0f, DATA2, WEATHER_UNKNOWN, true, false};    
   Cell cellData3 {0, 0.0f, DATA3, WEATHER_UNKNOWN, true, false};    
   Cell cellData4 {0, 0.0f, DATA4, WEATHER_UNKNOWN, true, false};    
   Cell cellData5 {0, 0.0f, DATA5, WEATHER_UNKNOWN, true, false};    
   Cell cellData6 {0, 0.0f, DATA6, WEATHER_UNKNOWN, true, false};     
   Cell cellNight1 {0, 0.0f, NIGHT1, WEATHER_UNKNOWN, false, false};
   Cell cellNight2 {0, 0.0f, NIGHT2, WEATHER_UNKNOWN, false, false};
   Cell cellNight3 {0, 0.0f, NIGHT3, WEATHER_UNKNOWN, false, false};
   Cell cellNight4 {0, 0.0f, NIGHT4, WEATHER_UNKNOWN, false, false};
   Cell cellNight5 {0, 0.0f, NIGHT5, WEATHER_UNKNOWN, false, false};
   Cell cellNight6 {0, 0.0f, NIGHT6, WEATHER_UNKNOWN, false, false};
   Cell cellMorning1 {0, 0.0f, MORNING1, WEATHER_UNKNOWN, false, false};
   Cell cellMorning2 {0, 0.0f, MORNING2, WEATHER_UNKNOWN, false, false};
   Cell cellMorning3 {0, 0.0f, MORNING3, WEATHER_UNKNOWN, false, false};
   Cell cellMorning4 {0, 0.0f, MORNING4, WEATHER_UNKNOWN, false, false};
   Cell cellMorning5 {0, 0.0f, MORNING5, WEATHER_UNKNOWN, false, false};
   Cell cellMorning6 {0, 0.0f, MORNING6, WEATHER_UNKNOWN, false, false};
   Cell cellDay1 {0, 0.0f, DAY1, WEATHER_UNKNOWN, false, false};
   Cell cellDay2 {0, 0.0f, DAY2, WEATHER_UNKNOWN, false, false};
   Cell cellDay3 {0, 0.0f, DAY3, WEATHER_UNKNOWN, false, false};
   Cell cellDay4 {0, 0.0f, DAY4, WEATHER_UNKNOWN, false, false};
   Cell cellDay5 {0, 0.0f, DAY5, WEATHER_UNKNOWN, false, false};
   Cell cellDay6 {0, 0.0f, DAY6, WEATHER_UNKNOWN, false, false};
   Cell cellEvening1 {0, 0.0f, EVENING1, WEATHER_UNKNOWN, false, false};
   Cell cellEvening2 {0, 0.0f, EVENING2, WEATHER_UNKNOWN, false, false};
   Cell cellEvening3 {0, 0.0f, EVENING3, WEATHER_UNKNOWN, false, false};
   Cell cellEvening4 {0, 0.0f, EVENING4, WEATHER_UNKNOWN, false, false} ;
   Cell cellEvening5 {0, 0.0f, EVENING5, WEATHER_UNKNOWN, false, false};
   Cell cellEvening6 {0, 0.0f, EVENING6, WEATHER_UNKNOWN, false,  false};
   
   ForecastPage(TFT_eSPI& _tft) : tft(_tft), btn_exit(0, 0, 239, 39)
   {

   }
   void drawVLine(int32_t x0, int32_t y0, int32_t visota, int32_t color, int repit);
   void drawHLine(int32_t x0, int32_t y0, int32_t chirina, int32_t color, int repit);
   void drawStatic() override;
   void updateDinamic() override;
};