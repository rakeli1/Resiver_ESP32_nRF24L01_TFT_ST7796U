#pragma once
#include "Page.h"
#include "Button.h"
#include "TFT_eSPI.h"
#include "PageManager.h"
#include "NetworkPage.h"
#include "LocationPage.h"

class LocationPage;
class NetworkPage;
extern PageManager manager;
extern NetworkPage networkpage;
extern LocationPage locationpage;

class SettingPage : public Page
{  
   private:
     Button btn_exit;
     Button btn_network;
     Button btn_location;
     TFT_eSPI& tft;
     
    

   public:
    SettingPage(TFT_eSPI& _tft );
    void set_drawVline(int32_t x0, int32_t y0, int32_t visota, int32_t color, int repit);
    void set_drawHLine(int32_t x0, int32_t y0, int32_t chirina, int32_t color, int repit);

    void drawStatic() override;
    void updateDinamic() override;

};