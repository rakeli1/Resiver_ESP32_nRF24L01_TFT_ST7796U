#include "ForecastPage.h"
#include "MainPage.h"
#include "DataResiver.h"

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


String ForecastPage::Cell::cellreturnWeather()
{
   switch(cell_Weathertype)
   {
     case CLEAR :        return "clear";  break;
     case CLOUDS :       return "cloud";  break;
     case RAIN :         return "rain";   break;
     case DRIZZLE :      return "driz";   break;
     case THUNDERSTORM : return "thund";  break;
     case SNOW :         return "snow";   break;
     case MIST :         return "mist";   break;
     case SMOKE :        return "smoke";  break;
     case HAZE :         return "haze";   break;
     case DUST :         return "dust";   break;
     case SAND :         return "sand";   break;
     case ASH :          return "ash";    break;
     case SQUALL :       return "squal";  break;
     case TORNADO :      return "torna";  break;
     case WEATHER_UNKNOWN : return "her"; break;
     default :           return "unkn";   break;
    } 
    
}

void ForecastPage::Cell::cellDraw(TFT_eSPI& tft)
{
   switch (cell_Id)
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
                  tft.drawString(cellreturnWeather(), 128, 125, 4);
    break;

    case NIGHT2 : tft.setTextDatum(MC_DATUM);
                  tft.drawString(String(cell_temp), 192, 95, 4);
                  tft.drawString(cellreturnWeather(), 192, 125, 4);
    break;

    case NIGHT3 : tft.setTextDatum(MC_DATUM);
                  tft.drawString(String(cell_temp), 256, 95, 4);
                  tft.drawString(cellreturnWeather(), 256, 125, 4);
    break;

    case NIGHT4 : tft.setTextDatum(MC_DATUM);
                  tft.drawString(String(cell_temp), 320, 95, 4);
                  tft.drawString(cellreturnWeather(), 320, 125, 4);
    break;

    case NIGHT5 : tft.setTextDatum(MC_DATUM);
                  tft.drawString(String(cell_temp), 384, 95, 4);
                  tft.drawString(cellreturnWeather(), 384, 125, 4);
    break;

    case NIGHT6 : tft.setTextDatum(MC_DATUM);
                  tft.drawString(String(cell_temp), 448, 95, 4);
                  tft.drawString(cellreturnWeather(), 448, 125, 4);
    break;

    case MORNING1 : tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 128, 155, 4);
                    tft.drawString(cellreturnWeather(), 128, 185, 4);
    break;

    case MORNING2 : tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 192, 155, 4);
                    tft.drawString(cellreturnWeather(), 192, 185, 4);
    break;

    case MORNING3 : tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 256, 155, 4);
                    tft.drawString(cellreturnWeather(), 256, 185, 4);
    break;

    case MORNING4 : tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 320, 155, 4);
                    tft.drawString(cellreturnWeather(), 320, 185, 4);
    break;

    case MORNING5 : tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 384, 155, 4);
                    tft.drawString(cellreturnWeather(), 384, 185, 4);
    break;

    case MORNING6 : tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 448, 155, 4);
                    tft.drawString(cellreturnWeather(), 448, 185, 4);
    break;

    case DAY1 :     tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 128, 215, 4);
                    tft.drawString(cellreturnWeather(), 128, 245, 4);
    break;

    case DAY2 :     tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 192, 215, 4);
                    tft.drawString(cellreturnWeather(), 192, 245, 4);
    break;

    case DAY3 :     tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 256, 215, 4);
                    tft.drawString(cellreturnWeather(), 256, 245, 4);
    break;

    case DAY4 :     tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 320, 215, 4);
                    tft.drawString(cellreturnWeather(), 320, 245, 4);
    break;

    case DAY5 :     tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 384, 215, 4);
                    tft.drawString(cellreturnWeather(), 384, 245, 4);
    break;

    case DAY6 :     tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 448, 215, 4);
                    tft.drawString(cellreturnWeather(), 448, 245, 4);
    break;

    case EVENING1 : tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 128, 275, 4);
                    tft.drawString(cellreturnWeather(), 128, 305, 4);
    break;

    case EVENING2 : tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 192, 275, 4);
                    tft.drawString(cellreturnWeather(), 192, 305, 4);
    break;

    case EVENING3 : tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 256, 275, 4);
                    tft.drawString(cellreturnWeather(), 256, 305, 4);
    break;

    case EVENING4 : tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 320, 275, 4);
                    tft.drawString(cellreturnWeather(), 320, 305, 4);
    break;

    case EVENING5 : tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 384, 275, 4);
                    tft.drawString(cellreturnWeather(), 384, 305, 4);
    break;

    case EVENING6 : tft.setTextDatum(MC_DATUM);
                    tft.drawString(String(cell_temp), 448, 275, 4);
                    tft.drawString(cellreturnWeather(), 448, 305, 4);
    break;
 
    default:       //tft.setTextDatum(MC_DATUM);
                   // tft.drawString(String(0), 128, 95, 4);
                   // tft.drawString("unkn", 128, 125, 4);
    break;
   }
}

