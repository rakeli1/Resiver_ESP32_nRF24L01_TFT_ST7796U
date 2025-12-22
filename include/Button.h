#pragma once
#include <stdint.h>
#include "FT6336U.h"


class Button
{
   private:
      int x; 
      int y; 
      int w; 
      int h;
      FT6336U& touch;
      
      

   public:
      Button(int x, int y, int w, int h, FT6336U& _touch);
      bool isTouched(int touchX, int touchY);
      
};