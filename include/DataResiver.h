#pragma once
#include "struct_radioPaket.h"
#include "RadioData.h"
#include "InternetClient.h"
#include <ArduinoJson.h>

class DataResiver
{
    private:
    InternetClient& client1;
    


    public:
     DataResiver(InternetClient& _client1);
     void parseFromJsonDoc(StaticJsonDocument<1024>&doc);
     
};