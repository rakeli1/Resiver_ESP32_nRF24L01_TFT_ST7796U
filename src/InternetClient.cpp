#include "InternetClient.h"

InternetClient::InternetClient(String _serverUrl ) : serverUrl(_serverUrl)
{
   
}



 void InternetClient::update()
 {
    switch(state)
    {
       case IDLE :
        if(requestStarted)
          state = CONNECTING;
       break; 

        case CONNECTING :
        http.begin(serverUrl);
        state = WAIT_RESPONSE;
        break;

        case WAIT_RESPONSE :
        {
        int code = http.GET();
        if(code > 0)
        {
          response = http.getString();
          DeserializationError err = deserializeJson(doc, response);
          if(err)
          {
            Serial.print("JSON parse error:");
            Serial.println(err.c_str());
          }
          state = DONE;
          Serial.println("REQUEST");
        }else
        {
          state = ERROR;
          Serial.println("ERROR IN WAIT_RESPONSE");
        }
    }
        break;
        

        case DONE : 
        {
          http.end();
          //Serial.print(response);
          requestStarted = false;
          state = IDLE;
        }
        break;

        case ERROR :
        {
        http.end();
        state = IDLE;
        }
        break;
    }
 }

  JsonDocument& InternetClient::getDoc()
  {
    return doc;
  }


       

   








 
   