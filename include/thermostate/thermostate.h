#ifndef THERMOSTATE_H
#define THERMOSTATE_H

#include <iostream>
#include <string>
#include "temperature_device.h"
#include "temperature.h"
#include "temperature_celsius.h"

enum State
{
    stop,
    heat,
    cool
};

struct limits
{
    float max;
    float min;
};

class thermostate : public temperature_device
{
private:
    limits limits;
    bool initialized;
    State thermostate_state;

protected:
    std::shared_ptr<temperature_celsius> temp;

public:
    bool set_limit_max(float max);
    bool set_limit_min(float min);
    void check_temperature();
    float get_temperature();
    State get_thernostate_state();
    std::string get_state();
    thermostate(float min, float max, float temp);
    ~thermostate() = default;
};
#endif
