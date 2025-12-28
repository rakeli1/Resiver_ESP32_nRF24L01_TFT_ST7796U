#pragma once
#include <stdint.h>

struct TouchState
{
   bool pressed = false;
   int16_t x = -2;
   int16_t y = -2;
};