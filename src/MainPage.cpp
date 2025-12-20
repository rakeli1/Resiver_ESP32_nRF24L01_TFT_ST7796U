
#include "MainPage.h"
#include <TFT_eSPI.h>
#include "RadioData.h"

MainPage::MainPage(TFT_eSPI& display, struc_radioPaket& paket, RadioData& _radiodata) : 
tft(display),sprTemp(&display),sprHumidity(&display),
 sprPressure(&display), sprIcon(&display), sprBaterry(&display), sprTime(&display),
 sprWiFi(&display), sprData(&display), sensorData(paket), radiodata(_radiodata)
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

 
 void MainPage::drawStatic() 
 {
  tft.fillScreen(TFT_DARKGREY);

  drawVline(160, 0, 320, TFT_WHITE, 2);
  drawVline(320, 220, 100, TFT_WHITE, 2);
  drawVline(320, 71, 250, TFT_WHITE, 2);
  drawHLine(0, 220, 480, TFT_WHITE, 2);
  drawHLine(0, 70, 480, TFT_WHITE, 2);
  drawHLine(0, 145, 160, TFT_WHITE, 2);
  
  tft.fillRect(0, 0, 20, 20, TFT_BLUE);  // ориентир setRotation()
  tft.drawRect(170, 5, 40, 13, TFT_WHITE ); // индикатор батареи
  tft.fillCircle(240, 125, 20, TFT_YELLOW);

  
  sprIcon.createSprite(64, 64);    // спрайт иконки погоды на текущий день
  sprBaterry.createSprite(38, 11); // индикатор батареи в своих размерах
  sprTime.createSprite(150, 40);
  sprWiFi.createSprite(40, 20);
  sprData.createSprite(150, 40);

  tft.setTextDatum(MC_DATUM); // центр по оси Х И по оси Y
  tft.setTextColor(TFT_BLACK);
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

  tft.setTextDatum(MC_DATUM);
  tft.setTextColor(TFT_BLACK);
  tft.setTextFont(4);
  tft.drawString("Wi-Fi", 360, 17);

  sprIcon.pushSprite(200, 100);   // спрайт иконки погоды на текущий день
  sprBaterry.pushSprite(171, 6); // индикатор батареи на своем месте
  sprTime.pushSprite(326, 180);
  sprWiFi.pushSprite(400, 6);
  sprData.pushSprite(166, 180);
}

void MainPage::updateTemp()
{
  if(sensorData.temperature != lastTemp)
  {
    sprTemp.createSprite(100, 50);
    sprTemp.fillSprite(TFT_DARKGREY);
    sprTemp.setTextColor(TFT_BLACK);
    sprTemp.setTextDatum(TC_DATUM);
    sprTemp.drawString(String(sensorData.temperature), 50, 0, 7);
    sprTemp.pushSprite(190, 260);
    lastTemp = sensorData.temperature;
  }
}

void MainPage::updateHumidity()
{
  if(sensorData.humidity!= lastHumidity)
  {
    sprHumidity.createSprite(100, 50);
    sprHumidity.fillSprite(TFT_DARKGREY);
    sprHumidity.setTextColor(TFT_BLACK);
    sprHumidity.setTextDatum(TC_DATUM);
    sprHumidity.drawString(String(sensorData.humidity), 50, 0, 7);
    sprHumidity.pushSprite(350, 260);
    lastHumidity = sensorData.humidity;
  }
}

void MainPage::updatePressure()
{
    if(sensorData.pressure != lastPressure)
    {
        sprPressure.createSprite(100, 50);
        sprPressure.fillSprite(TFT_DARKGREY);
        sprPressure.setTextColor(TFT_BLACK);
        sprPressure.setTextDatum(TC_DATUM);
        sprPressure.drawString(String(sensorData.pressure), 50, 0, 7);
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

void MainPage::updateTime(String t)
{
    sprTime.fillSprite(TFT_BLUE);
    sprTime.drawString(t, 0, 0, 4);
    sprTime.pushSprite(10, 200);
}

void MainPage::updateWiFi(bool connected)
{
    if(connected != lastWiFi)
    {
        sprWiFi.fillSprite(TFT_BLUE);
        sprWiFi.drawString(connected ? "WiFi" : "NoWiFi", 0, 0, 2);
        sprWiFi.pushSprite(200, 200);
        lastWiFi = connected;
    }
}

 void MainPage::updateDinamic()
{
     //Сюда добавить функции обновления обновляемых параметров  
     // ссылку на структуру которых будет хранить член класса MainPage
     // обьявления функций смотреть в хедере этого класса
     radiodata.upDate();
     sensorData = radiodata.getData();
     updatePressure();
     updateHumidity();
     updateTemp();
     //updateBaterry();
}

 
