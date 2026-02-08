#include "ForecastPage.h"
#include "MainPage.h"

extern PageManager manager;
extern MainPage mainpage;
extern TouchState structtouch;

void ForecastPage::drawVLine(int32_t x0, int32_t y0, int32_t visota, int32_t color, int repit)
{
  for(int i = 0; i < repit; i++)
 {
  tft.drawFastVLine(x0 + i, y0, visota, color);
 }
}

void ForecastPage::drawHLine(int32_t x0, int32_t y0, int32_t chirina, int32_t color, int repit)
{
  for(int i = 0; i < repit; i++)
 {
  tft.drawFastHLine(x0, y0 + i, chirina, color);
 }
}

String ForecastPage::Cell::cellDrawWeather(TFT_eSPI& tft)
{
   switch(cell_Weathertype)
   {
     case CLEAR :        return "clear";  break;
     case CLOUDS :       return "cloud"; break;
     case RAIN :         return "rain";   break;
     case DRIZZLE :      return "driz";  break;
     case THUNDERSTORM : return "thund"; break;
     case SNOW :         return "snow"; break;
     case MIST :         return "mist"; break;
     case SMOKE :        return "smoke"; break;
     case HAZE :         return "haze"; break;
     case DUST :         return "dust"; break;
     case SAND :         return "sand"; break;
     case ASH :          return "ash";  break;
     case SQUALL :       return "squal"; break;
     case TORNADO :      return "torna"; break;
    }
}

void ForecastPage::Cell::cellDraw(TFT_eSPI& tft)
{
   switch (Cell_Id)
   {
    case DATA1 : tft.setTextDatum(MC_DATUM);
                 tft.drawString(String(cell_data), 128, 60, 4);
    break;

    case DATA2 : tft.setTextDatum(MC_DATUM);
                 tft.drawString(String(cell_data), 192, 60, 4);
    break;

    case DATA3 : tft.setTextDatum(MC_DATUM);
                 tft.drawString(String(cell_data), 256, 60, 4);
    break;

    case DATA4 : tft.setTextDatum(MC_DATUM);
                 tft.drawString(String(cell_data), 320, 60, 4);
    break;

    case DATA5 : tft.setTextDatum(MC_DATUM);
                 tft.drawString(String(cell_data), 384, 60, 4);
    break;

    case DATA6 : tft.setTextDatum(MC_DATUM);
                 tft.drawString(String(cell_data), 448, 60, 4);
    break;

    case NIGHT1 : tft.setTextDatum(MC_DATUM);
                  tft.drawString(String(cell_temp), 128, 95, 4);
                  tft.drawString(cellDrawWeather(tft), 128, 125, 4);
    break;

    case NIGHT2 : tft.setTextDatum(MC_DATUM);
                  tft.drawString(String(cell_temp), 192, 95, 4);
                  tft.drawString(cellDrawWeather(tft), 192, 125, 4);
    break;

    case NIGHT3 : tft.setTextDatum(MC_DATUM);
                  tft.drawString(String(cell_temp), 256, 95, 4);
                  tft.drawString(cellDrawWeather(tft), 256, 125, 4);
    break;

    case NIGHT4 : tft.setTextDatum(MC_DATUM);
                  tft.drawString(String(cell_temp), 320, 95, 4);
                  tft.drawString(cellDrawWeather(tft), 320, 125, 4);
    break;

    case NIGHT5 : tft.setTextDatum(MC_DATUM);
                  tft.drawString(String(cell_temp), 384, 95, 4);
                  tft.drawString(cellDrawWeather(tft), 384, 125, 4);
    break;

    case NIGHT6 : tft.setTextDatum(MC_DATUM);
                  tft.drawString(String(cell_temp), 448, 95, 4);
                  tft.drawString(cellDrawWeather(tft), 448, 125, 4);
    break;

    case MORNING1 : tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 128, 155, 4);
                    tft.drawString(cellDrawWeather(tft), 128, 185, 4);
    break;

    case MORNING2 : tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 192, 155, 4);
                    tft.drawString(cellDrawWeather(tft), 192, 185, 4);
    break;

    case MORNING3 : tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 26, 155, 4);
                    tft.drawString(cellDrawWeather(tft), 256, 185, 4);
    break;

    case MORNING4 : tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 320, 155, 4);
                    tft.drawString(cellDrawWeather(tft), 320, 185, 4);
    break;

    case MORNING5 : tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 384, 155, 4);
                    tft.drawString(cellDrawWeather(tft), 384, 185, 4);
    break;

    case MORNING6 : tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 448, 155, 4);
                    tft.drawString(cellDrawWeather(tft), 448, 185, 4);
    break;

    case DAY1 :     tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 128, 215, 4);
                    tft.drawString(cellDrawWeather(tft), 128, 245, 4);
    break;

    case DAY2 :     tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 192, 215, 4);
                    tft.drawString(cellDrawWeather(tft), 192, 245, 4);
    break;

    case DAY3 :     tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 256, 215, 4);
                    tft.drawString(cellDrawWeather(tft), 256, 245, 4);
    break;

    case DAY4 :     tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 320, 215, 4);
                    tft.drawString(cellDrawWeather(tft), 320, 245, 4);
    break;

    case DAY5 :     tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 384, 215, 4);
                    tft.drawString(cellDrawWeather(tft), 384, 245, 4);
    break;

    case DAY6 :     tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 448, 215, 4);
                    tft.drawString(cellDrawWeather(tft), 448, 245, 4);
    break;

    case EVENING1 : tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 128, 275, 4);
                    tft.drawString(cellDrawWeather(tft), 128, 305, 4);
    break;

    case EVENING2 : tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 192, 275, 4);
                    tft.drawString(cellDrawWeather(tft), 192, 305, 4);
    break;

    case EVENING3 : tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 256, 275, 4);
                    tft.drawString(cellDrawWeather(tft), 256, 305, 4);
    break;

    case EVENING4 : tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 320, 275, 4);
                    tft.drawString(cellDrawWeather(tft), 320, 305, 4);
    break;

    case EVENING5 : tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 384, 275, 4);
                    tft.drawString(cellDrawWeather(tft), 384, 305, 4);
    break;

    case EVENING6 : tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 448, 275, 4);
                    tft.drawString(cellDrawWeather(tft), 448, 305, 4);
    break;
 
    default:        tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(0), 128, 95, 4);
                    tft.drawString("unkn", 128, 125, 4);
    break;
   }
}

