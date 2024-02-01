#include "unity.h"
#include "unity_fixture.h"

static void runAllTests()
{
    RUN_TEST_GROUP(ReturnValue);
    RUN_TEST_GROUP(LexemeList);
    RUN_TEST_GROUP(ParseLexemes);
}

int main(int ac, const char** av)
{
    UnityBegin("ft_printf");
    return (UnityMain(ac, av, runAllTests));
}
