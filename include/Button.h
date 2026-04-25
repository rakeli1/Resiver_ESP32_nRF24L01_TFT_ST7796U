#pragma once
#include <stdint.h>
#include "FT6336U.h"
#include "struct_TouchState.h"
#include "TFT_eSPI.h"


class Button
{
   private:
      int btnx; 
      int btny; 
      int btnw; 
      int btnh;
      uint32_t color;
   
   public:
      Button(int x, int y, int w, int h, uint32_t color, bool _visible, bool _enable);
      bool visible = false;
      bool enable = false;
      bool isTouched();
      void draw();    // в моем случае используется для кнопок которые становятся видимыми и активными 
                      // при определенных условиях
};