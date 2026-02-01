#pragma once
#include <WiFi.h>
#include "WiFiClientSecure.h"
#include "WiFiClient.h"
#include <HTTPClient.h>
#include <ArduinoJson.h>


enum NetState
{
   IDLE,         // готовимся к запросу
   CONNECTING,      // начинаем соединение
   WAIT_RESPONSE,  //ждем собраного ответа
   DONE,         // данные готовы, можно передать UI
   ERROR         // ошибка можно повторить
};

class InternetClient
{
  private:
    
    String serverUrl;        
    HTTPClient http;
    JsonDocument doc;
    

  


   public:
     NetState state = IDLE;
     bool requestStarted = true;
     String response;
     InternetClient(String _serverUrl);
     void update(); 
     JsonDocument &getDoc();
     
            

};