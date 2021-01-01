/**
 *   \file config_file.hpp
 *   \brief Configuration parametters for the OCR Server
 */

#ifndef _CONFIG_FILE_H_
#define _CONFIG_FILE_H_

#include <iostream>
#include <map>
#include "config_value.hpp"

using namespace std;

typedef map<string, ConfigValue> ConfigMap;

class ConfigFile
{
 public:
  ConfigFile(string file_location);
  ConfigFile(void);
  ~ConfigFile();
  ConfigMap GetMap(void);

 private:
  ConfigMap config_map_;
};

#endif /* _CONFIG_FILE_H_ */

