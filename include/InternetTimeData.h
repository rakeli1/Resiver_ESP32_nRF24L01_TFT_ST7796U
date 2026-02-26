#pragma once
#include "RTClib.h"
#include "time.h"
#include "Arduino.h"

enum TimeServiceState {TIME_INIT, TIME_REQUEST, TIME_SYNCED};


class InternetTimeData
{
   private:
   uint32_t lastRead = 0;
   int lastMinute = -1;
   const uint32_t interval = 1000;
   String serverTimeData1;
   String serverTimeData2;
   RTC_DS3231& rtcInclass;

   public:
    InternetTimeData(const String& _serverTimeData1, const String& _serverTimeData2, RTC_DS3231&  _rtcInclass);
    TimeServiceState timeState = TIME_INIT;
    struct tm timeinfoclass;                    
    void sinhroTimeData();
    void drawTimeData(int hour, int minute);
   
      

};


    