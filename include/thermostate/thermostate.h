#include <iostream>
#include <thread>
#include <string>

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

class thermostate
{
private:
    limits limits;
    bool initialized;
    float temperature;
    State thermostate_state;

    void heat_temp();
    void cool_temp();

public:
    bool set_limit_max(float max);
    bool set_limit_min(float min);
    float get_temperature();
    void set_temperature(float temp);
    void check_temperature();
    State get_thernostate_state();
    std::string get_state();
    thermostate(float min, float max, float temp);
    ~thermostate() = default;
};
