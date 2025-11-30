#pragma once
#include "Page.h"
#include "DataReciver.h"
#include <stdint.h>
#include <Arduino.h> 

class MainPage : public Page
{
 public:
      MainPage(DataReciver *datareciver);
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

           DataReciver *datareciver;
           float temperature = 0;
           float humidity = 0;
           float pressure = 0;
           int batteryLevel = 0;
           String currentData = "--";
           String currentTime = "-- : --";
           String dayOfWeek = " ----";

           uint8_t hour = 0;
           uint8_t minute = 0;
           uint8_t second = 0;

           uint8_t day = 00;
           uint8_t month = 00;
           uint16_t year = 00;

           unsigned long needRedraw; // чтобы не рисовать дисплей 50 раз в секунду
           const unsigned long redrawInterval = 500; // 500мс
          
};