#include "Button.h"



Button::Button(int x_, int y_, int w_, int h_, FT6336U& _touch) : btnx(x_), btny(y_), btnw(w_), btnh(h_),touch(_touch)
{

}

void Button::getTouchXY()
{
       int x_lib = touch.read_touch1_x();
       int y_lib = touch.read_touch1_y();

       touchx = (480 - y_lib);
       touchy = x_lib;
}



bool Button::isTouched()
{  
   getTouchXY();
   if(touch.read_touch1_event() == 2)
   {
     return (touchx >= btnx && touchx <= btnx + btnw && touchy >= btny && touchy <= btny + btnh);
   }else
   {
     return false;
   }
}

