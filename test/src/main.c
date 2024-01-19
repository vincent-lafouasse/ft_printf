#include "my_lib.h"
#include "unity.h"
#include "unity_fixture.h"

static void runAllTests()
{
    RUN_TEST_GROUP(Module);
}

int main(int ac, const char** av)
{
    UnityBegin("ft_rintf");
    return (UnityMain(ac, av, runAllTests));
}