void ForecastPage::updateAllCells(DataResiver& dataresiver)
{
   for(int i = 0; i < 46; i++)
   {
      switch (dataresiver.forecastarray[i].parthdayID)
      {
      case DATA1 :      
                   if(cellData1.cell_Id == PARTHZERO)
                     {
                     cellData1.cell_data = dataresiver.forecastarray[i].day;
                     cellData1.cell_Id   = dataresiver.forecastarray[i].parthdayID;
                     }
      break;

      case DATA2 :   
                    if(cellData2.cell_Id == PARTHZERO)
                    {
                     cellData2.cell_data = dataresiver.forecastarray[i].day;
                     cellData2.cell_Id   = dataresiver.forecastarray[i].parthdayID;
                    }
      break;
         
      case DATA3 :   
                    if(cellData3.cell_Id == PARTHZERO)
                    {
                     cellData3.cell_data = dataresiver.forecastarray[i].day;
                     cellData3.cell_Id   = dataresiver.forecastarray[i].parthdayID;
                    }
      break;

      case DATA4 :   
                    if(cellData4.cell_Id == PARTHZERO)
                    {
                     cellData4.cell_data = dataresiver.forecastarray[i].day;
                     cellData4.cell_Id = dataresiver.forecastarray[i].parthdayID;
                    }
      break;

      case DATA5 :   
                    if(cellData5.cell_Id == PARTHZERO)
                    {
                     cellData5.cell_data = dataresiver.forecastarray[i].day;
                     cellData5.cell_Id   = dataresiver.forecastarray[i].parthdayID;
                    }
      break;

      case DATA6 :   
                    if(cellData6.cell_Id == PARTHZERO)
                    {
                     cellData6.cell_data = dataresiver.forecastarray[i].day;
                     cellData6.cell_Id   = dataresiver.forecastarray[i].parthdayID;
                    }
      break;

      case NIGHT1 : 
                     if(cellNight1.cell_Id != PARTHZERO)
                     {
                        cellNight1.cell_temp = (cellNight1.cell_temp + dataresiver.forecastarray[i].temperature) / 2;
                     }else
                     {
                        cellNight1.cell_temp = dataresiver.forecastarray[i].temperature;
                        cellNight1.cell_Id   = dataresiver.forecastarray[i].parthdayID;
                     }
      break;

      case NIGHT2 : 
                     if(cellNight2.cell_Id != PARTHZERO)
                     {
                        cellNight2.cell_temp = (cellNight2.cell_temp + dataresiver.forecastarray[i].temperature) / 2;
                     }else
                     {
                        cellNight2.cell_temp = dataresiver.forecastarray[i].temperature;
                        cellNight2.cell_Id   = dataresiver.forecastarray[i].parthdayID;
                     }
      break;

      case NIGHT3 : 
                     if(cellNight3.cell_Id != PARTHZERO)
                     {
                        cellNight3.cell_temp = (cellNight3.cell_temp + dataresiver.forecastarray[i].temperature) / 2;
                     }else
                     {
                        cellNight3.cell_temp = dataresiver.forecastarray[i].temperature;
                        cellNight3.cell_Id   = dataresiver.forecastarray[i].parthdayID;
                     }
      break;

      case NIGHT4 : 
                     if(cellNight4.cell_Id != PARTHZERO)
                     {
                        cellNight4.cell_temp = (cellNight4.cell_temp + dataresiver.forecastarray[i].temperature) / 2;
                     }else
                     {
                        cellNight4.cell_temp = dataresiver.forecastarray[i].temperature;
                        cellNight4.cell_Id   = dataresiver.forecastarray[i].parthdayID;
                     }
      break;
      
      case NIGHT5 : 
                     if(cellNight5.cell_Id != PARTHZERO)
                     {
                        cellNight5.cell_temp = (cellNight5.cell_temp + dataresiver.forecastarray[i].temperature) / 2;
                     }else
                     {
                        cellNight5.cell_temp = dataresiver.forecastarray[i].temperature;
                        cellNight5.cell_Id   = dataresiver.forecastarray[i].parthdayID;
                     }
      break;

      case NIGHT6 : 
                     if(cellNight6.cell_Id != PARTHZERO)
                     {
                        cellNight6.cell_temp = (cellNight6.cell_temp + dataresiver.forecastarray[i].temperature) / 2;
                     }else
                     {
                        cellNight6.cell_temp = dataresiver.forecastarray[i].temperature;
                        cellNight6.cell_Id   = dataresiver.forecastarray[i].parthdayID;

                     }
      break;

      case MORNING1 : 
                     if(cellMorning1.cell_Id != PARTHZERO)
                     {
                        cellMorning1.cell_temp = (cellMorning1.cell_temp + dataresiver.forecastarray[i].temperature) / 2;
                     }else
                     {
                        cellMorning1.cell_temp = dataresiver.forecastarray[i].temperature;
                        cellMorning1.cell_Id   = dataresiver.forecastarray[i].parthdayID;

                     }
      break;

      case MORNING2 : 

                      if(cellMorning2.cell_Id != PARTHZERO)
                     {
                        cellMorning2.cell_temp = (cellMorning2.cell_temp + dataresiver.forecastarray[i].temperature) / 2;
                     }else
                     {
                        cellMorning2.cell_temp = dataresiver.forecastarray[i].temperature;
                        cellMorning2.cell_Id   = dataresiver.forecastarray[i].parthdayID;

                     }
      break;

      case MORNING3 : 
                     if(cellMorning3.cell_Id != PARTHZERO)
                     {
                        cellMorning3.cell_temp = (cellMorning3.cell_temp + dataresiver.forecastarray[i].temperature) / 2;
                     }else
                     {
                        cellMorning3.cell_temp = dataresiver.forecastarray[i].temperature;
                        cellMorning3.cell_Id   = dataresiver.forecastarray[i].parthdayID;

                     }
      break;

      case MORNING4 : 
                     if(cellMorning4.cell_Id != PARTHZERO)
                     {
                        cellMorning4.cell_temp = (cellMorning4.cell_temp + dataresiver.forecastarray[i].temperature) / 2;
                     }else
                     {
                        cellMorning4.cell_temp = dataresiver.forecastarray[i].temperature;
                        cellMorning4.cell_Id   = dataresiver.forecastarray[i].parthdayID;

                     }
      break;

      case MORNING5 : 
                     if(cellMorning5.cell_Id != PARTHZERO)
                     {
                        cellMorning5.cell_temp = (cellMorning5.cell_temp + dataresiver.forecastarray[i].temperature) / 2;
                     }else
                     {
                        cellMorning5.cell_temp = dataresiver.forecastarray[i].temperature;
                        cellMorning5.cell_Id   = dataresiver.forecastarray[i].parthdayID;

                     }
      break;

      case MORNING6 : 
                     if(cellMorning6.cell_Id != PARTHZERO)
                     {
                        cellMorning6.cell_temp = (cellMorning6.cell_temp + dataresiver.forecastarray[i].temperature) / 2;
                     }else
                     {
                        cellMorning6.cell_temp = dataresiver.forecastarray[i].temperature;
                        cellMorning6.cell_Id   = dataresiver.forecastarray[i].parthdayID;

                     }
      break;

      case DAY1 : 
                     if(cellDay1.cell_Id != PARTHZERO)
                     {
                        cellDay1.cell_temp = (cellDay1.cell_temp + dataresiver.forecastarray[i].temperature) / 2;
                     }else
                     {
                        cellDay1.cell_temp = dataresiver.forecastarray[i].temperature;
                        cellDay1.cell_Id   = dataresiver.forecastarray[i].parthdayID;

                     }
      break;

      case DAY2 : 
                     if(cellDay2.cell_Id != PARTHZERO)
                     {
                        cellDay2.cell_temp = (cellDay2.cell_temp + dataresiver.forecastarray[i].temperature) / 2;
                     }else
                     {
                        cellDay2.cell_temp = dataresiver.forecastarray[i].temperature;
                        cellDay2.cell_Id   = dataresiver.forecastarray[i].parthdayID;

                     }
      break;

      case DAY3 : 
                     if(cellDay3.cell_Id != PARTHZERO)
                     {
                        cellDay3.cell_temp = (cellDay3.cell_temp + dataresiver.forecastarray[i].temperature) / 2;
                     }else
                     {
                        cellDay3.cell_temp = dataresiver.forecastarray[i].temperature;
                        cellDay3.cell_Id   = dataresiver.forecastarray[i].parthdayID;

                     }
      break;

      case DAY4 : 
                     if(cellDay4.cell_Id != PARTHZERO)
                     {
                        cellDay4.cell_temp = (cellDay4.cell_temp + dataresiver.forecastarray[i].temperature) / 2;
                     }else
                     {
                        cellDay4.cell_temp = dataresiver.forecastarray[i].temperature;
                        cellDay4.cell_Id   = dataresiver.forecastarray[i].parthdayID;

                     }
      break;

      case DAY5 : 
                     if(cellDay5.cell_Id != PARTHZERO)
                     {
                        cellDay5.cell_temp = (cellDay5.cell_temp + dataresiver.forecastarray[i].temperature) / 2;
                     }else
                     {
                        cellDay5.cell_temp = dataresiver.forecastarray[i].temperature;
                        cellDay5.cell_Id   = dataresiver.forecastarray[i].parthdayID;

                     }
      break;

      case DAY6 : 
                     if(cellDay6.cell_Id != PARTHZERO)
                     {
                        cellDay6.cell_temp = (cellDay6.cell_temp + dataresiver.forecastarray[i].temperature) / 2;
                     }else
                     {
                        cellDay6.cell_temp = dataresiver.forecastarray[i].temperature;
                        cellDay6.cell_Id   = dataresiver.forecastarray[i].parthdayID;

                     }
      break;

      case EVENING1 : 
                     if(cellEvening1.cell_Id != PARTHZERO)
                     {
                        cellEvening1.cell_temp = (cellEvening1.cell_temp + dataresiver.forecastarray[i].temperature) / 2;
                     }else
                     {
                        cellEvening1.cell_temp = dataresiver.forecastarray[i].temperature;
                        cellEvening1.cell_Id   = dataresiver.forecastarray[i].parthdayID;

                     }
      break;

      case EVENING2 : 
                     if(cellEvening2.cell_Id != PARTHZERO)
                     {
                        cellEvening2.cell_temp = (cellEvening2.cell_temp + dataresiver.forecastarray[i].temperature) / 2;
                     }else
                     {
                        cellEvening2.cell_temp = dataresiver.forecastarray[i].temperature;
                        cellEvening2.cell_Id   = dataresiver.forecastarray[i].parthdayID;

                     }
      break;

      case EVENING3 : 
                     if(cellEvening3.cell_Id != PARTHZERO)
                     {
                        cellEvening3.cell_temp = (cellEvening3.cell_temp + dataresiver.forecastarray[i].temperature) / 2;
                     }else
                     {
                        cellEvening3.cell_temp = dataresiver.forecastarray[i].temperature;
                        cellEvening3.cell_Id   = dataresiver.forecastarray[i].parthdayID;

                     }
      break;

      case EVENING4 : 
                     if(cellEvening4.cell_Id != PARTHZERO)
                     {
                        cellEvening4.cell_temp = (cellEvening4.cell_temp + dataresiver.forecastarray[i].temperature) / 2;
                     }else
                     {
                        cellEvening4.cell_temp = dataresiver.forecastarray[i].temperature;
                        cellEvening4.cell_Id   = dataresiver.forecastarray[i].parthdayID;

                     }
      break;

      case EVENING5 : 
                     if(cellEvening5.cell_Id != PARTHZERO)
                     {
                        cellEvening5.cell_temp = (cellEvening5.cell_temp + dataresiver.forecastarray[i].temperature) / 2;
                     }else
                     {
                        cellEvening5.cell_temp = dataresiver.forecastarray[i].temperature;
                        cellEvening5.cell_Id   = dataresiver.forecastarray[i].parthdayID;

                     }
      break;

      case EVENING6 : 
                     if(cellEvening6.cell_Id != PARTHZERO)
                     {
                        cellEvening6.cell_temp = (cellEvening6.cell_temp + dataresiver.forecastarray[i].temperature) / 2;
                     }else
                     {
                        cellEvening6.cell_temp = dataresiver.forecastarray[i].temperature;
                        cellEvening6.cell_Id   = dataresiver.forecastarray[i].parthdayID;

                     }
      break;

      default:
         break;
      }
   }
}

