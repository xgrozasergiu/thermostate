#include "../include/thermostate/cooler.h"

float cooler::modify_temperature(float temperature)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return temperature;
}
