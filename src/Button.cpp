#include "Button.h"

extern TouchState structtouch;
extern uint16_t tX;
extern uint16_t tY;

Button::Button(int x_, int y_, int w_, int h_) : btnx(x_), btny(y_), btnw(w_), btnh(h_)
{

}

//void Button::getTouchXY()
//{
       //int x_lib = touch.read_touch1_x();
       //int y_lib = touch.read_touch1_y();

       //touchx = (480 - y_lib);
       //touchy = x_lib;
//}



bool Button::isTouched()
{  
   
   if(structtouch.pressed)
   { 
     return (tX >= btnx && tX <= btnx + btnw && tY >= btny && tY <= btny + btnh);
   }else
   {
     return false;
   }
}

