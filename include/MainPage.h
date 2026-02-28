#pragma once
#include <TFT_eSPI.h>
#include "Page.h"
#include "struct_radioPaket.h"
#include "RadioData.h"
#include "Button.h"
#include "FT6336U.h"
#include "PageManager.h"
#include "ForecastPage.h"
#include "SettingPage.h"
#include "CurrencyPage.h"
#include "InternetTimeData.h"
#include  "RTClib.h"

extern RTC_DS3231 rtc;

class MainPage : public Page
{
 private:
    TFT_eSPI&   tft;
    struc_radioPaket& sensorData;// структура данных в которую ложит данные класс RadioData
    RadioData& radiodata;
    PageManager& manager;
    Button btn_forecast;
    Button btn_settings;
    Button btn_currencypage;

    TFT_eSprite sprTemp;
    TFT_eSprite sprHumidity;
    TFT_eSprite sprPressure;
    TFT_eSprite sprIcon;
    TFT_eSprite sprBaterry;
    TFT_eSprite sprTimeHour;
    TFT_eSprite sprTimeMinutes;
    TFT_eSprite sprWiFi;
    TFT_eSprite sprDayWeek;
    
    
    public:
    int lastTemp = 0;
    int lastHumidity = 0;
    int lastPressure = 0;
    int lastIconID = 0;
    int lastBaterry = 0;
    int lastData;
    int lastPecent;
    
    bool lastWiFi = false;

    // dataresiver& data // ссылка на структуру данных, которую беру из класса Datareciver
                         // тут будут все данные 
    public:
    MainPage(TFT_eSPI& display, struc_radioPaket& paket, RadioData& _radiodata, PageManager& _manager);
    void displayTime();
    void drawStatic() override;
    void updateDinamic() override;
    int hours = 66;
    int minutes = 88;
    uint8_t dayOfWeek = 0;
    String returnDay(uint8_t dayOfWeek);
    void drawTimeData(int hours, int minutes);
    
    

    private:
    void updateTemp();
    void updateHumidity();
    void updatePressure();
    void updateIconWeather(int iconID);
    void updateBaterry();
    void updateTime();
    void updateWiFi();
    void updateDayWeek();
    void drawVline(int32_t x0, int32_t y0, int32_t visota, int32_t color, int repit);
    void drawHLine(int32_t x0, int32_t y0, int32_t chirina, int32_t color, int repit);  

};