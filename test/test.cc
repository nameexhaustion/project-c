#include "gtest/gtest.h"

extern "C" {
#include "lib.h"
}

TEST(something, add) {
  int a = 2;
  int b = 3;
  int r = add(a, b);
  ASSERT_EQ(r, 5);
}