#pragma once
#include "Page.h"

class MainPage : public Page
{
 public:
      MainPage();
      ~MainPage();
       
                //МЕТОДЫ СТРАНИЦЫ
      void update() override;
      void draw() override;

              // ПРИЕМ ДАННЫХ С РАДИОКАНАЛА - ВХОДНЫЕ ДАННЫЕ
      float receiveTemperature(float t); //сохраняем данные температуры в переменную чтобы не потерять
      float receiveHumidity(float h);    //сохраняем данные влажности в переменную
      float receivePressure(float p);    //сохраняем данные в переменную
        int receiveBatteryLevel(int BatLevel); //сохраняем данные в переменную

              // ОБНОВЛЕНИЕ ВРЕМЕНИ
       void receiveTime(uint8_t hour, uint8_t minute, uint8_t second);
       void receiveData(uint8_t day, uint8_t month, uint16_t year);


      private:
           void drawMainValues();
           void drawWeatherIcon();
           void drawBateryIcon();
           void drawButtons();
           void drawDataTime();
           void drawWindows();  // ЭТО НАБРОСОК РЕШАЮ ПОЗЖЕ ЛИБО РИСОВАТЬ ЛИБО БРАТЬ ГОТОВУЮ КАРТИНКУ

           float temperature;
           float humidity;
           float pressure;
           int batteryLevel;
           String currentData;
           String currentTime;
           String dayOfWeek;

           uint8_t hour;
           uint8_t minute;
           uint8_t second;

           uint8_t day;
           uint8_t month;
           uint16_t year;

           unsigned long lastRedraw; // чтобы не рисовать дисплей 50 раз в секунду
           const unsigned long redrawInterval = 500; // 500мс
          
};