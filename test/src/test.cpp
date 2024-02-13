#include <stdlib.h>
#include "gtest/gtest.h"

extern "C"
{
#include "ft_printf.h"
};

TEST(ReturnValue, Empty)
{
    int expected = 0;
    int actual = ft_printf("");

    ASSERT_EQ(expected, actual);
}
