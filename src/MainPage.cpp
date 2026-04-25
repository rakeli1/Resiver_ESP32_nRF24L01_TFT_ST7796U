#include "Page.h"
#include "MainPage.h"
#include <TFT_eSPI.h>
#include "RadioData.h"
#include "ForecastPage.h"
#include "SettingPage.h"
#include "CurrencyPage.h"
#include "struct_TouchState.h"

extern FT6336U gl_touch;
//class ForecastPage;
extern ForecastPage forecastpage;
extern SettingPage settingpage;
extern CurrencyPage currencypage;
extern uint16_t tX;
extern uint16_t tY;
extern TouchState structtouch;

extern void getTouchXY(int& x, int& y);
//extern int hours;
//extern int minute;

MainPage::MainPage(TFT_eSPI& display, struc_radioPaket& paket, RadioData& _radiodata, PageManager& _manager) : 
tft(display),sprTemp(&display),sprHumidity(&display),
 sprPressure(&display), sprIcon(&display), sprBaterry(&display), sprTimeHour(&display), sprTimeMinutes(&display),
 sprWiFi(&display), sprDayWeek(&display), sensorData(paket), radiodata(_radiodata), manager(_manager),
  btn_forecast(0, 0, 160, 70, TFT_DARKGREY, true, true), btn_settings(0, 70, 160, 70, TFT_DARKGREY, true, true),
   btn_currencypage(0, 140, 160, 70, TFT_DARKGREY, true, true)
 {

 }

 void MainPage::drawVline(int32_t x0, int32_t y0, int32_t visota, int32_t color, int repit)
{
  for(int i = 0; i < repit; i++)
 {
  tft.drawFastVLine(x0 + i, y0, visota, color);
 }
}

void MainPage::drawHLine(int32_t x0, int32_t y0, int32_t chirina, int32_t color, int repit)
{
  for(int i = 0; i < repit; i++)
 {
  tft.drawFastHLine(x0, y0 + i, chirina, color);
 }
}

String MainPage::returnDay(uint8_t dayOfWeek)
{
  switch(this->dayOfWeek)
  {
     case 0 : return "SUNDAY"; break;
     case 1 : return "MONDAY"; break;
     case 2 : return "TUESDAY"; break;
     case 3 : return "WEDNESDAY"; break;
     case 4 : return "THURSDAY"; break;
     case 5 : return "FRIDAY"; break;
     case 6 : return "SATURDAY"; break;
     default : return "--------"; break;
  }

}

 
 void MainPage::drawStatic() 
 {
  tft.fillScreen(TFT_DARKGREY);

  drawVline(160, 0, 320, TFT_WHITE, 2);
  drawVline(320, 71, 250, TFT_WHITE, 2);
  drawHLine(0, 220, 480, TFT_WHITE, 2);
  drawHLine(0, 70, 480, TFT_WHITE, 2);
  drawHLine(0, 145, 160, TFT_WHITE, 2);
  
 // tft.fillRect(0, 0, 20, 20, TFT_BLUE);  // ориентир setRotation()
  tft.drawRect(170, 5, 40, 13, TFT_WHITE ); // индикатор батареи
 // tft.fillCircle(240, 125, 20, TFT_YELLOW);

  
  sprIcon.createSprite(64, 64);    // спрайт иконки погоды на текущий день
  sprBaterry.createSprite(38, 11); // индикатор батареи в своих размерах
  
  

  tft.setTextDatum(MC_DATUM); // центр по оси Х И по оси Y
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(1);///////////////////////////////////////////////////////////////УБРАТЬ!!!!
  tft.setTextFont(4);
  tft.drawString("Temperature", 240, 240);
  tft.drawString("Humidity", 400, 240);
  tft.drawString("Pressure", 80, 240);

  tft.setTextDatum(MC_DATUM);
  tft.setTextColor(TFT_BLACK);
  tft.setTextFont(4);
  tft.drawString("SETTINGS", 80, 114);
  tft.drawString("CURRENCY", 80, 185);
  tft.drawString("FORECAST", 80, 40);
  tft.setTextFont(6);
  tft.drawString(":", 404, 205);

  tft.setTextDatum(MC_DATUM);
  tft.setTextColor(TFT_BLACK);
  tft.setTextFont(4);
  tft.drawString("Wi-Fi", 360, 17);

  sprIcon.pushSprite(200, 100);   // спрайт иконки погоды на текущий день
  sprBaterry.pushSprite(171, 6); // индикатор батареи на своем месте
  
  
  
    
}

