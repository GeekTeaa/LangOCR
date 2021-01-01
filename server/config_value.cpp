/**
 *   \file config_value.cpp
 *   \brief Implements a configuration value type
 */


#include <iostream>
#include "config_value.hpp"

ConfigValue::ConfigValue(int val) {
  this->type_ = kValueTypeInteger;
  this->int_val_ = val;
}
ConfigValue::ConfigValue(bool val) {
  this->type_ = kValueTypeBoolean;
  this->bool_val_ = val;
}

ConfigValue::ConfigValue(std::string val) {
  this->type_ = kValueTypeString;
  this->string_val_ = val;
}

ConfigValue::ConfigValue(float val) {
  this->type_ = kValueTypeFloat;
  this->float_val_ = val;
}

ConfigValue::~ConfigValue() {
  return;
}

std::ostream& operator<<(std::ostream& os, const ConfigValue& c) {
  os << c.GetValue();
  return os;
}
