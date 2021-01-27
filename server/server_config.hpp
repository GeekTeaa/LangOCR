/**
 *   \file config_file.hpp
 *   \brief Cconfiguration parametters for the OCR Server
 */

#ifndef _SERVER_CONFIG_H_
#define _SERVER_CONFIG_H_

#include <iostream>
#include <map>
#include <exception>
#include "toml.hpp"

using namespace std;

typedef std::map<string, int> ConfigMap;

class ServerConfig {
 public:
  ServerConfig();
  ~ServerConfig();
  ConfigMap GetParameters(void) const { return this->param_map_;};
  ConfigMap GetDefaultParameters(void);

  void Set(string, int);
  void Read(string);
  bool WriteAsTomlFile(string file_location);

 private:
  void LoadDefaults(void);
  toml::value toml_config_;
  ConfigMap param_map_;

};

#endif /* _SERVER_CONFIG_H_ */
