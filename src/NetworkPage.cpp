#include "NetworkPage.h"



NetworkPage::NetworkPage(TFT_eSPI &_tft, PageManager &_manager, uint16_t &_tX, uint16_t &_tY) : tft(_tft),
                          sprEnter(&_tft), manager(_manager), tX(_tX), tY(_tY)
{}

void NetworkPage::drawVline(int32_t x0, int32_t y0, int32_t visota, int32_t color, int repit)
{
   for(int i = 0; i < repit; i++)
 {
  tft.drawFastVLine(x0 + i, y0, visota, color);
 }
}


void NetworkPage::drawHLine(int32_t x0, int32_t y0, int32_t chirina, int32_t color, int repit)
{
   for(int i = 0; i < repit; i++)
 {
  tft.drawFastHLine(x0, y0 + i, chirina, color);
 }
} 

void NetworkPage::drawStatic()
{
   for(int i = 1; i < 8; i++)
    {
      tft.drawFastHLine(0, (i * 40), 480, TFT_WHITE);
    }

    for(int y = 1; y < 12; y++)
    { 
      if(y == 5 || y == 6 || y == 7)
      {
         tft.drawFastVLine((y * 40), 40, 240, TFT_WHITE);
      }
      if(y != 5 && y != 6 && y != 7)
      {
      tft.drawFastVLine((y * 40), 40, 280, TFT_WHITE );
      }
    }
}

void NetworkPage::addChar(char c) // добавление символа
  {
    if(inputBufer.length() < 64)
    {
      inputBufer += c;
    }
  }

   void NetworkPage::removeChar()  // удаление символа
  {
    if(inputBufer.length() > 0)
     {
        inputBufer.remove(inputBufer.length() - 1);
     }
  }




void NetworkPage::drawKeyboard()
{
  for(int i = 0; i < 64; i++)
    {
       tft.setTextFont(1);
       tft.setTextSize(2);
       char c = shiftstate ? key[i].upper : key[i].lower;
       tft.setTextDatum(MC_DATUM);
       tft.drawString(String(c), key[i].x, key[i].y);
    }
    
       tft.setTextFont(1);
       tft.setTextSize(2);
       // клавиша SPACE//
       tft.drawString("SPACE", 240, 300);
       // клавиша SHIFT //
       tft.drawString("Sh", 20, 300);
       // клавиша BKSPS
       tft.drawString("Bkp", 420, 300);
       // клавиша EXIT
       tft.drawString("Ext", 460, 300);
       // клавиша OK
       tft.drawString("Ok", 60, 300);
}

void NetworkPage::handleTouchKeyBoard()
{
  for(int i = 0; i < 64; i++)
 {
  if(tX > (key[i].x - 20) && tX < (key[i].x + 20) && tY > (key[i].y - 20) && tY < (key[i].y + 20))
  {
    char c = shiftstate ? key[i].upper : key[i].lower;
    inputBufer += c;
  }

 }

  if(tX > 0 && tX < 40 && tY > 280 && tY < 320)
    {
      shiftstate = !shiftstate;
    }else if(tX > 40 && tX < 80 && tY > 280 && tY < 320)
    {
      passwordOk = true;
    }else if(tX > 400 && tX < 440 && tY > 280 && tY < 320)
    {
      removeChar();
    }else if(tX > 160 && tX < 320 && tY > 280 && tY < 320)
    {
      addChar(' ');
    }
}

void NetworkPage::updateDinamic()
{

}