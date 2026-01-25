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

 /*void drawForecastGrid()  // Функция заполнения ячеек страницы прогноза погоды
 {
  for(int day = 0; day < DAYS; day++)
  {
    for (int part = 0; part < PARTS; part++)
    {
     // drawCell(part, day, forecast[day][part]);
    }
  }
 }*/

/*struct Cell
{
  bool valid;
  int8_t temp;
  String label;
};*/

/*void drawCell(int day, int part, const Cell& cell)
{
  //-----вычисляем координаты ячейки------
  int x = GRID_X0 + day * CELL_W;
  int y = GRID_Y0 + part * CELL_H;

  int cx = x + CELL_W / 2;
  int cy = y + CELL_H / 2;

  //--- если данных нет----
  if(cell.valid)
  {
    tft.setTextDatum(MC_DATUM);
    tft.drawString("--", cx, cy, 2);
    return;
  }
    //--- температура (верх ячейки)
     if(cell.temp != NO_TEMP)
     {
      tft.setTextDatum(MC_DATUM);
        tft.drawString(
        String(cell.temp) + tft.print((char)176), // это значек - кружочек цельсия
        cx,
        y + CELL_H * 0.30,
        2
      );
     }

     if(!cell.label.isEmpty())
     {
      tft.setTextDatum(MC_DATUM);
      tft.drawString(
        cell.label, 
        cx, 
        y + CELL_H * 0.75,
        1
      );
     }
  
}*/

