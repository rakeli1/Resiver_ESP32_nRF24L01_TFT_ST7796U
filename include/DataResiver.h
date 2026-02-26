#pragma once
#include "struct_radioPaket.h"
#include "RadioData.h"
#include "InternetForecast.h"
#include <ArduinoJson.h>
#include "TFT_eSPI.h"
#define FORECAST_POINTS 40

extern TFT_eSPI tft;

enum ParthDayID
{  
   DATA1,
   NIGHT1,  
   MORNING1,
   DAY1,
   EVENING1,
   DATAZERO1,
   NIGHTZERO1,
   MORNINGZERO1,
   DAYZERO1,
   EVENINGZERO1,
   DATA2,
   NIGHT2,  
   MORNING2,
   DAY2,
   EVENING2,
   DATA3,
   NIGHT3,  
   MORNING3,
   DAY3,
   EVENING3,
   DATA4,
   NIGHT4,  
   MORNING4,
   DAY4,
   EVENING4,
   DATA5,
   NIGHT5,  
   MORNING5,
   DAY5,
   EVENING5,
   DATA6,
   NIGHT6,  
   MORNING6,
   DAY6,
   EVENING6,
   PARTHZERO,

};



enum WeatherType
{
   WEATHER_UNKNOWN,
   CLEAR,         // Clear
   CLOUDS,        // Clouds
   RAIN,          // Rain
   DRIZZLE,       // Drizzle
   THUNDERSTORM,  // Thunderstorm
   SNOW,          // Snow
   MIST,          // Mist
   SMOKE,         // Smoke
   HAZE,          // Haze
   DUST,          // Dust
   SAND,          // Sand
   ASH,           // Ash
   SQUALL,        // Squall
   TORNADO,       // Tornado
};

struct ForecastPoint
{
   //int year;
   float temperature = 0;
   int month = 0;
   int day = 0;
   int hour = 0;
   WeatherType weathertype;
   ParthDayID parthdayID;
};



