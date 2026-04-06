
#include "FileServises.h"

void drawKeyBoardLowRegistr()
  {
    for(int i = 1; i < 8; i++)
    {
      tft.drawFastHLine(0, (i * 40), 480, TFT_WHITE);
    }

    tft.setTextFont(2);
    tft.setTextColor(TFT_WHITE);
    tft.setTextDatum(MC_DATUM);
    tft.drawString("a", 20, 60);  tft.drawString("g", 260, 60);
    tft.drawString("b", 60, 60); tft.drawString("h", 300, 60);
    tft.drawString("c", 100, 60); tft.drawString("i", 340, 60);
    tft.drawString("d", 140, 60); tft.drawString("j", 380, 60);
    tft.drawString("e", 180, 60); tft.drawString("k", 420, 60);
    tft.drawString("f", 220, 60); tft.drawString("l", 460, 60);

    tft.drawString("m", 20, 100);  tft.drawString("s", 260, 100);
    tft.drawString("n", 60, 100);  tft.drawString("t", 300, 100);
    tft.drawString("o", 100, 100);  tft.drawString("u", 340, 100);
    tft.drawString("p", 140, 100);  tft.drawString("v", 380, 100);
    tft.drawString("q", 180, 100);  tft.drawString("w", 420, 100);
    tft.drawString("r", 220, 100);  tft.drawString("x", 460, 100);

    tft.drawString("y", 20, 140);  tft.drawString("z", 60, 140);

    //////////////////////// SIMBOLS/////////////////////////

    tft.drawString("1", 100, 140);  tft.drawString("6", 300, 140);      
    tft.drawString("2", 140, 140); tft.drawString("7", 340, 140);
    tft.drawString("3", 180, 140); tft.drawString("8", 380, 140);
    tft.drawString("4", 220, 140); tft.drawString("9", 420, 140);
    tft.drawString("5", 260, 140); tft.drawString("0", 460, 140);

    tft.drawString(".", 20, 180);  tft.drawString("#", 260, 180);
    tft.drawString(",", 60, 180);  tft.drawString("@", 300, 180);
    tft.drawString(":", 100, 180);  tft.drawString("/", 340, 180);
    tft.drawString(";", 140, 180);  tft.drawString("\\", 380, 180);
    tft.drawString("!", 180, 180);  tft.drawString("&", 420, 180);
    tft.drawString("?", 220, 180);  tft.drawString("%", 460, 180);

    
    tft.drawString("=", 20, 220);  tft.drawString("+", 260, 220);
    tft.drawString("_", 60, 220);   tft.drawString("$", 300, 220);
    tft.drawString("-", 100, 220);  tft.drawString("{", 340, 220);
    tft.drawString("(", 140, 220);  tft.drawString("}", 380, 220);
    tft.drawString(")", 180, 220);  tft.drawString("*", 420, 220);
    tft.drawString("\"", 220, 220);  tft.drawString("[", 460, 220);

    tft.drawString("]", 20, 260);  tft.drawString("~", 140, 260);  
    tft.drawString("'", 60, 260);  
    tft.drawString("^", 100, 260);

    tft.drawString("Sh", 20, 300);  tft.drawString("<-", 420, 300);
    tft.drawString("SPACE", 240, 300); 
    tft.fillRect(440, 280, 40, 40, TFT_RED);
    tft.drawString("ext", 460, 300);
    
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

 void drawKeyBoardHiRegistr()
  {
    for(int i = 1; i < 8; i++)
    {
      tft.drawFastHLine(0, (i * 40), 480, TFT_WHITE);
    }

    tft.setTextFont(2);
    tft.setTextColor(TFT_WHITE);
    tft.setTextDatum(MC_DATUM);
    tft.drawString("A", 20, 60);  tft.drawString("G", 260, 60);
    tft.drawString("B", 60, 60); tft.drawString("H", 300, 60);
    tft.drawString("C", 100, 60); tft.drawString("I", 340, 60);
    tft.drawString("D", 140, 60); tft.drawString("J", 380, 60);
    tft.drawString("E", 180, 60); tft.drawString("K", 420, 60);
    tft.drawString("F", 220, 60); tft.drawString("L", 460, 60);

    tft.drawString("M", 20, 100);  tft.drawString("S", 260, 100);
    tft.drawString("N", 60, 100);  tft.drawString("T", 300, 100);
    tft.drawString("O", 100, 100);  tft.drawString("U", 340, 100);
    tft.drawString("P", 140, 100);  tft.drawString("V", 380, 100);
    tft.drawString("Q", 180, 100);  tft.drawString("W", 420, 100);
    tft.drawString("R", 220, 100);  tft.drawString("X", 460, 100);

    tft.drawString("Y", 20, 140);  tft.drawString("Z", 60, 140);

    //////////////////////// SIMBOLS/////////////////////////

    tft.drawString("1", 100, 140);  tft.drawString("6", 300, 140);      
    tft.drawString("2", 140, 140); tft.drawString("7", 340, 140);
    tft.drawString("3", 180, 140); tft.drawString("8", 380, 140);
    tft.drawString("4", 220, 140); tft.drawString("9", 420, 140);
    tft.drawString("5", 260, 140); tft.drawString("0", 460, 140);

    tft.drawString(".", 20, 180);  tft.drawString("#", 260, 180);
    tft.drawString(",", 60, 180);  tft.drawString("@", 300, 180);
    tft.drawString(":", 100, 180);  tft.drawString("/", 340, 180);
    tft.drawString(";", 140, 180);  tft.drawString("\\", 380, 180);
    tft.drawString("!", 180, 180);  tft.drawString("&", 420, 180);
    tft.drawString("?", 220, 180);  tft.drawString("%", 460, 180);

    
    tft.drawString("=", 20, 220);  tft.drawString("+", 260, 220);
    tft.drawString("_", 60, 220);   tft.drawString("$", 300, 220);
    tft.drawString("-", 100, 220);  tft.drawString("{", 340, 220);
    tft.drawString("(", 140, 220);  tft.drawString("}", 380, 220);
    tft.drawString(")", 180, 220);  tft.drawString("*", 420, 220);
    tft.drawString("\"", 220, 220);  tft.drawString("[", 460, 220);

    tft.drawString("]", 20, 260);  tft.drawString("~", 140, 260);  
    tft.drawString("'", 60, 260);  
    tft.drawString("^", 100, 260);

    tft.drawString("Sh", 20, 300);  tft.drawString("<-", 420, 300);
    tft.drawString("SPACE", 240, 300); 
    tft.fillRect(440, 280, 40, 40, TFT_RED);
    tft.drawString("ext", 460, 300);
    
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