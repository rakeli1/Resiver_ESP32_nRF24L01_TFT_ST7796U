#pragma once
#include <stdint.h>
#include "FT6336U.h"


class Button
{
   private:
      int btnx; 
      int btny; 
      int btnw; 
      int btnh;
      FT6336U& touch;
      
      

   public:
      Button(int x, int y, int w, int h, FT6336U& _touch);
      bool isTouched();
      void getTouchXY(); //метод согласовующий несоответствие реальных координат нажатия с програмными 
                          // и установки координат касания
      int touchx = - 1;
      int touchy = - 1;
      
      
};