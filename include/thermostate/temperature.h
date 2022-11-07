#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include <memory.h>
#include "cooler.h"
#include "heater.h"


class temperature
{
protected:
    float temp;
    std::unique_ptr<heater> heater_ptr;
    std::unique_ptr<cooler> cooler_ptr;

public:
    virtual void set_temperature(float new_temp) = 0;
    virtual float get_temperature() = 0;
    virtual void heat_temperature(float new_temp) = 0;
    virtual void cool_temperature(float new_temp) = 0;
};
#endif


