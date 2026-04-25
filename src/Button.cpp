#include "Button.h"
#include "TFT_eSPI.h"

extern TouchState structtouch;
extern TFT_eSPI tft;
extern uint16_t tX;
extern uint16_t tY;

Button::Button(int x_, int y_, int w_, int h_, uint32_t _color, bool _visible, bool _enable) : btnx(x_), btny(y_), btnw(w_),
 btnh(h_), color(_color), visible(_visible), enable(_enable)
{

}
 
void Button::draw()
{
  if(!visible) return;
  tft.fillRect(btnx, btny, btnw, btnh, color);

}

bool Button::isTouched()
{  
   
   if(structtouch.pressed)
   {
   if(!visible || !enable) return false;

      if(tX >= btnx && tX <= btnx + btnw && tY >= btny && tY <= btny + btnh)
       { 
         structtouch.pressed = false;
         // tX = -1;
          // tY = -1;
       }
    
     return (tX >= btnx && tX <= btnx + btnw && tY >= btny && tY <= btny + btnh);
     
   }else
   {
     return false;
   }
}

