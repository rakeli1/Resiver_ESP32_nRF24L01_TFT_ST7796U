#pragma once
#include <Arduino.h>
#include <WiFi.h>
#include "WiFiClientSecure.h"
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "FileServises.h"





class InternetCurrency
{
   private:
   // String serverBankUrl; 
           
    HTTPClient httpc;
    WiFiClientSecure clientsec;
    const String& serverUrl1;
    

   public:
    JsonDocument docBank;
    String responseBank;
    bool requestBankStarted = true;
    NetState stateBank; //=IDLE
    JsonDocument &getDocBank();
    InternetCurrency(const String& _serverUrl1); 
    void updateCurrency();
};