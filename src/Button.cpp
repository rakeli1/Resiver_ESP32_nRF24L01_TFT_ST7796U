#include "Button.h"



Button::Button(int x_, int y_, int w_, int h_, FT6336U& _touch) : x(x_), y(y_), w(w_), h(h_),touch(_touch)
{

}



bool Button::isTouched(int touchX, int touchY)
{  
   if(touch.read_touch1_event() == 2)
   {
    return(touchX >= x && touchX <= x + w && touchY >= y && touchY <= y + h);
   }else
   {
     return false;
   }
}

