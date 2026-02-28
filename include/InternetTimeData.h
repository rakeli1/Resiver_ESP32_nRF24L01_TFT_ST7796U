#pragma once
#include "RTClib.h"
#include "time.h"
#include "Arduino.h"

enum TimeServiceState {TIME_IDLE, TIME_INIT, TIME_REQUEST, TIME_SYNCED};


class InternetTimeData
{
   private:
   
   
   const uint32_t interval = 1000;
   String serverTimeData1;
   String serverTimeData2;
   

   public:
    InternetTimeData(const String& _serverTimeData1, const String& _serverTimeData2, RTC_DS3231&  _rtcInclass);
    TimeServiceState timeState = TIME_INIT;
    RTC_DS3231& rtcInclass;
    struct tm timeinfoclass;                    
    void sinhroTimeData();
    uint32_t lastRead = 0;
    int lastMinute = -1;
    void drawTimeData(int hour, int minute);

   
      

};


    