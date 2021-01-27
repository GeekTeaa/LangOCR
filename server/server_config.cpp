/**
 *   \file server_config.cpp
 *   \brief Implements the ServerConfig class
 */

#include <iostream>
#include <string>
#include <algorithm>
#include "server_config.hpp"

static ConfigMap default_server_config = {
  {"port", int(2000)},
};

ServerConfig::ServerConfig(void) {
  this->LoadDefaults();
}

ServerConfig::~ServerConfig(void) {
  return;
}

void ServerConfig::LoadDefaults(void) {
  this->param_map_ = default_server_config;
}

ConfigMap ServerConfig::GetDefaultParameters(void) {
  return default_server_config;
}

void ServerConfig::Set(std::string key, int value) {
  this->param_map_[key] = value;
}

bool ServerConfig::WriteAsTomlFile(std::string file_location) {
  std::fstream fs;

  try {
    fs.open (file_location, std::fstream::out | std::fstream::trunc);
    fs << std::setw(80) << this->toml_config_ << std::endl;
    fs.close();
  } catch (std::exception &e) {
    std::cout << e.what();
  }
  return true;
}

void ServerConfig::Read(std::string file_location) {
  this->toml_config_ = toml::parse(file_location);
}
