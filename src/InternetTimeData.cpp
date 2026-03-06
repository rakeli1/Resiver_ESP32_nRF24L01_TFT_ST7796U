#include "InternetTimeData.h"

extern RTC_DS3231 rtc;

InternetTimeData::InternetTimeData(const String& _serverTimeData1, const String& _serverTimeData2, RTC_DS3231&  _rtcInclass) : serverTimeData1(_serverTimeData1), 
                                   serverTimeData2(_serverTimeData2), rtcInclass(_rtcInclass)
{

}

void InternetTimeData::sinhroTimeData()
{
    {
      //====NTP/ сервер времени=======
    switch (timeState)
    {
      case TIME_INIT : 
      {
        configTime(2*3600, 3600, serverTimeData1.c_str(), serverTimeData2.c_str());
        timeState = TIME_REQUEST;
      }
      break;
      case TIME_REQUEST :
      if(getLocalTime(&timeinfoclass))
      {
       
        timeState = TIME_SYNCED;
      }
        break;
      case TIME_SYNCED :
            rtcInclass.adjust(DateTime(
            timeinfoclass.tm_year + 1900,    
            timeinfoclass.tm_mon + 1,
            timeinfoclass.tm_mday,
            timeinfoclass.tm_hour,
            timeinfoclass.tm_min,
            timeinfoclass.tm_sec
            
        ));
        timeState = TIME_IDLE;
        Serial.println("TIME SINCHED!!!");
       // Serial.println(String(timeinfoclass.tm_min));
        // rtcInclass.;
        // Время синхронизировано можно периодически проверять можно периодически обновлять через millis()
        break;
      }
    }
}
