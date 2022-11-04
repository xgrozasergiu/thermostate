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
    thermo->set_temperature(30.f);
    EXPECT_EQ(30.f,thermo->get_temperature());
}


int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
