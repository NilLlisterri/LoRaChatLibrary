#pragma once

#include <Arduino.h>

#include "./message/dataMessage.h"

#pragma pack(1)
class WiFiMessage: public DataMessageGeneric {
public:
    uint8_t url;
    uint8_t payload[];
};
#pragma pack()