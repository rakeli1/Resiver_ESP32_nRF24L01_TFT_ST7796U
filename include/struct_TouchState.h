#pragma once
#include <stdint.h>

struct TouchState
{
   bool pressed = false;
   uint16_t x = 0;
   uint16_t y = 0;
};