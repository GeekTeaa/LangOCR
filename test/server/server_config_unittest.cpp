/**
 *   \file server_config_unittest.cpp
 *   \brief Unit test for ServerConfig class
 */

#include <iostream>
#include <stdio.h>
#include <map>
#include "server_config.hpp"
#include "gtest/gtest.h"

std::vector<std::string> toml_small_ex = {
  "# This example only tests a single config param",
  "port = 1000 "
};

//< Example taken from https://github.com/toml-lang/toml
std::vector<std::string> toml_full_ex = {
  "# This is a TOML document.",
  "",
  "title = \"TOML Example\"",
  "",
  "[owner]",
  "name = \"Tom Preston-Werne\"",
  "dob = 1979-05-27T07:32:00-08:00 # First class dates",
  "",
  "[database]",
  "server = \"192.168.1.1\"",
  "ports = [ 8001, 8001, 8002 ]",
  "connection_max = 5000",
  "enabled = true",
  "",
  "[servers]",
  "",
  "  # Indentation (tabs and/or spaces) is allowed but not required",
  "  [servers.alpha]",
  "  ip = \"10.0.0.1\"",
  "  dc = \"eqdc10\"",
  "",
  "  [servers.beta]",
  "  ip = \"10.0.0.2\"",
  "  dc = \"eqdc10\"",
  "",
  "[clients]",
  "data = [ [\"gamma\", \"delta\"], [1, 2] ]",
  "",
  "# Line breaks are OK when inside arrays",
  "hosts = [",
  "  \"alpha\",",
  "  \"omega\"",
  "]",
};

static void WriteTomlFile(std::string file) {
    fstream fs;
    fs.open(file, fstream::out);
    for (int i = 0; i < toml_full_ex.size(); i++) {
      fs << toml_full_ex[i] << std::endl;
    }
    fs.close();
}

static void DeleteTomlFile(std::string file) {
  if (remove(file.c_str()))
    FAIL() << "Failed to delete example toml file\n";
}

// The fixture for testing class Foo.
class ServerConfigTest : public ::testing::Test {
 protected:
  std::string toml_file = "./unittest.toml";
  ServerConfigTest() {
    WriteTomlFile(this->toml_file);
  }

  ~ServerConfigTest() override {
     // You can do clean-up work that doesn't throw exceptions here.
    DeleteTomlFile(this->toml_file);
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  void SetUp() override {
     // Code here will be called immediately after the constructor (right
     // before each test).
  }

  void TearDown() override {
     // Code here will be called immediately after each test (right
     // before the destructor).
  }

  // Class members declared here can be used by all tests in the test suite
  // for Foo.
};


TEST(ServerConfigTest, DefaultInit) {
  ServerConfig config;
  ConfigMap params = config.GetParameters();
  ConfigMap default_params = config.GetDefaultParameters();
  ConfigMap::iterator param = params.begin();

  while(param != params.end()) {
    // Expect that the initialized map is same as the default map
    EXPECT_EQ(param->second, default_params[param->first]);
    param++;
  }
}

TEST(ServerConfigTest, UpdateValue) {
  ServerConfig config;
  ConfigMap params = config.GetParameters();
  ConfigMap default_params = config.GetDefaultParameters();
  int port = (default_params["port"] + 1);

  config.Set("port", port);
  params = config.GetParameters();
  EXPECT_EQ(params["port"], port);
}
