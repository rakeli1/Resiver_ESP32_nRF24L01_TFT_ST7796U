#include "DataReciver.h"
#include <ctime>

DataReciver::DataReciver(RF24& radio) : radiomodul(radio) 
{
    for(int i = 0; i < 4; i++)
    dataSensor[i] = 0.0f;

    RadioData {0.0f, 0.0f, 0.0f, 0 };
    ForecastData {0.0f, 0.0f, 0.0f, 0.0f, 0, 0};
    TimeData {0, 0, 0, 0, 0, 0, 0};
}

void DataReciver::updateRadio()
{
    if(radiomodul.available())
    {
        radiomodul.read(&dataSensor, sizeof(dataSensor));
    }

    radiodata.temperature = dataSensor[0];
    radiodata.humidity = dataSensor[1];
    radiodata.pressure = dataSensor[2];
    radiodata.baterylevel = dataSensor[3];
}

void DataReciver::updateForecast()
{
    forecast.temp_morning = 15.f;
    forecast.temp_day     = 25.0f;
    forecast.temp_evening = 18.0f;
    forecast.temp_night   = 15.0f;
    forecast.precipitatios = 0.2f;
}

void DataReciver::updateTimeData()
{
  time_t now = time(nullptr);
  struct tm* t = localtime(&now);

  timedata.year  = t->tm_year + 1900;
  timedata.month = t->tm_mon + 1;
  timedata.day   = t->tm_yday;
  timedata.hour  = t->tm_hour;
  timedata.minute = t->tm_min;
  timedata.seconds= t->tm_sec;
  timedata.unixTime = now; 
}

RadioData& DataReciver::getRadioData()
{
  return radiodata;
}

ForecastData& DataReciver::getForecastData()
{
    return forecast;
}

TimeData& DataReciver::getTimeData()
{
    return timedata;
}