void ForecastPage::drawStatic()
{
  tft.fillScreen(TFT_DARKGREY);
  tft.fillRect(0, 0, 239, 39, TFT_RED);

  drawHLine(0, 39, 480, TFT_BLACK, 1);
  drawHLine(0, 80, 480, TFT_BLACK, 1); 
  drawHLine(0, 140, 480, TFT_BLACK, 1);
  drawHLine(0, 200, 480, TFT_BLACK, 1);
  drawHLine(0, 260, 480, TFT_BLACK, 1);
  //drawHLine(96, 110, 370, TFT_WHITE, 1);
  //drawHLine(96, 170, 370, TFT_WHITE, 1);
  //drawHLine(96, 230, 370, TFT_WHITE, 1);
  //drawHLine(96, 290, 370, TFT_WHITE, 1);

  //float data = 45.85;          // debug
  tft.setTextDatum(MC_DATUM);
  tft.setTextColor(TFT_BLACK);
  tft.drawString("EXIT", 120, 20, 4);
  tft.drawString("UPDATE", 360, 20, 4); //tft.drawString(String(data), 128, 60, 4); // Debug
  tft.drawString("Data", 47, 60, 4);
  tft.drawString("Night", 47, 110, 4);
  tft.drawString("Morning", 47, 170, 4);
  tft.drawString("Day", 47, 230, 4);
  tft.drawString("Evening", 47, 290, 4);
  

  drawVLine( 96, 40, 280, TFT_BLACK, 1);
  drawVLine(160, 40, 280, TFT_BLACK, 1);
  drawVLine(224, 40, 280, TFT_BLACK, 1);
  drawVLine(288, 40, 280, TFT_BLACK, 1);
  drawVLine(352, 40, 280, TFT_BLACK, 1);
  drawVLine(416, 40, 280, TFT_BLACK, 1);

  updateAllCells(dataresiver);

  cellData1.cellDraw(tft);
  cellData2.cellDraw(tft);
  cellData3.cellDraw(tft);
  cellData4.cellDraw(tft);
  cellData5.cellDraw(tft);
  cellData6.cellDraw(tft);
  cellNight1.cellDraw(tft);
  cellNight2.cellDraw(tft);
  cellNight3.cellDraw(tft);
  cellNight4.cellDraw(tft);
  cellNight5.cellDraw(tft);
  cellNight6.cellDraw(tft);
  cellMorning1.cellDraw(tft);
  cellMorning2.cellDraw(tft);
  cellMorning3.cellDraw(tft);
  cellMorning4.cellDraw(tft);
  cellMorning5.cellDraw(tft);
  cellMorning6.cellDraw(tft);
  cellDay1.cellDraw(tft);
  cellDay2.cellDraw(tft);
  cellDay3.cellDraw(tft);
  cellDay4.cellDraw(tft);
  cellDay5.cellDraw(tft);
  cellDay6.cellDraw(tft);
  cellEvening1.cellDraw(tft); 
  cellEvening2.cellDraw(tft);
  cellEvening3.cellDraw(tft);
  cellEvening4.cellDraw(tft);
  cellEvening5.cellDraw(tft);
  cellEvening6.cellDraw(tft);


}

void ForecastPage::updateDinamic()
{
   if(btn_exit.isTouched())
   {  
      structtouch.pressed = false;
      
      
      manager.setPage(&mainpage);
      
   } 
}






    

