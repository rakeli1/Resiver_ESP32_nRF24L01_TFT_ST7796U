#pragma once
#include <WiFi.h>
#include "WiFiClientSecure.h"
#include "WiFiClient.h"
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "RTClib.h"


enum NetState
{
   IDLE,         // готовимся к запросу
   CONNECTING,      // начинаем соединение
   WAIT_RESPONSE,  //ждем собраного ответа
   DONE,         // данные готовы, можно передать UI
   ERROR         // ошибка можно повторить
};



//enum CurrencyServisState {CURRENCY_INIT, CURRENCY_REQUEST, CURRENCY_READY};
    //CurrencyServisState currencyState = CURRENCY_INIT;

class InternetForecast
{
  private:
    
    String serverUrl;        
    HTTPClient http;
    
    

  


   public:
     JsonDocument doc;                        // распарсеный документ прогноза погоды
     
     
     NetState state = IDLE;      // прогноз погоды
     bool requestStarted = true; // прогноз погоды
     String response;            // ответ с сервера прогноз погоды
     InternetForecast(String _serverUrl);
    // InternetClient();                 
     void updateForecast();
     //void updateTimeData(); 
     JsonDocument &getDoc();       // прогноз погоды
    // DateTime &getDateTime();    // дата и время
     
            

};