class DataResiver
{
    private:
    InternetForecast& client1;
    //----------- 0 точка-------------
   /* float list_0_main_temp = 0;
    int month0;
    int day0;
    int hour0;
    WeatherType weather0;
    //----------- 1 точка-------------
    float list_1_main_temp = 0;;
    int month1;
    int day1;
    int hour1;
    WeatherType weather1;
    //----------- 2 точка-------------
    float list_2_main_temp = 0; ;
    int month2;
    int day2;
    int hour2;
    WeatherType weather2;
    //----------- 3 точка-------------
    float list_3_main_temp = 0;
    int month3;
    int day3;
    int hour3;
    WeatherType weather3;
    //----------- 4 точка-------------
    float list_4_main_temp = 0;;
    int month4;
    int day4;
    int hour4;
    WeatherType weather4;
    //----------- 5 точка-------------
    float list_5_main_temp = 0;
    int month5;
    int day5;
    int hour5;
    WeatherType weather5;
    //----------- 6 точка-------------
    float list_6_main_temp = 0;
    int month6;
    int day6;
    int hour6;
    WeatherType weather6;
    //----------- 7 точка-------------
    float list_7_main_temp = 0;
    int month7;
    int day7;
    int hour7;
    WeatherType weather7;
    //----------- 8 точка-------------
    float list_8_main_temp = 0;
    int month8;
    int day8;
    int hour8;
    WeatherType weather8;
    //----------- 9 точка-------------
    float list_9_main_temp = 0;
    int month9;
    int day9;
    int hour9;
    WeatherType weather9;
    //----------- 10 точка-------------
    float list_10_main_temp = 0;;
    int month10;
    int day10;
    int hour10;
    WeatherType weather10;
    //----------- 11 точка-------------
    float list_11_main_temp = 0;
    int month11;
    int day11;
    int hour11;
    WeatherType weather11;
    //----------- 12 точка-------------
    float list_12_main_temp = 0;
    int month12;
    int day12;
    int hour12;
    WeatherType weather12;
    //----------- 13 точка-------------
    float list_13_main_temp = 0;
    int month13;
    int day13;
    int hour13;
    WeatherType weather13;
    //----------- 14 точка-------------
    float list_14_main_temp = 0;
    int month14;
    int day14;
    int hour14;
    WeatherType weather14;
    //----------- 15 точка-------------
    float list_15_main_temp = 0;
    int month15;
    int day15;
    int hour15;
    WeatherType weather15;
    //----------- 16 точка-------------
    float list_16_main_temp = 0;
    int month16;
    int day16;
    int hour16;
    WeatherType weather16;
    //----------- 17 точка-------------
    float list_17_main_temp = 0;
    int month17;
    int day17;
    int hour17;
    WeatherType weather17;
    //----------- 18 точка-------------
    float list_18_main_temp = 0;
    int month18;
    int day18;
    int hour18;
    WeatherType weather18;
    //----------- 19 точка-------------
    float list_19_main_temp = 0;
    int month19;
    int day19;
    int hour19;
    WeatherType weather19;
    //----------- 20 точка-------------
    float list_20_main_temp = 0;
    int month20;
    int day20;
    int hour20;
    WeatherType weather20;
    //----------- 21 точка-------------
    float list_21_main_temp = 0;
    int month21;
    int day21;
    int hour21;
    WeatherType weather21;
    //----------- 22 точка-------------
    float list_22_main_temp = 0;
    int month22;
    int day22;
    int hour22;
    WeatherType weather22;
    //----------- 23 точка-------------
    float list_23_main_temp = 0;
    int month23;
    int day23;
    int hour23;
    WeatherType weather23;
    //----------- 24 точка-------------
    float list_24_main_temp = 0;
    int month24;
    int day24;
    int hour24;
    WeatherType weather24;
    //----------- 25 точка-------------
    float list_25_main_temp = 0;
    int month25;
    int day25;
    int hour25;
    WeatherType weather25;
    //----------- 26 точка-------------
    float list_26_main_temp = 0;
    int month26;
    int day26;
    int hour26;
    WeatherType weather26;
    //----------- 27 точка-------------
    float list_27_main_temp = 0;
    int month27;
    int day27;
    int hour27;
    WeatherType weather27;
    //----------- 28 точка-------------
    float list_28_main_temp = 0;
    int month28;
    int day28;
    int hour28;
    WeatherType weather28;
    //----------- 29 точка-------------
    float list_29_main_temp = 0;
    int month29;
    int day29;
    int hour29;
    WeatherType weather29;
    //----------- 30 точка-------------
    float list_30_main_temp = 0;
    int month30;
    int day30;
    int hour30;
    WeatherType weather30;
    //----------- 31 точка-------------
    float list_31_main_temp = 0;;
    int month31;
    int day31;
    int hour31;
    WeatherType weather31;
    //----------- 32 точка-------------
    float list_32_main_temp = 0;
    int month32;
    int day32;
    int hour32;
    WeatherType weather32;
    //----------- 33 точка-------------
    float list_33_main_temp = 0;
    int month33;
    int day33;
    int hour33;
    WeatherType weather33;
    //----------- 34 точка-------------
    float list_34_main_temp = 0;
    int month34;
    int day34;
    int hour34;
    WeatherType weather34;
    //----------- 35 точка-------------
    float list_35_main_temp = 0;
    int month35;
    int day35;
    int hour35;
    WeatherType weather35;
    //----------- 36 точка-------------
    float list_36_main_temp = 0;
    int month36;
    int day36;
    int hour36;
    WeatherType weather36;
    //----------- 37 точка-------------
    float list_37_main_temp = 0;
    int month37;
    int day37;
    int hour37;
    WeatherType weather37;
    //----------- 38 точка-------------
    float list_38_main_temp = 0;
    int month38;
    int day38;
    int hour38;
    WeatherType weather38;
    //----------- 39 точка-------------
    float list_39_main_temp = 0;
    int month39;
    int day39;
    int hour39;
    WeatherType weather39;*/


    public:
     DataResiver(InternetForecast& _client1);
     ForecastPoint forecastarray[46]; // массив структур хранящих точки прогноза с параметрами для отображения на дисплее
     int dataForecast[6] {0};                      // массив хранящий даты дней и их количество полученное с сайта openweathermap
     int iteracia = 0;                     
     WeatherType parseWeatherType(const char* weather);
     void parseForecastFromJsonDoc(JsonDocument& doc, ForecastPoint* forecastarray);// парсинг данных из JSON файла полученного с сервера погоды
    
     
     
     
};