#include "NetworkPage.h"
#include "WiFiManager.h"
#include "PageManager.h"
#include "MainPage.h"

extern SettingPage settingpage;
extern PageManager manager;
extern MainPage mainpage;
//extern WiFiManager wifi;

NetworkPage::NetworkPage(TFT_eSPI &_tft, PageManager &_manager, uint16_t &_tX, uint16_t &_tY) : tft(_tft),
                          sprEnter(&_tft), manager(_manager), tX(_tX), tY(_tY),
                          btnNet_exit(160, 120, 160, 80, TFT_RED, false, false)
{}

void NetworkPage::drawVline(int32_t x0, int32_t y0, int32_t visota, int32_t color, int repit)
{
   for(int i = 0; i < repit; i++)
 {
  tft.drawFastVLine(x0 + i, y0, visota, color);
 }
}

bool NetworkPage::justReleased()  // метод срабатывания тача по отпусканию пальца
{
  static bool wasTouched = false;
  bool isTouched = (gl_touch.read_td_status() == 1);
  bool result = (!isTouched && wasTouched);
  wasTouched = isTouched;
  return result;
}


void NetworkPage::drawHLine(int32_t x0, int32_t y0, int32_t chirina, int32_t color, int repit)
{
   for(int i = 0; i < repit; i++)
 {
  tft.drawFastHLine(x0, y0 + i, chirina, color);
 }
} 

//void NetworkPage::checkTouch();

