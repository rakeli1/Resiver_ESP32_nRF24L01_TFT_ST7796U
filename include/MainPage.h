#pragma once
#include <TFT_eSPI.h>
#include "Page.h"
#include "struct_radioPaket.h"
#include "RadioData.h"


class MainPage : public Page
{
 private:
    TFT_eSPI&   tft;
    struc_radioPaket& sensorData;// структура данных в которую ложит данные класс RadioData
    RadioData& radiodata;

    TFT_eSprite sprTemp;
    TFT_eSprite sprHumidity;
    TFT_eSprite sprPressure;
    TFT_eSprite sprIcon;
    TFT_eSprite sprBaterry;
    TFT_eSprite sprTime;
    TFT_eSprite sprWiFi;
    TFT_eSprite sprData;

    int lastTemp = 0;
    int lastHumidity = 0;
    int lastPressure = 0;
    int lastIconID = 0;
    int lastBaterry = 0;
    int lastData;
    int lastPecent;
    String Time;
    bool lastWiFi = false;

    // dataresiver& data // ссылка на структуру данных, которую беру из класса Datareciver
                         // тут будут все данные 
    public:
    MainPage(TFT_eSPI& display, struc_radioPaket& paket, RadioData& _radiodata);
    void drawStatic() override;
    void updateDinamic() override;

    private:
    void updateTemp();
    void updateHumidity();
    void updatePressure();
    void updateIconWeather(int iconID);
    void updateBaterry();
    void updateTime(String t);
    void updateWiFi(bool connect);
    void updateData(String dateStr);
    void drawVline(int32_t x0, int32_t y0, int32_t visota, int32_t color, int repit);
    void drawHLine(int32_t x0, int32_t y0, int32_t chirina, int32_t color, int repit);  

};