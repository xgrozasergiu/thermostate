#ifndef TEMPERATURE_MODIFIER_H
#define TEMPERATURE_MODIFIER_H
#include <thread>

class temperature_modifier
{
public:
    virtual float modify_temperature(float temperature) = 0;
};

#endif