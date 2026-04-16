#pragma once
#include "Page.h"
#include <TFT_eSPI.h>
#include "FT6336U.h"
#include "PageManager.h"
#include "Button.h"
#include "SettingPage.h"

extern uint16_t tX;
extern uint16_t tY;

class NetworkPage : public Page
{
  private :
  TFT_eSPI &tft;
  TFT_eSprite sprEnter;
  PageManager& manager;

  struct Key
  {
    int x, y;
    char lower;
    char upper;
  };

Key key[64] = {{20, 60, 'a', 'A'},
                 {60, 60, 'b', 'B'},
                 {100, 60, 'c', 'C'},
                 {140, 60, 'd', 'D'},
                 {180, 60, 'e', 'E'},
                 {220, 60, 'f', 'F'},
                 {260, 60, 'g', 'G'},
                 {300, 60, 'h', 'H'},
                 {340, 60, 'i', 'I'},
                 {380, 60, 'j', 'J'},
                 {420, 60, 'k', 'K'},
                 {460, 60, 'l', 'L'},
                 {20, 100, 'm', 'M'},
                 {60, 100, 'n', 'N'},
                 {100, 100, 'o', 'O'},
                 {140, 100, 'p', 'P'},
                 {180, 100, 'q', 'Q'},
                 {220, 100, 'r', 'R'},
                 {260, 100, 's', 'S'},
                 {300, 100, 't', 'T'},
                 {340, 100, 'u', 'U'},
                 {380, 100, 'v', 'V'},
                 {420, 100, 'w', 'W'},
                 {460, 100, 'x', 'X'},
                 {20, 140, 'y', 'Y'},
                 {60, 140, 'z', 'Z'},
                 {100, 140, '1', '1'},
                 {140, 140, '2', '2'},
                 {180, 140, '3', '3'},
                 {220, 140, '4', '4'},
                 {260, 140, '5', '5'},
                 {300, 140, '6', '6'},
                 {340, 140, '7', '7'},
                 {380, 140, '8', '8'},
                 {420, 140, '9', '9'},
                 {460, 140, '0', '0'},
                 {20, 180, '.', '.'},
                 {60, 180, ',', ','},
                 {100, 180, ':', ':'},
                 {140, 180, ';', ';'},
                 {180, 180, '!', '!'},
                 {220, 180, '?', '?'},
                 {260, 180, '#', '#'},
                 {300, 180, '@', '@'},
                 {340, 180, '/', '/'},
                 {380, 180, '\\', '\\'},
                 {420, 180, '&', '&'},
                 {460, 180, '%', '%'},
                 {20, 220, '=', '='},
                 {60, 220, '_', '_'},
                 {100, 220, '-', '-'},
                 {140, 220, '(', '('},
                 {180, 220, ')', ')'},
                 {220, 220, '"', '"'},
                 {260, 220, '+', '+'},
                 {300, 220, '$', '$'},
                 {340, 220, '{', '{'},
                 {380, 220, '}', '}'},
                 {420, 220, '*', '*'},
                 {460, 220, '[', '['},
                 {20, 260, ']', ']'},
                 {60, 260, '\'', '\''},
                 {100, 260, '^', '^'},
                 {140, 260, '~', '~'},
    };

int networks = 0;
String ssidList[20];
String selectedSSID = "";
String inputBufer = "Zopa"; // Промежуточная переменная ввода пароля
String password = "";       // Переменная для рароля
bool passwordOk = false;    // Подтверждение ввода пароля
bool shiftstate = false;    // Переключение между регистрами
uint16_t &tX;              //              ВОПРОС!!!!!!!!!!!!!!!!
uint16_t &tY;               //             ВОПРОС!!!!!!!!!!!!!!!!
//void getTouchXY(uint16_t &tX, uint16_t &tY); ВОПРОС!!!!!!!!!!!!!!!!!

void drawVline(int32_t x0, int32_t y0, int32_t visota, int32_t color, int repit);
void drawHLine(int32_t x0, int32_t y0, int32_t chirina, int32_t color, int repit); 
void drawKeyboard(); // отрисовка клавиатуры
void handleTouchKeyBoard();
void removeChar();
void addChar(char d);
    
  public:
  NetworkPage(TFT_eSPI &_tft, PageManager &manager, uint16_t &_tX, uint16_t &tY);
  void drawStatic() override;
  void updateDinamic() override;
};