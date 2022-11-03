#include "thermostate.h"
enum Menu{
    front_menu,
    modify_max_limit,
    modify_min_limit,
    close,
    modify
};

class thermostate_controller
{
private:
    thermostate thermo;
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


