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
    String serverUrl;              // адрес клиента
    String response;               // полученые данные
    NetState state;                // текущее состояние клиента
    unsigned long requestStartTime;
    void startRequest();


   public:
    InternetClient();
    void begin(const char*server);  // задаем URL и инициализируем клиента
    void update();                  // вызывается каждый цикл в loop() внутри проверяем состояние stat
    const String& getData();        // получить данные когда готово
    NetState getState();            // узнать состояние

};