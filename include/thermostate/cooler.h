#ifndef COOLER_H
#define COOLER_H

#include "temperature_modifier.h"

class cooler: public temperature_modifier
{
public:
    cooler() = default;
    ~cooler() = default;
    float modify_temperature(float temperature);
};
#endif