void NetworkPage::drawStatic()
{  
   Serial.println("S T A T I C");
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

  for(int i = 0; i < 64; i++)
    {  
       tft.setTextFont(1);
       tft.setTextSize(2);
       char c = shiftstate ? key[i].upper : key[i].lower;
       tft.setTextDatum(MC_DATUM);
       tft.setTextColor(TFT_WHITE, TFT_BLACK);
       tft.drawString(String(c), key[i].x, key[i].y);
    }
       //tft.setTextColor(TFT_WHITE);
       //tft.setTextFont(1);
       //tft.setTextSize(2);
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
       //Serial.println("TTTT");
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

void NetworkPage::getTouchXY()
{
   uint16_t x_lib = gl_touch.read_touch1_x();
   uint16_t y_lib = gl_touch.read_touch1_y();

   tX = (480 - y_lib);
   tY = x_lib;
}

void NetworkPage::drawWiFiList()
{
    tft.fillScreen(TFT_BLACK);

    tft.setTextSize(2);
    tft.setCursor(10, 10);
    tft.println("Select WiFi:");

    for(int i = 0; i < networks; i++)
    {
      tft.setCursor(20, 40 + (i * 30));
      tft.print(i + 1);
      tft.print(". ");
      tft.println(ssidList[i]);
    }
}

void NetworkPage::scanWiFi()
{
    tft.fillScreen(TFT_BLACK);
    tft.setTextFont(1);
    tft.setTextSize(2);
   tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setCursor(10, 10);
    tft.println("Scaning WiFi...");
    Serial.println("Start scan");
    networks = WiFi.scanNetworks();

    for(int i = 0; i < networks; i++)
    {
      ssidList[i] = WiFi.SSID(i); 
    }
    
     //drawWiFiList();
     }



void NetworkPage::connectWiFi()
{
     tft.fillScreen(TFT_BLACK);
     tft.setCursor(7, 10);
     tft.println("Enter password:");
     tft.println(selectedSSID);
     
      
       if(gl_touch.read_td_status() == 1)
       {
         getTouchXY();
         delay(100);       // антидребезг
       }
        
        drawKeyboard();
       
        handleTouchKeyBoard();
       tX = -1;           //НЕ УБИРАТЬ!!!!!!!!!!!!!!
       tY = -1;           //НЕ УБИРАТЬ!!!!!!!!!!!!!!!!
        sprEnter.createSprite(280, 25);
        sprEnter.fillSprite(TFT_RED);
        sprEnter.setTextColor(TFT_WHITE);
        sprEnter.setTextFont(1);
        sprEnter.setTextSize(2);
        sprEnter.drawString(inputBufer, 0, 5);
        sprEnter.pushSprite(200, 7);
        
      

     if(WiFi.status() != WL_CONNECTED)
     {
       password = inputBufer; // ввод пароля пока тут потом в блоке if() выше..... 
       //91891518
        WiFi.begin(selectedSSID.c_str(), password.c_str());

       while(WiFi.status() != WL_CONNECTED)
        {
         delay(500);
         tft.print(".");
        }
      }
      
      if(WiFi.status() == WL_CONNECTED)
      {
      if(gl_touch.read_td_status() == 1)
       {
         getTouchXY();
         delay(100);       // антидребезг
       }

      tft.fillScreen(TFT_BLACK);
      tft.setCursor(10, 10);
      tft.setTextFont(1);
      tft.setTextSize(2);
      tft.println("WiFi connected!");
      tft.setCursor(220, 10);
      tft.println(WiFi.localIP());

      btnNet_exit.enable = true;
      btnNet_exit.visible =true;
      btnNet_exit.draw();
      tft.setTextColor(TFT_BLACK);
      tft.setTextDatum(MC_DATUM);
      tft.drawString("EXIT", 240, 160);
      
      


      }
    }

void NetworkPage::updateDinamic()
{

   
  update();
  if(state != prevState) //ДОРАБОТАТЬ ДЛЯ КЛАВИШИ SHIFT ПОДУМАТЬ НАД ЛОГИКОЙ ПЕРЕМЕННОЙ shiftstate
  {
    onEnterState(state);
    prevState = state;
  }

  render(); 

   
  Serial.println("D I N A M I C NETWORKPAGE");
  Serial.println(tX);
  Serial.println(tY);
   
   
}

int NetworkPage::checkTouch()
 { 
    if(gl_touch.read_td_status() == 1)
    {
      getTouchXY();
     for(int i = 0; i < networks; i++)
     {
       int yStart = 40 + (i * 30);
       int yEnd   = yStart + 30;
       if(tY > yStart && tY < yEnd)
      {
        selectedSSID = ssidList[i];
        
        //while(WiFi.status() != WL_CONNECTED)
        //{
          // connectWiFi();
          // Serial.println("Connekting");
        //}
        return i;
      } 
     }
    }else
    {
      tX = -1;
      tY = -1;
      return -1;
    }
    //Serial.println("C H E C K T O U C H");
  }

void NetworkPage::update()
{
  switch(state)
  {
  case WIFI_SCAN :

    scanWiFi();
    if(networks >= 0)
    {
      state = WIFI_LIST;
    }

    
    break;

  case WIFI_LIST :
   selektNetwork = checkTouch();
   if(selektNetwork >= 0) // разработать логику выхода из состояния по выбору сети НАЧАТЬ С ЭТОГО!!!!!
   {
     state = WIFI_PASSWORD;

   }
   break;

   case WIFI_PASSWORD :
     if(gl_touch.read_td_status() == 1)
       {
         getTouchXY();
         delay(100);       // антидребезг
       }
        
        
       
        handleTouchKeyBoard();
       tX = -1;           //НЕ УБИРАТЬ!!!!!!!!!!!!!!
       tY = -1;           //НЕ УБИРАТЬ!!!!!!!!!!!!!!!!

        sprEnter.createSprite(280, 25);
        sprEnter.fillSprite(TFT_RED);
        sprEnter.setTextColor(TFT_WHITE);
        sprEnter.setTextFont(1);
        sprEnter.setTextSize(2);
        sprEnter.drawString(inputBufer, 0, 5);
        sprEnter.pushSprite(200, 7);
        if(passwordOk)
        {
         password = inputBufer;
         state = WIFI_CONNECTING;
        }
   
   break;

   case WIFI_CONNECTING :
   if(WiFi.status() == WL_CONNECTED)
   {
     state = WIFI_RESULT;
   }

   break;

   case WIFI_RESULT :
   if(gl_touch.read_td_status() == 1)
    {
      getTouchXY();
    }else
    {
       tX = -1;
       tY = -1; 
    }
      
      btnNet_exit.enable = true;
      btnNet_exit.visible =true;
   if(btnNet_exit.isTouched())
   {
      manager.setPage(&settingpage);
      return;
   }  

   manager.setPage(&mainpage);

   break;


  
  default:
    break;
  }
}  
  


void NetworkPage::onEnterState(State state)
{
  switch(state)
  {
    case WIFI_SCAN :

    tft.fillScreen(TFT_BLACK);
    tft.setTextFont(1);
    tft.setTextSize(2);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setCursor(10, 10);
    tft.println("Scaning WiFi...");
    
    break;
    
    case WIFI_LIST :
    drawWiFiList();

    break;

   case WIFI_PASSWORD :
     tft.fillScreen(TFT_BLACK);
     tft.setTextColor(TFT_WHITE);
     tft.setTextFont(1);
     tft.setTextSize(2);
     tft.setCursor(7, 10);
     tft.println("Enter password:");
     tft.println(selectedSSID);
     drawKeyboard();
   

    break;

   case  WIFI_CONNECTING :
   WiFi.begin(selectedSSID.c_str(), password.c_str());

   break;

   case WIFI_RESULT :
   tft.fillScreen(TFT_BLACK);
      tft.setCursor(10, 10);
      tft.setTextFont(1);
      tft.setTextSize(2);
      tft.println("WiFi connected!");
      tft.setCursor(220, 10);
      tft.println(WiFi.localIP());

      btnNet_exit.enable = true;
      btnNet_exit.visible =true;
      btnNet_exit.draw();
      tft.setTextColor(TFT_BLACK);
      tft.setTextDatum(MC_DATUM);
      tft.drawString("EXIT", 240, 160);

   break;

  }
     
  
  
}

void NetworkPage::render()    // смена картинки на екране
{
  if(shiftstate != prevShiftstate)  // Смена регистра на клавиатуре
  {
    drawKeyboard();
    prevShiftstate = shiftstate;
  }
}