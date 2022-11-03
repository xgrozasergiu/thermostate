#include "../include/thermostate/thermostate_controller.h"

thermostate_controller::thermostate_controller(thermostate th) : thermo(th), thermostate_menu(front_menu)
{
    system("clear");
}

void thermostate_controller::display_menu()
{
    std::cout << "Thermostate Menu" << std::endl;

    if (thermo.get_thernostate_state() == State::stop)
    {
        std::cout << "Temperature : " << thermo.get_temperature() << " degrees" << std::endl;
        std::cout << thermo.get_state() << std::endl;
        std::cout << "" << std::endl;

        switch (thermostate_menu)
        {
        case modify_max_limit:
            modify_max_limit_menu();
            break;
        case modify_min_limit:
            modify_min_limit_menu();
            break;
        case close:
            thermostate_menu = close;
            break;
        default:
            main_menu();
            break;
        }
    }
    else
    {
        modify_menu();
    }

    thermo.check_temperature();

    system("clear");
}

void thermostate_controller::main_menu()
{
    thermostate_menu = front_menu;

    std::cout << "Choose action: " << std::endl;
    std::cout << "1. Modify maximum limit " << std::endl;
    std::cout << "2. Modify minimum limit " << std::endl;
    std::cout << "3. Close " << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Choose option: ";
    std::cin >> choice;

    switch (choice)
    {
    case front_menu:
        thermostate_menu = front_menu;
        break;
    case modify_max_limit:
        thermostate_menu = modify_max_limit;
        break;
    case modify_min_limit:
        thermostate_menu = modify_min_limit;
        break;
    case close:
        thermostate_menu = close;
        break;
    default:
        thermostate_menu = front_menu;
        break;
    }
}

void thermostate_controller::modify_max_limit_menu()
{
    thermostate_menu = modify_max_limit;
    std::cout << "New maximum limit: ";
    std::cin >> max;

    if (thermo.set_limit_max(max))
    {
        thermostate_menu = modify;
    }
    else
    {
        thermostate_menu = modify_max_limit;
    }
}

void thermostate_controller::modify_min_limit_menu()
{
    thermostate_menu = modify_min_limit;
    std::cout << "New minimum limit: ";
    std::cin >> min;

    if (thermo.set_limit_min(min))
    {
        thermostate_menu = modify;
    }
    else
    {
        thermostate_menu = modify_min_limit;
    }
}

void thermostate_controller::modify_menu()
{
    std::cout << thermo.get_state() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    thermostate_menu = front_menu;
}

bool thermostate_controller::get_close_menu_state()
{
    if (thermostate_menu == close)
    {
        return true;
    }

    return false;
}