#pragma once
#include <RF24.h>


class DataReciver
{
  public:
     DataReciver(RF24 *radio);
     bool update();               // прием данных с радиомодуля
     const float *getData()const;  // возврат указателя на массив значений полученых с радиомодуля

   private:
      RF24 *radio;
      float dataSensor[4]; //массив в который сохраняем данные полученые с радиомодуля
};