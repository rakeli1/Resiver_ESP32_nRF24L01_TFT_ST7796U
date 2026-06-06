#include "LocationPage.h"


LocationPage::LocationPage(TFT_eSPI& _tft, PageManager& _manager, uint16_t &_tX, uint16_t &_tY) :
    tft(_tft), manager(_manager), tX(_tX), tY(_tY), sprInput(&_tft), ok_Long(410, 175, 60, 30, TFT_RED, true, true),
    ok_Lat(410, 135, 60, 30, TFT_RED, true, true), btnext_Location(420, 270, 60, 50, TFT_RED, true, true)
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
       tft.drawString("start", 330, 285);
       tft.drawString("input", 330, 305);
       tft.drawString("enter", 440, 190);
       tft.drawString("enter", 440, 150);
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
      tft.drawString("Enter your LATITUDE and LONGITUDE", 240, 20);
      tft.drawString("for an accurate weather forecast!!!", 240, 50);
      tft.drawString("For start input press \"start input\"", 240, 80);
      tft.drawString("XX.XXXX", 225, 115);
     // tft.drawString("format", 60, 105);
      tft.drawString("LATITUDE", 80, 155);
      tft.drawString("LONGITUDE", 92, 195);
      tft.drawRect(175, 135, 100, 30, TFT_RED);
      tft.drawRect(175, 175, 100, 30,TFT_RED);
      tft.drawRect(295, 135, 100, 30, TFT_RED);
      tft.drawRect(295, 175, 100, 30,TFT_RED);
      tft.setTextFont(1);
      tft.setTextSize(2);
      tft.drawString("coordinat", 348, 121);
      tft.drawString("Current", 348, 104);
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

      
      update();

      if(stateLoc != prevstateLoc)
      {
        onEnterState();
        prevstateLoc = stateLoc;
      }
      //Serial.println(lat, 4);
      //Serial.println(lon, 4);
    }

    void LocationPage::addChar(char c) // добавление символа
    {
     if(inputBufer.length() < 7)
     {
      inputBufer += c;
     }
    }

    void LocationPage::removeChar()  // удаление символа
  {
    if(inputBufer.length() > 0)
     {
        inputBufer.remove(inputBufer.length() - 1);
     }
  }

    void LocationPage::handleTouchLokKbrd()
    {
       if(tX  >= 0 && tX <= 60 && tY >= 220 && tY <= 270) 
       {
         addChar('0');
       }
       if(tX  >= 60 && tX <= 120 && tY >= 220 && tY <= 270)
       {
         addChar('1');
       }
       if(tX  >= 120 && tX <= 180 && tY >= 220 && tY <= 270)
       {
         addChar('2');
       }
       if(tX  >= 180 && tX <= 240 && tY >= 220 && tY <= 270)
       {
         addChar('3');
       }
       if(tX  >= 240 && tX <= 300 && tY >= 220 && tY <= 270)
       {
         addChar('4');
       }
       if(tX  >= 300 && tX <= 360 && tY >= 220 && tY <= 270)
       {
         addChar('5');
       }
       if(tX  >= 360 && tX <= 420 && tY >= 220 && tY <= 270)
       {
         addChar('6');
       }
       if(tX  >= 420 && tX <= 480 && tY >= 220 && tY <= 270)
       {
         addChar('7');
       }
       if(tX  >= 0 && tX <= 60 && tY >= 270 && tY <= 320)
       {
         addChar('8');
       }
       if(tX  >= 60 && tX <= 120 && tY >= 270 && tY <= 320)
       {
         addChar('9');
       }
       if(tX  >= 120 && tX <= 180 && tY >= 270 && tY <= 320)
       {
         addChar('.');
       }
       if(tX  >= 180 && tX <= 240 && tY >= 270 && tY <= 320)
       {
         removeChar();
       }
       if(tX >= 300 && tX <= 360 && tY >= 270 && tY <= 320)
       {
         startInput = true;
         Serial.println("PRESSSEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE");
       }
       if(ok_Lat.isTouched())
       {
         stateLoc = INPUTLON;
       }
       if(ok_Long.isTouched())
       {
         stateLoc = DONEPROCESSING;
       }
       

    }

    void LocationPage::update()
    {
      handleTouchLokKbrd();
      switch(stateLoc)
      {
       case NEITRAL :

        if(startInput)
        {
         stateLoc = INPUTLAT;

        }else
        {
         break;
        }
       break;
       
       case INPUTLAT :
        sprInput.setTextDatum(MC_DATUM);
        sprInput.setTextSize(2);
        sprInput.fillSprite(TFT_WHITE);
        sprInput.drawString(inputBufer, 50, 15);
        
        sprInput.pushSprite(175, 135);
        

       break;

       case INPUTLON :
       
          
        sprInput.setTextDatum(MC_DATUM);           // отрисовка екрана LON
        sprInput.setTextSize(2);                   // отрисовка екрана LON
        sprInput.fillSprite(TFT_RED);              // отрисовка екрана LON
        sprInput.drawString(inputBufer, 50, 15);   // отрисовка екрана LON
        sprInput.pushSprite(175, 175);

       break;
       
       case DONEPROCESSING :
       //stateLoc = NEITRAL;

       break;

      
      }
    }

    void LocationPage::onEnterState()
    {
      switch(stateLoc)
      {
        case NEITRAL :
        pref.begin("settings", false);
        if(pref.getInt("valuecord", 0) == 1)
        {
        pref.putFloat("lat", lat);
        pref.putFloat("lon", lon);
        }
        buferLat = String(pref.getFloat("lat", 0.0f));
        buferLon = String(pref.getFloat("lon", 0.0f));
        tft.setTextFont(1);
        tft.setTextSize(2);
        tft.setTextColor(TFT_BLACK);
        tft.setTextDatum(MC_DATUM);
        tft.drawString(buferLat, 345, 150);
        tft.drawString(buferLon, 345, 190);

        //тут логика вывода на дисплей current coordinat(Latitude and Longitude) from EEPROM 
        break;

        case INPUTLAT :

        sprInput.createSprite(100, 30);
        

        break;

        case INPUTLON :
        buferLat = inputBufer;
        lat = buferLat.toFloat(); // значение которое будет сохранятся в еепром (lat)
        inputBufer = "";
        tft.setTextDatum(MC_DATUM);
        tft.setTextColor(TFT_BLACK, TFT_DARKGREY);
        tft.drawString(buferLat, 345, 150);
        
        sprInput.deleteSprite();
        tft.fillRect(175, 135, 100, 30, TFT_DARKGREY);
        tft.drawRect(175, 135, 100, 30, TFT_RED);

        sprInput.createSprite(100, 30);
        

         break;

         case DONEPROCESSING :
         buferLon = inputBufer;
         lon = buferLon.toFloat(); // значение которое будет сохранятся в еепром (lon)
         tft.setTextDatum(MC_DATUM);
         tft.setTextColor(TFT_BLACK, TFT_DARKGREY);
         tft.drawString(buferLon, 345, 190);
         inputBufer ="";
         sprInput.deleteSprite();
         tft.fillRect(175, 175, 100, 30, TFT_DARKGREY);
         tft.drawRect(175, 175, 100, 30, TFT_RED);
         stateLoc = NEITRAL;
         prevstateLoc = DONEPROCESSING;
         startInput = false;
         pref.putFloat("lat", lat);
         pref.putFloat("lon", lon);

         valueInpytCoord = pref.getInt("valuecord", 0);
         valueInpytCoord++;
         pref.putInt("valuecord", valueInpytCoord);
         pref.end();
          // Это значение надо заносить в еепром
         Serial.println(valueInpytCoord);
         break;
        

      }
    } 