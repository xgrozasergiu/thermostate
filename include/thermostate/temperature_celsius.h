#ifndef TEMPERATURE_CELSIUS_H
#define TEMPERATURE_CELSIUS_H
#include "temperature.h"

class temperature_celsius : public temperature
{
protected:
    float temp;
    std::unique_ptr<temperature_modifier> heater_ptr;
    std::unique_ptr<temperature_modifier> cooler_ptr;

public:
    temperature_celsius(float temp) ;
    ~temperature_celsius() = default;
    void set_temperature(float new_temp) override;
    float get_temperature() override;
    void heat_temperature(float new_temp) override;
    void cool_temperature(float new_temp) override;
};
#endif