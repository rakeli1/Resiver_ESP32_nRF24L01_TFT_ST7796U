#pragma once
#include <WiFi.h>

enum class WiFiState
{
   OFF,
   START,
   CONNECTING,
   CONNECTED,
   LOST,
   RETRY
};

class WiFiManager
{
  private:
     WiFiState _state = WiFiState::OFF;
     unsigned long _ts = 0;

     const char* _ssid;
     const char* _password;

     static constexpr unsigned long CONNECT_TIMEOUT = 10000; // 10 секунд
     static constexpr unsigned long RETRY_DELAY = 5000;      // 5 секунд

  public:
     WiFiManager(const char* ssid, const char* password);
     void begin();
     void update();
     bool isConnected() const;
     WiFiState getState() const;

  
};