#include "../include/thermostate/heater.h"

float heater::modify_temperature(float temperature)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return temperature;
}
