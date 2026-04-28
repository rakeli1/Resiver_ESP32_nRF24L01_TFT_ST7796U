#pragma once
#include "Page.h"
#include "TFT_eSPI.h"
#include "FT6336U.h"
#include "PageManager.h"
#include "Button.h"
#include "SettingPage.h"

 class SettingPage;
 extern float latitude;
 extern float longitude;
 extern PageManager manager;
 extern SettingPage settingpage;
 extern uint16_t tX;              
 extern uint16_t tY;

class LocationPage : public Page
{
   private :
   TFT_eSPI &tft;
   PageManager &manager;
   uint16_t &tX;
   uint16_t &tY;
   TFT_eSprite sprLong;
   TFT_eSprite sprLat;
   Button ok_Long;
   Button ok_Lat;
   Button btnext_Location;
   String inputBuferLoc;
   void drawVline(int32_t x0, int32_t y0, int32_t visota, int32_t color, int repit);
   void drawHline(int32_t x0, int32_t y0, int32_t chirina, int32_t color, int repit);
   
   
   

   public :

   LocationPage(TFT_eSPI& _tft, PageManager& _manager, uint16_t &_tX, uint16_t &_tY); 
   void drawLocKeybrd();
   void addChar(char c);
   void handleTouchLokKbrd();
    
    

    
     
   
   void drawStatic() override;
   void updateDinamic() override;
};