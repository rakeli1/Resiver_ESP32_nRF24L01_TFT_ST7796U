#pragma once
#include <WiFi.h>
#include "WiFiClientSecure.h"
#include "WiFiClient.h"
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "RTClib.h"
#include "FileServises.h"






//enum CurrencyServisState {CURRENCY_INIT, CURRENCY_REQUEST, CURRENCY_READY};
    //CurrencyServisState currencyState = CURRENCY_INIT;

class InternetForecast
{
  private:
    
    String serverUrl;        
    HTTPClient http;
   
    

  


   public:
     JsonDocument doc;                        // распарсеный документ прогноза погоды
      NetState state = IDLE;
     
           // прогноз погоды
     bool requestStarted = true; // прогноз погоды
     String response;            // ответ с сервера прогноз погоды
     InternetForecast(String _serverUrl);                 
     void updateForecast(); 
     JsonDocument &getDoc();       // прогноз погоды
     
            

};