#include "RadioData.h"
#include <TFT_eSPI.h>
#include "RF24.h"

RadioData::RadioData(RF24& radiomodul) :
radio(radiomodul) {}


 const struc_radioPaket& RadioData::getData()
{
    return radiopaket;
}

void RadioData::upDate()
{ if(radio.available())
  {
  radio.read(&rx_data, sizeof(rx_data)); 
  }
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


