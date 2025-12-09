#include "RadioData.h"
#include <TFT_eSPI.h>

RadioData::RadioData(RF24& radiomodul) :
radio(radiomodul) {}


 const radioPaket& RadioData::getData()
{
    return radiopaket;
}

void RadioData::upDate()
{
    
  radiopaket.ID = rx_data[ID];
  radiopaket.temperature = rx_data[TEMPERATURE];
  radiopaket.humidity = rx_data[HUMIDITY];
  radiopaket.pressure = rx_data[PRESSURE];
  radiopaket.percent = rx_data[PERCENT];
  radiopaket.adcfl = rx_data[ADCFL];
  radiopaket.vA0 = rx_data[VA0];
  radiopaket.vbat = rx_data[VBAT];

}


/*bool RadioData::resive()
{

}*/


