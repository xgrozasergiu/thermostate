#include <gtest/gtest.h>
#include "include/thermostate/thermostate_controller.h"
#include "include/thermostate/temperature.h"

struct ThermostateTest : testing::Test
{
    thermostate* thermo;

    ThermostateTest()
    {
        thermo = new thermostate(10.f, 32.f, 21.f);
    }

    ~ThermostateTest()
    {
        delete thermo;
    }
};

TEST_F(ThermostateTest,ThermostateInitialTemp)
{
    EXPECT_EQ(21.f,thermo->get_temperature());
}

TEST_F(ThermostateTest,ThermostateInitialState)
{
    EXPECT_EQ(State::stop,thermo->get_thernostate_state());
}

TEST_F(ThermostateTest,ThermostateSetMaxTrue)
{
    EXPECT_EQ(true,thermo->set_limit_max(33.f));
}

TEST_F(ThermostateTest,ThermostateSetMaxFalse)
{
    EXPECT_EQ(false,thermo->set_limit_max(9.f));
}

TEST_F(ThermostateTest,ThermostateSetMinTrue)
{
    EXPECT_EQ(true,thermo->set_limit_min(9.f));
}

TEST_F(ThermostateTest,ThermostateSetMinFalse)
{
    EXPECT_EQ(false,thermo->set_limit_max(33.f));
}

TEST_F(ThermostateTest,ThermostateSetTemp)
{
    thermo->set_limit_min(30.f);
    EXPECT_EQ(30.f,thermo->get_temperature());
}

TEST_F(ThermostateTest,ThermostateSetTemp)
{
    thermo->set_limit_max(20.f);
    EXPECT_EQ(20.f,thermo->get_temperature());
}

struct TemperatureTest : testing::Test
{
    temperature* temp;

    TemperatureTest()
    {
        temp = new temperature_celsius(21.f);
    }

    ~TemperatureTest()
    {
        delete temp;
    }
};

TEST_F(TemperatureTest,TemperatureSetTemp)
{
    temp->set_temperature(20.f);
    EXPECT_EQ(20.f,temp->get_temperature());
}

TEST_F(TemperatureTest,TemperatureHeatTemp)
{
    temp->heat_temperature(22.f);
    EXPECT_EQ(22.f,temp->get_temperature());
}

TEST_F(TemperatureTest,TemperatureCoolTemp)
{
    temp->cool_temperature(20.f);
    EXPECT_EQ(20.f,temp->get_temperature());
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
