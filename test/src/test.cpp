#include "gtest/gtest.h"
#include <stdlib.h>

extern "C" {
#include "ft_printf.h"
};

void test_array_equality(int* array1, int* array2, int array_size) {
  for (int i = 0; i < array_size; i++) {
    ASSERT_EQ(array1[i], array2[i]);
  }
}

TEST(Dummy, Dummy) {
	ASSERT_EQ(1, 1);
}
