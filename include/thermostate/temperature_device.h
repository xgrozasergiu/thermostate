#ifndef TEMPERATURE_DEVICE_H
#define TEMPERATURE_DEVICE_H
#include "temperature_modifier.h"
#include "temperature_celsius.h"

class temperature_device
{
protected:
    std::shared_ptr<temperature_celsius> temp;

public:
    virtual void check_temperature() = 0;
};
#endif
