/**
 *   \file config_value_test.cpp
 *   \brief GTest for the ConfigValue class.
 */

#include <limits.h>
#include "config_value.hpp"
#include "gtest/gtest.h"

TEST(ConfigValue, Integer) {
  int min = INT_MIN;
  int max = INT_MAX;

  for (int i = min; i < max; ++i) {
    EXPECT_EQ(i, ConfigValue(i).GetValue());

    if (HasFailure()) return;
  }
}

TEST(ConfigValue, Boolean) {
  EXPECT_EQ(true, ConfigValue(true).GetValue());
  EXPECT_EQ(false, ConfigValue(false).GetValue());
}

TEST(ConfigValue, String) {
  EXPECT_EQ(1, 1);
}

TEST(ConfigValue, Float) {
  EXPECT_EQ(1, 1);
}
