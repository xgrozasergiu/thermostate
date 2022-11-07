#ifndef TEMPERATURE_DEVICE_CONTROLLER_H
#define TEMPERATURE_DEVICE_CONTROLLER_H
#include "temperature_device.h"

class temperature_device_controller
{
private:
    std::unique_ptr<temperature_device> thermo;

    virtual void modify_menu() = 0;

public:
    void display_menu();
    void main_menu();
    
};
#endif
