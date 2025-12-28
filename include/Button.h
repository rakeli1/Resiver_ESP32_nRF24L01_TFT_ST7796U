#pragma once
#include <stdint.h>
#include "FT6336U.h"
#include "struct_TouchState.h"


class Button
{
   private:
      int btnx; 
      int btny; 
      int btnw; 
      int btnh;
   
      
      

   public:
      Button(int x, int y, int w, int h);
      bool isTouched();
      //void getTouchXY(); //метод согласовующий несоответствие реальных координат нажатия с програмными 
                          // и установки координат касания
      
   
      
      
};