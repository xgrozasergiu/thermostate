#ifndef THERMOSTATE_CONTROLLER_H
#define THERMOSTATE_CONTROLLER_H

#include <thread>
#include "thermostate.h"
#include "temperature_device_controller.h"

enum Menu
{
    front_menu,
    modify_max_limit,
    modify_min_limit,
    close,
    modify
};

class thermostate_controller : public temperature_device_controller
{
private:
    std::unique_ptr<thermostate> thermo;
    Menu thermostate_menu;

    void modify_menu();

public:
    int choice;
    int max;
    int min;

    thermostate_controller(thermostate thermo);
    ~thermostate_controller() = default;
    void display_menu();
    void main_menu();
    void modify_min_limit_menu();
    void modify_max_limit_menu();
    bool get_close_menu_state();
};
#endif