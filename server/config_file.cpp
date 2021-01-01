#include "config_file.hpp"
#include "toml.hpp"
#include "lib/log.hpp"

using namespace std;

ConfigFile::ConfigFile(void) {
  return;
}

ConfigFile::ConfigFile(string file_location) {
  sys::Log log; 
  try {
    auto file = toml::parse(file_location);
    auto answer = toml::find<std::int64_t>(file, "answer");
    cout << "Answer is " << answer << endl;
  } catch (const std::exception& e) {
    cout << "Failed parse config file. Using defaults.\n";
    cout << e.what(); 
  }
}

ConfigFile::~ConfigFile(void) {
  return;
}

ConfigMap ConfigFile::GetMap(void) {
  
  return this->config_map_;
}
