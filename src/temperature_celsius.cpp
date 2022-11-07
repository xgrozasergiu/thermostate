#include "../include/thermostate/temperature_celsius.h"

temperature_celsius::temperature_celsius(float temp) : temp(temp), heater_ptr(std::make_unique<heater>()), cooler_ptr(std::make_unique<cooler>())
{
}

void temperature_celsius::set_temperature(float new_temp)
{
    temp = new_temp;
}

float temperature_celsius::get_temperature()
{
    return temp;
}

void temperature_celsius::heat_temperature(float new_temp)
{
    set_temperature(heater_ptr->modify_temperature(new_temp));
}

void temperature_celsius::cool_temperature(float new_temp)
{
    set_temperature(cooler_ptr->modify_temperature(new_temp));
}
