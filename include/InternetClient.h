#pragma once
#include <WiFi.h>
#include <HTTPClient.h>



enum NetState
{
   NET_IDLE,         // готовимся к запросу
   NET_REQUEST,      // начинаем запрос
   NET_WAIT_RESPONSE,// ждем завершения можно через таймер или ассинхронный метод
   NET_DONE,         // данные готовы, можно передать UI
   NET_ERROR         // ошибка можно повторить
};

class InternetClient
{
  private:
    const char* serverUrl;         // адрес клиента
    String response;               // полученые данные
    NetState state;                // текущее состояние клиента
    unsigned long updateInterval;
    unsigned long lastUpdate;
    void startRequest();
    bool requestStarted;
    HTTPClient http;
    WiFiClient client;
    String bufer;


   public:
    InternetClient(const char* url, unsigned long intervalMs);
    void begin(const char*server);  // задаем URL и инициализируем клиента
    void update();                  // вызывается каждый цикл в loop() внутри проверяем состояние states
    const String& getData();        // получить данные когда готово
    NetState getState();            // узнать состояние

};