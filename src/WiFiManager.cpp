#include "WiFiManager.h"

WiFiManager::WiFiManager(const char* ssid, const char* password) : _ssid(ssid), _password(password)
{

}

void WiFiManager::begin()
{
    WiFi.mode(WIFI_STA);
    WiFi.setAutoReconnect(false);
    WiFi.disconnect(true);

    _state  = WiFiState::START;
}

void WiFiManager::update()
{
    switch (_state)
    {
    case WiFiState::OFF :
        
        break;

    case WiFiState::START :
    WiFi.begin(_ssid, _password);
    _ts = millis();
    _state = WiFiState::CONNECTING;
    break;

    case WiFiState::CONNECTING :
    if(WiFi.status() == WL_CONNECTED)
    {
        _state = WiFiState::CONNECTED;
    } else if(millis() - _ts > CONNECT_TIMEOUT)
    {
        WiFi.disconnect(true);
        _ts = millis();
        _state = WiFiState::RETRY;
    }
    break;

    case WiFiState::CONNECTED :
    if(WiFi.status() != WL_CONNECTED)
    {
        WiFi.disconnect(true);
        _ts = millis();
        _state = WiFiState::RETRY;
    }
    break;

    case WiFiState::RETRY :
    if(millis() - _ts > RETRY_DELAY)
    {
        _state = WiFiState::START;
    }
    break;
    
    }
}

bool WiFiManager::isConnected() const
{
   return _state == WiFiState::CONNECTED;
}

WiFiState WiFiManager::getState() const
{
    return _state;
}