void ForecastPage::drawStatic()
{
  tft.fillScreen(TFT_DARKGREY);
  tft.fillRect(0, 0, 239, 39, TFT_RED);

  drawHLine(0, 40, 480, TFT_WHITE, 1);
  drawHLine(0, 80, 480, TFT_WHITE, 1); 
  drawHLine(0, 140, 480, TFT_WHITE, 1);
  drawHLine(0, 200, 480, TFT_WHITE, 1);
  drawHLine(0, 260, 480, TFT_WHITE, 1);
  drawHLine(96, 110, 370, TFT_WHITE, 1);
  drawHLine(96, 170, 370, TFT_WHITE, 1);
  drawHLine(96, 230, 370, TFT_WHITE, 1);
  drawHLine(96, 290, 370, TFT_WHITE, 1);

  float data = 45.85;          // debug
  tft.setTextDatum(MC_DATUM);
  tft.setTextColor(TFT_BLACK);
  tft.drawString("EXIT", 120, 20, 4);
  tft.drawString("UPDATE", 360, 20, 4); tft.drawString(String(data), 128, 60, 4); // Debug
  tft.drawString("Data", 47, 60, 4);
  tft.drawString("Night", 47, 110, 4);
  tft.drawString("Morning", 47, 170, 4);
  tft.drawString("Day", 47, 230, 4);
  tft.drawString("Evening", 47, 290, 4);
  

  drawVLine(96, 40, 280, TFT_WHITE, 1);
  drawVLine(160, 40, 280, TFT_WHITE, 1);
  drawVLine(224, 40, 280, TFT_WHITE, 1);
  drawVLine(288, 40, 280, TFT_WHITE, 1);
  drawVLine(352, 40, 280, TFT_WHITE, 1);
  drawVLine(416, 40, 280, TFT_WHITE, 1);
}

void ForecastPage::updateDinamic()
{
   if(btn_exit.isTouched())
   {  
      structtouch.pressed = false;
      manager.setPage(&mainpage);
   } 
}






    

