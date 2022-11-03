#include <gtest/gtest.h>
#include "include/thermostate/thermostate_controller.h"

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

TEST_F(ThermostateTest,ThermostateInitialState)
{
    EXPECT_EQ(21.f,thermo->get_temperature());
}

TEST_F(ThermostateTest,ThermostateInitialState)
{
    EXPECT_EQ(State::stop,thermo->get_thernostate_state());
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
