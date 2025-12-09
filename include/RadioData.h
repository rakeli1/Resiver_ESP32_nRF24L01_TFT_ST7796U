#pragma once
#include "nRF24L01.h"
#include "RF24.h"
#include<stdint.h>
#include "struct_radioPaket.h"

enum Type
{
  ID,
  TEMPERATURE,
  HUMIDITY,
  PRESSURE,
  PERCENT,
  ADCFL, // значение АЦП
  VA0,   // Напряжение на пине А0
  VBAT,  // напряжение на батарее
};




class RadioData
{  
 private:
   RF24& radio;
   float rx_data[8];
   radioPaket radiopaket; // структура данных
   
   
   public:
   RadioData(RF24& radiomodul);
  // bool resive();
   const radioPaket& getData();
   void upDate();
   
     
   
   

};