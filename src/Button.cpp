#include "Button.h"

extern TouchState structtouch;
extern uint16_t tX;
extern uint16_t tY;

Button::Button(int x_, int y_, int w_, int h_) : btnx(x_), btny(y_), btnw(w_), btnh(h_)
{

}




bool Button::isTouched()
{  
   
   if(structtouch.pressed)
   {
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

