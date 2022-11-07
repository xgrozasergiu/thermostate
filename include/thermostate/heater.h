#ifndef HEATER_H
#define HEATER_H

#include "temperature_modifier.h"

class heater : public temperature_modifier
{
public:
    heater() = default;
    ~heater() = default;
    float modify_temperature(float temperature);
};
#endif