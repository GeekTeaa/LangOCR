/**
 *   \file config_value_test.cpp
 *   \brief GTest for the ConfigValue class.
 */

#include "config_value.hpp"
#include "gtest/gtest.h"

TEST(ConfigValueTest, Initialization) {
  EXPECT_EQ(1, ConfigValue(1));
}
