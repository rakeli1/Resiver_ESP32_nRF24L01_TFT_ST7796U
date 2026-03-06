#include "InternetForecast.h"
//#include "WiFiManager.h"
//#include "RTClib.h"

//extern WiFiManager wifi;
//extern RTC_DS3231 rtc;
InternetForecast::InternetForecast(String _serverUrl ) : serverUrl(_serverUrl)
{
   
}

//InternetClient::InternetClient()//Доработать!!!!!!!!
//{

//}



 void InternetForecast::updateForecast()
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
         // Serial.println("REQUEST");
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

  JsonDocument& InternetForecast::getDoc()
  {
    return doc;
  }

 // DateTime& InternetClient::getDateTime()
  //{
    // return now;
  //}

     
    //float usdRate = 0.0f;

    
      //=====Запрос курса валют=======
      
    /*  switch (currencyState)
      {
        case CURRENCY_INIT :
        if(wifi.isConnected())
        {
          startCurrencyRequest(); // моя функция которая делает HTTP GET
          currencyState = CURRENCY_REQUEST;
        }
        break;

        case CURRENCY_REQUEST :
        if(currencyResponceReady()) //  проверка получения ответа
        {
          usdRate = parseCurrencyResponse();
          currencyState = CURRENCY_READY;
        }
        break;

        case CURRENCY_READY :
        // курс готов можно обновлять дисплей// периодические обновления, можно через millis()
        break;
      
      
      }
    }*/
    
      
    

   








 
   