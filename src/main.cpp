#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include "MainPage.h"
#include "RadioData.h"
#define CE_PIN  26
#define CSN_PIN 27

RF24 radio(CE_PIN,CSN_PIN);
byte address[][6] = {"1Node", "2Node", "3Node", "4Node", "5Node", "6Node"}; 
TFT_eSPI tft = TFT_eSPI(); 
RadioData radiodata (radio);
radioPaket paket; // структура в которую заходят данные с радиомодуля
MainPage mainPage(tft, paket);





void setup() 
{
  Serial.begin(9600);
  tft.init();
  tft.setRotation(3); // левый верхний угол - 0 координат(x- вправо , y - вниз). контакты дисплея слева 
  tft.fillScreen(TFT_DARKGREY);
  mainPage.draw();
  radio.begin();
  radio.setAutoAck(1);
  radio.setRetries(0,15);
  radio.enableAckPayload();
  radio.setPayloadSize(32);

  radio.openReadingPipe(1, address[0]);
  radio.setChannel(0x60);
  radio.setPALevel(RF24_PA_LOW);
  radio.setDataRate(RF24_250KBPS);

  radio.powerUp();
  radio.startListening();
}

void loop() 
{   
    
    radiodata.upDate();
    paket = radiodata.getData();
    mainPage.update();
    //float temperature = paket.temperature;
    //Serial.println(temperature);
    //delay(1000);

    //Serial.println("HELLO");
} 

