#include "InternetClient.h"
#include <WiFi.h> 
#include <HTTPClient.h>



InternetClient::InternetClient(const char* url, unsigned long intervalMs)
   : serverUrl(url), updateInterval(intervalMs)
{

}

 const String& InternetClient::getData()
{
    return response;
}

NetState InternetClient::getState() 
{
    return state;
}

void InternetClient::startRequest()
{
    response = "";
    state = NET_REQUEST;
    requestStarted = false;
}

void InternetClient::update()
{
    unsigned long now = millis();

    switch (state)
    {
    case NET_IDLE :
        if(now - lastUpdate >= updateInterval)
        {
            startRequest();
        }
        break;

    case NET_REQUEST : 
        if(!requestStarted) 
        {
            http.begin(client, serverUrl);
            http.setTimeout(3000);
            int code = http.sendRequest("GET");
            if(code < 0)
            {
            state = NET_ERROR;
            } else
             {
                state = NET_WAIT_RESPONSE;
             }
             requestStarted = true;

        } 
         break;

    case NET_WAIT_RESPONSE :
       if(client.connected())
       {
        while(client.available())
        {
            bufer += (char)client.read();        
        }
        } else 
        {
            state = NET_DONE;
            http.end();
        }   

         break;
        
    
    case NET_DONE :
        state = NET_IDLE; // вернулись в ожидание
         break;

    case NET_ERROR :
        state = NET_IDLE; // можно добавить повтор через интервал
        break;
         
    default:
        break;
    }
}








 
   