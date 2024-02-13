#include "gtest/gtest.h"
#include <stdlib.h>

extern "C" {
#include "ft_printf.h"
};

TEST(ReturnValue, Empty) {
	int expected = 0;
	int actual = ft_printf("");

	ASSERT_EQ(expected, actual);
}
