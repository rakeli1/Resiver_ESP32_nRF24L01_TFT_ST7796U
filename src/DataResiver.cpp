#include "DataResiver.h"
#include "ArduinoJson.h"

DataResiver::DataResiver(InternetClient& _client1) : client1(_client1)
{
 
}



void DataResiver::parseFromJsonDoc(StaticJsonDocument<1024>&doc)  // аргумент StaticJsonDocument<1024>&doc возвращается с помощью
{                                                                 // метода client1.getDoc() екземпляра класса client1 класса InternetClient
    JsonArray list = doc["list"]; 

 // ------------Данные обьекта 0-------------- 
  JsonObject list_0 = list[0];
  JsonObject list_0_main = list_0["main"];
  list_0_main_temp = list_0_main["temp"];                                          // температура 1-ой точки
  JsonObject list_0_weather_0 = list_0["weather"][0];                             
  const char* list_0_weather_main = list_0_weather_0["main"];                      // осадки 1-ой точки
  const char* list_0_dt_txt = list_0["dt_txt"];                                    // дата-время 1-ой точки
  sscanf(list_0_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month0, &day0, &hour0);
  weather0 = parseWeatherType(list_0_weather_main);
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  //------------данные обьекта1-----------------
  JsonObject list_1 = list[1];
  JsonObject list_1_main = list_1["main"];
  list_1_main_temp = list_1_main["temp"];                                           // температура 2-ой точки
  JsonObject list_1_weather_0 = list_1["weather"][0];      
  const char* list_1_weather_0_main = list_1_weather_0["main"];                    // осадки 2-ой точки
  const char* list_1_dt_txt = list_1["dt_txt"];                                    // дата-время 2-ой точки
  sscanf(list_1_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month1, &day1, &hour1);
  weather1 = parseWeatherType(list_1_weather_0_main);

  //------------данные обьекта2------------------
  JsonObject list_2 = list[2];
  JsonObject list_2_main = list_2["main"];
  list_2_main_temp = list_2_main["temp"];                                            // температура 3-ей точки
  JsonObject list_2_weather_0 = list_2["weather"][0];
  const char* list_2_weather_0_main = list_2_weather_0["main"];                      // осадки 3-ей точки
  const char* list_2_dt_txt = list_2["dt_txt"];                                      // дата-время 3-ей точки
  sscanf(list_2_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month2, &day2, &hour2);
  weather2 = parseWeatherType(list_2_weather_0_main);

  //------------данные обьекта3------------------
  JsonObject list_3 = list[3];
  JsonObject list_3_main = list_3["main"];
  list_3_main_temp = list_3_main["temp"];                                            // температура 4-ой точки
  JsonObject list_3_weather_0 = list_3["weather"][0];
  const char* list_3_weather_0_main = list_3_weather_0["main"];                      // осадки 4-ой точки
  const char* list_3_dt_txt = list_3["dt_txt"];                                      // дата-время 4-ой точки
  sscanf(list_3_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month3, &day3, &hour3);
  weather3 = parseWeatherType(list_3_weather_0_main);

  //------------данные обьекта4------------------
  JsonObject list_4 = list[4];
  JsonObject list_4_main = list_4["main"];
  list_4_main_temp = list_4_main["temp"];                                     // температура 5-ой точки
  JsonObject list_4_weather_0 = list_4["weather"][0];
  const char* list_4_weather_0_main = list_4_weather_0["main"];                      // осадки 5-ой точки
  const char* list_4_dt_txt = list_4["dt_txt"];                                      // дата-время 5-ой точки
  sscanf(list_4_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month4, &day4, &hour4);
  weather4 = parseWeatherType(list_4_weather_0_main);

  //------------данные обьекта5------------------------------------------------------------------------------
  JsonObject list_5 = list[5];
  JsonObject list_5_main = list_5["main"];
  list_5_main_temp = list_5_main["temp"];                                     // температура 6-ой точки
  JsonObject list_5_weather_0 = list_5["weather"][0];
  const char* list_5_weather_0_main = list_5_weather_0["main"];                      // осадки 6-ой точки
  const char* list_5_dt_txt = list_5["dt_txt"];                                      // дата-время 6-ой точки
  sscanf(list_5_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month5, &day5, &hour5);
  weather5 = parseWeatherType(list_5_weather_0_main);

  //------------данные обьекта6-------------------------------------------------------------------------------
  JsonObject list_6 = list[6];
  JsonObject list_6_main = list_6["main"];
  list_6_main_temp = list_6_main["temp"];                                     // температура 7-ой точки
  JsonObject list_6_weather_0 = list_6["weather"][0];
  const char* list_6_weather_0_main = list_6_weather_0["main"];                      // осадки 7-ой точки
  const char* list_6_dt_txt = list_6["dt_txt"];                                      // дата-время 7-ой точки
  sscanf(list_6_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month6, &day6, &hour6);
  weather6 = parseWeatherType(list_6_weather_0_main);


  //------------данные обьекта7-------------------------------------------------------------------------------
  JsonObject list_7 = list[7];
  JsonObject list_7_main = list_7["main"];
  list_7_main_temp = list_7_main["temp"];                                     // температура 8-ой точки
  JsonObject list_7_weather_0 = list_7["weather"][0];
  const char* list_7_weather_0_main = list_7_weather_0["main"];                      // осадки 8-ой точки
  const char* list_7_dt_txt = list_7["dt_txt"];                                      // дата-время 8-ой точки
  sscanf(list_7_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month7, &day7, &hour7);
  weather7 = parseWeatherType(list_7_weather_0_main);


  //------------данные обьекта8-------------------------------------------------------------------------------
  JsonObject list_8 = list[8];
  JsonObject list_8_main = list_8["main"];
  list_8_main_temp = list_8_main["temp"];                                     // температура 9-ой точки
  JsonObject list_8_weather_0 = list_8["weather"][0];
  const char* list_8_weather_0_main = list_8_weather_0["main"];                      // осадки 9-ой точки
  const char* list_8_dt_txt = list_8["dt_txt"];                                      // дата-время 9-ой точки
  sscanf(list_8_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month8, &day8, &hour8);
  weather8 = parseWeatherType(list_8_weather_0_main);

  //------------данные обьекта9-------------------------------------------------------------------------------
  JsonObject list_9 = list[9];
  JsonObject list_9_main = list_9["main"];
  list_9_main_temp = list_9_main["temp"];                                     // температура 10-ой точки
  JsonObject list_9_weather_0 = list_9["weather"][0];
  const char* list_9_weather_0_main = list_9_weather_0["main"];                      // осадки 10-ой точки
  const char* list_9_dt_txt = list_9["dt_txt"];                                      // дата-время 10-ой точки
  sscanf(list_9_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month9, &day9, &hour9);
  weather9 = parseWeatherType(list_9_weather_0_main);

  //------------данные обьекта10-------------------------------------------------------------------------------
  JsonObject list_10 = list[10];
  JsonObject list_10_main = list_10["main"];
  list_10_main_temp = list_10_main["temp"];                                     // температура 11-ой точки
  JsonObject list_10_weather_0 = list_10["weather"][0];
  const char* list_10_weather_0_main = list_10_weather_0["main"];                      // осадки 11-ой точки
  const char* list_10_dt_txt = list_10["dt_txt"];                                      // дата-время 11-ой точки
  sscanf(list_10_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month10, &day10, &hour10);
  weather10 = parseWeatherType(list_10_weather_0_main);

  //------------данные обьекта11-------------------------------------------------------------------------------
  JsonObject list_11 = list[11];
  JsonObject list_11_main = list_11["main"];
  list_11_main_temp = list_11_main["temp"];                                     // температура 12-ой точки
  JsonObject list_11_weather_0 = list_11["weather"][0];
  const char* list_11_weather_0_main = list_11_weather_0["main"];                      // осадки 12-ой точки
  const char* list_11_dt_txt = list_11["dt_txt"];                                      // дата-время 12-ой точки
  sscanf(list_11_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month11, &day11, &hour11);
  weather11 = parseWeatherType(list_11_weather_0_main);

  //------------данные обьекта12-------------------------------------------------------------------------------
  JsonObject list_12 = list[12];
  JsonObject list_12_main = list_12["main"];
  list_12_main_temp = list_12_main["temp"];                                     // температура 13-ой точки
  JsonObject list_12_weather_0 = list_12["weather"][0];
  const char* list_12_weather_0_main = list_12_weather_0["main"];                      // осадки 13-ой точки
  const char* list_12_dt_txt = list_12["dt_txt"];                                      // дата-время 13-ой точки
  sscanf(list_12_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month12, &day12, &hour12);
  weather12 = parseWeatherType(list_12_weather_0_main);

  //------------данные обьекта13-------------------------------------------------------------------------------
  JsonObject list_13 = list[13];
  JsonObject list_13_main = list_13["main"];
  list_13_main_temp = list_13_main["temp"];                                     // температура 14-ой точки
  JsonObject list_13_weather_0 = list_13["weather"][0];
  const char* list_13_weather_0_main = list_13_weather_0["main"];                      // осадки 14-ой точки
  const char* list_13_dt_txt = list_13["dt_txt"];                                      // дата-время 14-ой точки
  sscanf(list_13_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month13, &day13, &hour13);
  weather13 = parseWeatherType(list_13_weather_0_main);

  //------------данные обьекта14-------------------------------------------------------------------------------
  JsonObject list_14 = list[14];
  JsonObject list_14_main = list_14["main"];
  list_14_main_temp = list_14_main["temp"];                                     // температура 15-ой точки
  JsonObject list_14_weather_0 = list_14["weather"][0];
  const char* list_14_weather_0_main = list_14_weather_0["main"];                      // осадки 15-ой точки
  const char* list_14_dt_txt = list_14["dt_txt"];                                      // дата-время 15-ой точки
  sscanf(list_14_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month14, &day14, &hour14);
  weather14 = parseWeatherType(list_14_weather_0_main);

  //------------данные обьекта15-------------------------------------------------------------------------------
  JsonObject list_15 = list[15];
  JsonObject list_15_main = list_15["main"];
  list_15_main_temp = list_15_main["temp"];                                     // температура 16-ой точки
  JsonObject list_15_weather_0 = list_15["weather"][0];
  const char* list_15_weather_0_main = list_15_weather_0["main"];                      // осадки 16-ой точки
  const char* list_15_dt_txt = list_15["dt_txt"];                                      // дата-время 16-ой точки
  sscanf(list_15_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month15, &day15, &hour15);
  weather15 = parseWeatherType(list_15_weather_0_main);

  //------------данные обьекта16-------------------------------------------------------------------------------
  JsonObject list_16 = list[16];
  JsonObject list_16_main = list_16["main"];
  list_16_main_temp = list_16_main["temp"];                                     // температура 17-ой точки
  JsonObject list_16_weather_0 = list_16["weather"][0];
  const char* list_16_weather_0_main = list_16_weather_0["main"];                      // осадки 17-ой точки
  const char* list_16_dt_txt = list_16["dt_txt"];                                      // дата-время 17-ой точки
  sscanf(list_16_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month16, &day16, &hour16);
  weather16 = parseWeatherType(list_16_weather_0_main);

  //------------данные обьекта17-------------------------------------------------------------------------------
  JsonObject list_17 = list[17];
  JsonObject list_17_main = list_17["main"];
  list_17_main_temp = list_17_main["temp"];                                     // температура 18-ой точки
  JsonObject list_17_weather_0 = list_17["weather"][0];
  const char* list_17_weather_0_main = list_17_weather_0["main"];                      // осадки 18-ой точки
  const char* list_17_dt_txt = list_17["dt_txt"];                                      // дата-время 18-ой точки
  sscanf(list_17_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month17, &day17, &hour17);
  weather17 = parseWeatherType(list_17_weather_0_main);

  //------------данные обьекта18-------------------------------------------------------------------------------
  JsonObject list_18 = list[18];
  JsonObject list_18_main = list_18["main"];
  list_18_main_temp = list_18_main["temp"];                                     // температура 18-ой точки
  JsonObject list_18_weather_0 = list_18["weather"][0];
  const char* list_18_weather_0_main = list_18_weather_0["main"];                      // осадки 18-ой точки
  const char* list_18_dt_txt = list_18["dt_txt"];                                      // дата-время 18-ой точки
  sscanf(list_18_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month18, &day18, &hour18);
  weather18 = parseWeatherType(list_18_weather_0_main);

  //------------данные обьекта19-------------------------------------------------------------------------------
  JsonObject list_19 = list[19];
  JsonObject list_19_main = list_19["main"];
  list_19_main_temp = list_19_main["temp"];                                     // температура 20-ой точки
  JsonObject list_19_weather_0 = list_19["weather"][0];
  const char* list_19_weather_0_main = list_19_weather_0["main"];                      // осадки 20-ой точки
  const char* list_19_dt_txt = list_19["dt_txt"];                                      // дата-время 20-ой точки
  sscanf(list_19_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month19, &day19, &hour19);
  weather19 = parseWeatherType(list_19_weather_0_main);

  //------------данные обьекта20-------------------------------------------------------------------------------
  JsonObject list_20 = list[20];
  JsonObject list_20_main = list_20["main"];
  list_20_main_temp = list_20_main["temp"];                                     // температура 21-ой точки
  JsonObject list_20_weather_0 = list_20["weather"][0];
  const char* list_20_weather_0_main = list_20_weather_0["main"];                      // осадки 21-ой точки
  const char* list_20_dt_txt = list_20["dt_txt"];                                      // дата-время 21-ой точки
  sscanf(list_20_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month20, &day20, &hour20);
  weather20 = parseWeatherType(list_20_weather_0_main);

  //------------данные обьекта21-------------------------------------------------------------------------------
  JsonObject list_21 = list[21];
  JsonObject list_21_main = list_21["main"];
  list_21_main_temp = list_21_main["temp"];                                     // температура 22-ой точки
  JsonObject list_21_weather_0 = list_21["weather"][0];
  const char* list_21_weather_0_main = list_21_weather_0["main"];                      // осадки 22-ой точки
  const char* list_21_dt_txt = list_21["dt_txt"];                                      // дата-время 22-ой точки
  sscanf(list_21_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month21, &day21, &hour21);
  weather21 = parseWeatherType(list_21_weather_0_main);

  //------------данные обьекта22-------------------------------------------------------------------------------
  JsonObject list_22 = list[22];
  JsonObject list_22_main = list_22["main"];
  list_22_main_temp = list_22_main["temp"];                                     // температура 23-ой точки
  JsonObject list_22_weather_0 = list_22["weather"][0];
  const char* list_22_weather_0_main = list_22_weather_0["main"];                      // осадки 23-ой точки
  const char* list_22_dt_txt = list_22["dt_txt"];                                      // дата-время 23-ой точки
  sscanf(list_22_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month22, &day22, &hour22);
  weather22 = parseWeatherType(list_22_weather_0_main);

  //------------данные обьекта23-------------------------------------------------------------------------------
  JsonObject list_23 = list[23];
  JsonObject list_23_main = list_23["main"];
  list_23_main_temp = list_23_main["temp"];                                     // температура 24-ой точки
  JsonObject list_23_weather_0 = list_23["weather"][0];
  const char* list_23_weather_0_main = list_23_weather_0["main"];                      // осадки 24-ой точки
  const char* list_23_dt_txt = list_23["dt_txt"];                                      // дата-время 24-ой точки
  sscanf(list_23_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month23, &day23, &hour23);
  weather23 = parseWeatherType(list_23_weather_0_main);

  //------------данные обьекта24-------------------------------------------------------------------------------
  JsonObject list_24 = list[24];
  JsonObject list_24_main = list_24["main"];
  list_24_main_temp = list_24_main["temp"];                                     // температура 25-ой точки
  JsonObject list_24_weather_0 = list_24["weather"][0];
  const char* list_24_weather_0_main = list_24_weather_0["main"];                      // осадки 25-ой точки
  const char* list_24_dt_txt = list_24["dt_txt"];                                      // дата-время 25-ой точки
  sscanf(list_24_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month24, &day24, &hour24);
  weather24 = parseWeatherType(list_24_weather_0_main);

   //------------данные обьекта25-------------------------------------------------------------------------------
  JsonObject list_25 = list[25];
  JsonObject list_25_main = list_25["main"];
  list_25_main_temp = list_25_main["temp"];                                     // температура 26-ой точки
  JsonObject list_25_weather_0 = list_25["weather"][0];
  const char* list_25_weather_0_main = list_25_weather_0["main"];                      // осадки 26-ой точки
  const char* list_25_dt_txt = list_25["dt_txt"];                                      // дата-время 26-ой точки
  sscanf(list_25_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month25, &day25, &hour25);
  weather25 = parseWeatherType(list_25_weather_0_main);

   //------------данные обьекта26-------------------------------------------------------------------------------
  JsonObject list_26 = list[26];
  JsonObject list_26_main = list_26["main"];
  list_26_main_temp = list_26_main["temp"];                                     // температура 27-ой точки
  JsonObject list_26_weather_0 = list_26["weather"][0];
  const char* list_26_weather_0_main = list_26_weather_0["main"];                      // осадки 27-ой точки
  const char* list_26_dt_txt = list_26["dt_txt"];                                      // дата-время 27-ой точки
  sscanf(list_26_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month26, &day26, &hour26);
  weather26 = parseWeatherType(list_26_weather_0_main);

  //------------данные обьекта27-------------------------------------------------------------------------------
  JsonObject list_27 = list[27];
  JsonObject list_27_main = list_27["main"];
  list_27_main_temp = list_27_main["temp"];                                     // температура 28-ой точки
  JsonObject list_27_weather_0 = list_27["weather"][0];
  const char* list_27_weather_0_main = list_27_weather_0["main"];                      // осадки 28-ой точки
  const char* list_27_dt_txt = list_27["dt_txt"];                                      // дата-время 28-ой точки
  sscanf(list_27_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month27, &day27, &hour27);
  weather27 = parseWeatherType(list_27_weather_0_main);

  //------------данные обьекта28-------------------------------------------------------------------------------
  JsonObject list_28 = list[28];
  JsonObject list_28_main = list_28["main"];
  list_28_main_temp = list_28_main["temp"];                                     // температура 29-ой точки
  JsonObject list_28_weather_0 = list_28["weather"][0];
  const char* list_28_weather_0_main = list_28_weather_0["main"];                      // осадки 29-ой точки
  const char* list_28_dt_txt = list_28["dt_txt"];                                      // дата-время 29-ой точки
  sscanf(list_28_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month28, &day28, &hour28);
  weather28 = parseWeatherType(list_28_weather_0_main);

  //------------данные обьекта29-------------------------------------------------------------------------------
  JsonObject list_29 = list[29];
  JsonObject list_29_main = list_29["main"];
  list_29_main_temp = list_29_main["temp"];                                     // температура 30-ой точки
  JsonObject list_29_weather_0 = list_29["weather"][0];
  const char* list_29_weather_0_main = list_29_weather_0["main"];                      // осадки 30-ой точки
  const char* list_29_dt_txt = list_29["dt_txt"];                                      // дата-время 30-ой точки
  sscanf(list_29_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month29, &day29, &hour29);
  weather29 = parseWeatherType(list_29_weather_0_main);

  //------------данные обьекта30-------------------------------------------------------------------------------
  JsonObject list_30 = list[30];
  JsonObject list_30_main = list_30["main"];
  list_30_main_temp = list_30_main["temp"];                                     // температура 31-ой точки
  JsonObject list_30_weather_0 = list_30["weather"][0];
  const char* list_30_weather_0_main = list_30_weather_0["main"];                      // осадки 31-ой точки
  const char* list_30_dt_txt = list_30["dt_txt"];                                      // дата-время 31-ой точки
  sscanf(list_30_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month30, &day30, &hour30);
  weather30 = parseWeatherType(list_30_weather_0_main);

  //------------данные обьекта31-------------------------------------------------------------------------------
  JsonObject list_31 = list[31];
  JsonObject list_31_main = list_31["main"];
  list_31_main_temp = list_31_main["temp"];                                     // температура 32-ой точки
  JsonObject list_31_weather_0 = list_31["weather"][0];
  const char* list_31_weather_0_main = list_31_weather_0["main"];                      // осадки 32-ой точки
  const char* list_31_dt_txt = list_31["dt_txt"];                                      // дата-время 32-ой точки
  sscanf(list_31_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month31, &day31, &hour31);
  weather31 = parseWeatherType(list_31_weather_0_main);

  //------------данные обьекта32-------------------------------------------------------------------------------
  JsonObject list_32 = list[32];
  JsonObject list_32_main = list_32["main"];
  list_32_main_temp = list_32_main["temp"];                                     // температура 33-ой точки
  JsonObject list_32_weather_0 = list_32["weather"][0];
  const char* list_32_weather_0_main = list_32_weather_0["main"];                      // осадки 33-ой точки
  const char* list_32_dt_txt = list_32["dt_txt"];                                      // дата-время 33-ой точки
  sscanf(list_32_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month32, &day32, &hour32);
  weather32 = parseWeatherType(list_32_weather_0_main);
  
   //------------данные обьекта33-------------------------------------------------------------------------------
  JsonObject list_33 = list[33];
  JsonObject list_33_main = list_33["main"];
  list_33_main_temp = list_33_main["temp"];                                     // температура 34-ой точки
  JsonObject list_33_weather_0 = list_33["weather"][0];
  const char* list_33_weather_0_main = list_33_weather_0["main"];                      // осадки 34-ой точки
  const char* list_33_dt_txt = list_33["dt_txt"];                                      // дата-время 34-ой точки
  sscanf(list_33_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month33, &day33, &hour33);
  weather33 = parseWeatherType(list_33_weather_0_main);

  //------------данные обьекта34-------------------------------------------------------------------------------
  JsonObject list_34 = list[34];
  JsonObject list_34_main = list_34["main"];
  list_34_main_temp = list_34_main["temp"];                                     // температура 35-ой точки
  JsonObject list_34_weather_0 = list_34["weather"][0];
  const char* list_34_weather_0_main = list_34_weather_0["main"];                      // осадки 35-ой точки
  const char* list_34_dt_txt = list_34["dt_txt"];                                      // дата-время 35-ой точки
  sscanf(list_34_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month34, &day34, &hour34);
  weather34 = parseWeatherType(list_34_weather_0_main);

  //------------данные обьекта35-------------------------------------------------------------------------------
  JsonObject list_35 = list[35];
  JsonObject list_35_main = list_35["main"];
  list_35_main_temp = list_35_main["temp"];                                     // температура 36-ой точки
  JsonObject list_35_weather_0 = list_35["weather"][0];
  const char* list_35_weather_0_main = list_35_weather_0["main"];                      // осадки 36-ой точки
  const char* list_35_dt_txt = list_35["dt_txt"];                                      // дата-время 36-ой точки
  sscanf(list_35_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month35, &day35, &hour35);
  weather35 = parseWeatherType(list_35_weather_0_main);

  //------------данные обьекта36-------------------------------------------------------------------------------
  JsonObject list_36 = list[36];
  JsonObject list_36_main = list_36["main"];
  list_36_main_temp = list_36_main["temp"];                                     // температура 37-ой точки
  JsonObject list_36_weather_0 = list_36["weather"][0];
  const char* list_36_weather_0_main = list_36_weather_0["main"];                      // осадки 37-ой точки
  const char* list_36_dt_txt = list_36["dt_txt"];                                      // дата-время 37-ой точки
  sscanf(list_36_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month36, &day36, &hour36);
  weather36 = parseWeatherType(list_36_weather_0_main);

  //------------данные обьекта37-------------------------------------------------------------------------------
  JsonObject list_37 = list[37];
  JsonObject list_37_main = list_37["main"];
  list_37_main_temp = list_37_main["temp"];                                     // температура 38-ой точки
  JsonObject list_37_weather_0 = list_37["weather"][0];
  const char* list_37_weather_0_main = list_37_weather_0["main"];                      // осадки 38-ой точки
  const char* list_37_dt_txt = list_37["dt_txt"];                                      // дата-время 38-ой точки
  sscanf(list_37_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month37, &day37, &hour37);
  weather37 = parseWeatherType(list_37_weather_0_main);

  //------------данные обьекта38-------------------------------------------------------------------------------
  JsonObject list_38 = list[38];
  JsonObject list_38_main = list_38["main"];
  list_38_main_temp = list_38_main["temp"];                                     // температура 39-ой точки
  JsonObject list_38_weather_0 = list_38["weather"][0];
  const char* list_38_weather_0_main = list_38_weather_0["main"];                      // осадки 39-ой точки
  const char* list_38_dt_txt = list_38["dt_txt"];                                      // дата-время 39-ой точки
  sscanf(list_38_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month38, &day38, &hour38);
  weather38 = parseWeatherType(list_38_weather_0_main);

  //------------данные обьекта39-------------------------------------------------------------------------------
  JsonObject list_39 = list[39];
  JsonObject list_39_main = list_39["main"];
  list_39_main_temp = list_39_main["temp"];                                            // температура 40-ой точки
  JsonObject list_39_weather_0 = list_39["weather"][0];
  const char* list_39_weather_0_main = list_39_weather_0["main"];                      // осадки 40-ой точки
  const char* list_39_dt_txt = list_39["dt_txt"];                                      // дата-время 40-ой точки
  sscanf(list_39_dt_txt, "%*d-%d-%d %d:%*d-%*d", &month39, &day39, &hour39);
  weather39 = parseWeatherType(list_39_weather_0_main);
}