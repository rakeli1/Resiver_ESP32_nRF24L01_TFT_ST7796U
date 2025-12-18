#include "WiFiClient.h"



WIFIClient::WIFIClient()
  {
    ssid[0] = '\0';
    password[0] = '\0';
  }

void WIFIClient::begin()
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid,password);
}

void WIFIClient::loop()
{
    if(WiFi.status() == WL_CONNECTED)
     {
       connected = true;
       return;
     }

     connected = false;

     unsigned long now = millis();

     if((now - lastReconnectedAttempt) > 10000)
     {
        lastReconnectedAttempt = now;
        WiFi.reconnect();
     }
}

 void WIFIClient::setCredentials(const char*_ssid, const char* _password)
 {
    const char* s = _ssid ? _ssid : "";
    const char* p = _password ? _password : "";

    strncpy(ssid, s, sizeof(ssid));
    ssid[sizeof(ssid) - 1] = '\0';

    strncpy(password, p, sizeof(password));
    password[sizeof(password) - 1] = '\0';

 }

 bool WIFIClient::connect()
 {
   if(ssid[0] == '\0') return false; // нет SSID
   WiFi.begin(ssid, password);
   // ожидание подключения и т.д
   return WiFi.status() == WL_CONNECTED;

 }

 bool WIFIClient::isConnected() const
 {
    return connected;
 }

 bool WIFIClient::sendData(const String& serverUrl,
                           int temperature,
                           int humidity, 
                           int pressure)
    {
       HTTPClient http;
       String json = "{";
       json += "\"temp\":" + String(temperature, 2) + ",";
       json += "\"humidity\":" + String(humidity, 2) + ",";
       json += "\"pressure\":" + String(humidity, 2)  + ",";
       json += "}";

       http.begin(serverUrl);
       http.addHeader("Content-Type", "application/json");

       int code = http.POST(json);

       http.end();

       return (code > 0 && code < 300);
    }