#include "../include/thermostate/thermostate.h"

thermostate::thermostate(float min, float max, float temp) : initialized(false), thermostate_state(stop), temperature(temp)
{
    if (min <= max)
    {
        limits.min = min;
        limits.max = max;
        initialized = true;
        check_temperature();
    }
}

bool thermostate::set_limit_max(float max)
{
    if (max < limits.min)
    {
        return false;
    }
    limits.max = max;

    return true;
}

bool thermostate::set_limit_min(float min)
{
    if (min > limits.max)
    {
        return false;
    }

    limits.min = min;

    return true;
}

void thermostate::check_temperature()
{
    if (temperature > limits.max)
    {
        thermostate_state = cool;
        cool_temp();
    }
    else if (temperature < limits.min)
    {
        thermostate_state = heat;
        heat_temp();
    }
    else
    {
        thermostate_state = stop;
    }
}

void thermostate::heat_temp()
{
    if (temperature < limits.min)
    {
        set_temperature(limits.min);
    }
    else
    {
        thermostate_state = stop;
    }
}

void thermostate::cool_temp()
{
    if (temperature > limits.max)
    {
        set_temperature(limits.max);
    }
    else
    {
        thermostate_state = stop;
    }
}

float thermostate::get_temperature()
{
    return temperature;
}

void thermostate::set_temperature(float temp)
{
    temperature = temp;
}

State thermostate::get_thernostate_state()
{
    return thermostate_state;
}

std::__1::string thermostate::get_state()
{
    switch (thermostate_state)
    {
    case heat:
        return "Heating, temperature under the minimum limit: " + std::to_string(limits.min);
        break;
    case cool:
        return "Cooling, temperature over the maximum limit: " + std::to_string(limits.max);
        break;
    default:
        return "Temperature is in limits ( " + std::to_string(limits.min) + " , " + std::to_string(limits.max) + " )";
        break;
    }
}