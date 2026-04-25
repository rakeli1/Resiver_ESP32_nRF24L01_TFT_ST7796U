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
     bool needConnect = false; // флаг - "НАДО ПОДКЛЮЧИТЬСЯ!"

     String _ssid;
     String _password;
     static constexpr unsigned long CONNECT_TIMEOUT = 10000; // 10 секунд
     static constexpr unsigned long RETRY_DELAY = 5000;      // 5 секунд

  public:
     WiFiManager(String ssid, String password);
     WiFiManager(){};
     void begin();
     void update();
     void setCredentials(String _ssidUser, String _passwordUser);
     bool isConnected() const;
     WiFiState getState() const;

  
};