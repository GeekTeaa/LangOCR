/**
 *   \file config_value.hpp
 *   \brief Describes a configuration value and type
 *
 *  Should only be used ConfigFile to describe a value to configure
 *  the program with.
 *
 */

#ifndef _CONFIG_VALUE_H_
#define _CONFIG_VALUE_H_

#include <iostream>
#include <typeinfo>

using namespace std;

typedef enum _ValueType_ {
  kValueTypeError   = 0,
  kValueTypeBoolean = 1,
  kValueTypeInteger = 2,
  kValueTypeFloat   = 3,
  kValueTypeString  = 4
} ValueType;

class ConfigValue
{
 public:
  ConfigValue(int);
  ConfigValue(bool);
  ConfigValue(std::string);
  ConfigValue(float val);
  ~ConfigValue(void);

  auto GetValue(void) const {
    switch(this->type_) {
      case(kValueTypeInteger):
        return (int) this->int_val_;
      case(kValueTypeBoolean):
        return (bool) this->bool_val_;
      case(kValueTypeFloat):
        return (float) this->float_val_;
      case(kValueTypeString):
        return (string)this->string_val_;
      default:
        return NULL;
        break;
    }
      return this->GetValueFromType();};
  friend std::ostream& operator<<(std::ostream& os, const ConfigValue& c);

 private:
  ValueType   type_;
  bool        bool_val_;
  int         int_val_;
  std::string string_val_;
  float       float_val_;

};

std::ostream& operator<<(std::ostream& os, const ConfigValue& c);

#endif /* _CONFIG_VALUE_H_ */
