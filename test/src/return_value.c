#include "ft_printf.h"
#include "unity_fixture.h"

#include <stdio.h>

TEST_GROUP(ReturnValue);
TEST_SETUP(ReturnValue) {}
TEST_TEAR_DOWN(ReturnValue) {}

TEST(ReturnValue, DummyTest)
{
    int expected = 0;
    int actual = ft_printf("");

    char error[100];
    sprintf(error, "Error found, expected %d was %d", expected, actual);
    TEST_ASSERT_MESSAGE(expected == actual, error);
}

TEST_GROUP_RUNNER(ReturnValue)
{
    printf("\e[34m----- ReturnValue -----\e[0m\n");
    RUN_TEST_CASE(ReturnValue, DummyTest);
}
