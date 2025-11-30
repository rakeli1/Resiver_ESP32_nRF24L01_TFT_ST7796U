#pragma once
#include <RF24.h>


struct RadioData
{
   float temperature;
   float humidity;
   float pressure;
     int baterylevel;  
};

struct ForecastData
{
  float temp_morning;
  float temp_day;
  float temp_evening;
  float temp_night;
  int   rain_chance;
  float precipitatios;
  char desc[50];
};

struct TimeData
{
   int hour;
   int minute;
   int seconds;

   int day;
   int month;
   int year;

   int weekday;
   unsigned long unixTime;
};


class DataReciver
{
  private:
     RF24&        radiomodul;
     float        dataSensor[4];
     RadioData    radiodata;
     ForecastData forecast;
     TimeData     timedata;
     

  public:
     DataReciver(RF24& radio);
     void updateRadio();
     void updateForecast();
     void updateTimeData();
     
     RadioData& getRadioData();
     ForecastData& getForecastData(); 
        TimeData&  getTimeData(); 
};