void MainPage::updateDayWeek()
{  
   sprDayWeek.createSprite(150, 40);
   sprDayWeek.fillSprite(TFT_DARKGREY);
   sprDayWeek.setTextColor(TFT_BLACK);
   sprDayWeek.setTextDatum(MC_DATUM);
   sprDayWeek.drawString((this->returnDay(this->dayOfWeek)), 75, 25, 4); //(this->returnDay(this->dayOfWeek)
   sprDayWeek.pushSprite(166, 180);
}

void MainPage::updateTemp()
{
  if(true)//sensorData.temperature != lastTemp
  {
    sprTemp.createSprite(100, 50);
    sprTemp.fillSprite(TFT_DARKGREY);
    sprTemp.setTextColor(TFT_BLACK);
    sprTemp.setTextDatum(TC_DATUM);
    sprTemp.drawString(String(lastTemp), 50, 0, 7);
    sprTemp.pushSprite(190, 260);
    lastTemp = sensorData.temperature;
    //Serial.println("UpdateSpriteTemperature");
  }
}

void MainPage::updateHumidity()
{
  if(true)
  {
    sprHumidity.createSprite(100, 50);
    sprHumidity.fillSprite(TFT_DARKGREY);
    sprHumidity.setTextColor(TFT_BLACK);
    sprHumidity.setTextDatum(TC_DATUM);
    sprHumidity.drawString(String(lastHumidity), 50, 0, 7);
    sprHumidity.pushSprite(350, 260);
    lastHumidity = sensorData.humidity;
  }
}

void MainPage::updatePressure()
{
    if(true)//sensorData.pressure != lastPressure
    {
        sprPressure.createSprite(100, 50);
        sprPressure.fillSprite(TFT_DARKGREY);
        sprPressure.setTextColor(TFT_BLACK);
        sprPressure.setTextDatum(TC_DATUM);
        sprPressure.drawString(String(lastPressure), 50, 0, 7);
        sprPressure.pushSprite(30, 260);
        lastPressure = sensorData.pressure;
    }
}

void MainPage::updateIconWeather(int iconID)
{
    if(iconID != lastIconID)
    {
        sprIcon.fillSprite(TFT_BLUE);
        //sprIcon.pushImage.... тут моя иконка погоды
        sprIcon.pushSprite(200, 10);
        lastIconID = iconID;
    }
}

void MainPage::updateBaterry()
{
    if(sensorData.percent != lastPecent)
    {
        sprBaterry.fillSprite(TFT_BLUE);
        sprBaterry.setTextColor(TFT_BLACK);
        sprBaterry.drawString(String(sensorData.percent), 0, 0, 2);
        sprBaterry.pushSprite(10, 200);
        lastPecent = sensorData.percent;
    }
}

void MainPage::updateTime()
{   
    sprTimeHour.createSprite(56, 40);
    sprTimeHour.fillSprite(TFT_DARKGREY);
    sprTimeHour.setTextColor(TFT_BLACK);
    sprTimeHour.setTextDatum(MC_DATUM);
    sprTimeHour.drawString((hours < 10 ? "0" : "") + String(hours), 28, 25, 6);
    sprTimeHour.pushSprite(336, 180);

    sprTimeMinutes.createSprite(56, 40);
    sprTimeMinutes.fillSprite(TFT_DARKGREY);
    sprTimeMinutes.setTextColor(TFT_BLACK);
    sprTimeMinutes.setTextDatum(MC_DATUM);
    sprTimeMinutes.drawString((minutes < 10 ? "0": "") + String(minutes), 28, 25, 6);
    sprTimeMinutes.pushSprite(416, 180);
}

void MainPage::updateWiFi()
{ 
  sprWiFi.createSprite(40, 20);
  sprWiFi.fillSprite(TFT_BLUE);
  sprWiFi.drawString(lastWiFi ? "ON" : "OF", 0, 0, 4);
  sprWiFi.pushSprite(400, 6);
  
}



 void MainPage::updateDinamic()
{  
     radiodata.upDate();
     updateTime();
     updatePressure();
     updateHumidity();
     updateTemp();
     updateWiFi();
     updateDayWeek();
     
     //updateBaterry();
  
    
     // if(gl_touch.read_td_status()==1)
    
       if(btn_settings.isTouched())
      {
         manager.setPage(&settingpage);
      }else if(btn_forecast.isTouched())
      { 
         manager.setPage(&forecastpage);
      }else if(btn_currencypage.isTouched())
      { 
        manager.setPage(&currencypage);
      }
      //Serial.println("Enter MainPage upDate Dinamicccccccccccccccc");
}
      //structtouch.pressed = false; 
    

 
 
    

   
