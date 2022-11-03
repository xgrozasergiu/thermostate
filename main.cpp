#include <iostream>
#include "include/thermostate/thermostate_controller.h"

int main(int, char **)
{
    thermostate thermostate1(10.f, 32.f, 21.f);
    thermostate_controller th_ctr(thermostate1);

    while (!th_ctr.get_close_menu_state())
    {
        th_ctr.display_menu();
    }

    return 0;
}
