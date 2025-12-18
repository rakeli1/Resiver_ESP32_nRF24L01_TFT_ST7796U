#pragma once
#include <WiFi.h>
#include <HTTPClient.h>

class WIFIClient
{
  private:
      char ssid[32];
      char password[64];
     bool connected  = false;
     unsigned long lastReconnectedAttempt = 0;


   public:
      WIFIClient();

      void begin();
      void loop();
      void setCredentials(const char* _ssid, const char* _password);
      bool connect();
      bool isConnected() const;

      bool sendData(const String& serverUrl,
                    int temperature, 
                    int humidity,
                    int pressure);

};