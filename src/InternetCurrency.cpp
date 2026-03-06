#include "InternetCurrency.h"

InternetCurrency::InternetCurrency(const String& _serverUrl1) :
 serverUrl1(_serverUrl1)// Доработать!!!!!!
{

}

void InternetCurrency::updateCurrency()
{
    
    switch(stateBank)
    {
      case IDLE :
      if(requestBankStarted)
      {
        stateBank = CONNECTING;
      }
      break;

      case CONNECTING :
      
        clientsec.setInsecure(); 
        httpc.begin(clientsec, serverUrl1);                   
        httpc.useHTTP10(true);                       // раскомментировать при запросе в банк
        httpc.addHeader("User-Agent", "ESP32");      //  раскомментировать при запросе в банк       
        httpc.addHeader("Accept", "application/json"); // раскомментировать при запросе в банк      
        httpc.addHeader("Connection", "close");       //  раскомментировать при запросе в банк      
        httpc.setTimeout(5000);                       // раскоментировать при запросе в банк
        httpc.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);//раскомментировать при запросе в банк!
        configTime(7200, 3600, "pool.ntp.org", "time.nist.gov");
        Serial.println("CONNECTING"); // отладка!!!!!!!!!!!!!!!!
        stateBank = WAIT_RESPONSE;
       break;

       case WAIT_RESPONSE :
       {
         int code = httpc.GET();
         if(code > 0)
        {
          responseBank = httpc.getString();
          DeserializationError err = deserializeJson(docBank, responseBank);
          if(err)
          {
            Serial.print("JSON parse error:");
            Serial.println(err.c_str());
          }
          stateBank = DONE;
         // Serial.println("REQUEST");
        }else
        {
          stateBank = ERROR;
          Serial.println("ERROR IN WAIT_RESPONSE");
        }
          break;
       }
       case DONE :
       {
          httpc.end();
          //Serial.print(response);
          requestBankStarted = false;
          stateBank = IDLE;
       }
        break;
        case ERROR :
        {
        httpc.end();
        stateBank = IDLE;
        }
        break;
    }
}

JsonDocument& InternetCurrency::getDocBank()
{
  return docBank;
}