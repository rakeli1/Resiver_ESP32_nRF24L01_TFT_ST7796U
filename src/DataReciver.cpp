#include "DataReciver.h"

DataReciver::DataReciver(RF24 *radio): radio(radio)
{
    for(int i = 0; i < 4; i++)
    {
        dataSensor[i] = 0; // начальные значения
    }
}

bool DataReciver::update()
{
   // здесь код для приема данных с радиомодуля
    return true; //пример
}

const float *DataReciver::getData() const  // возврат указателя на массив значений полученых с радиомодуля
{
    return dataSensor;
}