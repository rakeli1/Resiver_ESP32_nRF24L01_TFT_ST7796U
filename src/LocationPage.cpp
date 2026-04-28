#include "LocationPage.h"


LocationPage::LocationPage(TFT_eSPI& _tft, PageManager& _manager, uint16_t &_tX, uint16_t &_tY) :
    tft(_tft), manager(_manager), tX(_tX), tY(_tY), sprLong(&_tft), sprLat(&_tft), ok_Long(410, 165, 60, 30, TFT_RED, true, true),
    ok_Lat(410, 125, 60, 30, TFT_RED, true, true), btnext_Location(420, 270, 60, 50, TFT_RED, true, true)
    {

    }

    void LocationPage::drawVline(int32_t x0, int32_t y0, int32_t visota, int32_t color, int repit)
    {
        for(int i = 0; i < repit; i++)
        {
          tft.drawFastVLine(x0 + i, y0, visota, color);
        }
    }

    void LocationPage::drawHline(int32_t x0, int32_t y0, int32_t chirina, int32_t color, int repit)
    {
      for(int i = 0; i < repit; i++)
      {
        tft.drawFastHLine(x0, y0 + i, chirina, color);
      }
    }


    void LocationPage::drawLocKeybrd()
    {
       drawHline(0, 220, 480, TFT_BLACK, 1);
       drawHline(0, 270, 480, TFT_BLACK, 1);
       for(int i = 1; i < 8; i++)
       {
         drawVline((i * 60), 220, 100, TFT_BLACK, 1);
       }

       tft.setTextDatum(MC_DATUM);
       tft.setTextColor(TFT_BLACK);
       tft.setTextFont(1);
       tft.setTextSize(2);
       tft.drawString("0", 30, 245);
       tft.drawString("1", 90, 245);
       tft.drawString("2", 150, 245);
       tft.drawString("3", 210, 245);
       tft.drawString("4", 270, 245);
       tft.drawString("5", 330, 245);
       tft.drawString("6", 390, 245);
       tft.drawString("7", 450, 245);
       tft.drawString("8", 30, 295);
       tft.drawString("9", 90, 295);
       tft.drawString(".", 150, 295);
       tft.drawString("bksps", 210, 295);
       tft.drawString("enter", 440, 180);
       tft.drawString("enter", 440, 140);
       tft.setTextSize(2);
       tft.drawString("EXIT", 450, 295);
    }

    void LocationPage::drawStatic()
    {
      tft.fillScreen(TFT_DARKGREY);
      tft.setTextDatum(MC_DATUM);
      tft.setTextColor(TFT_BLACK);
      tft.setTextSize(1);
      tft.setTextFont(4);
      tft.drawString("Enter your LATITUDE and LONGITUDE", 240, 30);
      tft.drawString("for an accurate weather forecast!!!", 240, 60);
      tft.drawString("XX.XXXX", 225, 105);
     // tft.drawString("format", 60, 105);
      tft.drawString("LATITUDE", 80, 145);
      tft.drawString("LONGITUDE", 92, 185);
      tft.drawRect(175, 125, 100, 30, TFT_RED);
      tft.drawRect(175, 165, 100, 30,TFT_RED);
      tft.drawRect(295, 125, 100, 30, TFT_RED);
      tft.drawRect(295, 165, 100, 30,TFT_RED);
      tft.setTextFont(1);
      tft.setTextSize(2);
      tft.drawString("coordinat", 348, 111);
      tft.drawString("Current", 348, 94);
      btnext_Location.draw();
      ok_Lat.draw();
      ok_Long.draw();
      drawLocKeybrd();
      
    }

    void LocationPage::updateDinamic()
    {
      if(btnext_Location.isTouched())
      {
        manager.setPage(&settingpage);
        return;
      }
    }

    void LocationPage::addChar(char c) // добавление символа
    {
     if(inputBuferLoc.length() < 7)
     {
      inputBuferLoc += c;
     }
    }

    void handleTouchLokKbrd()
    {
         
    }