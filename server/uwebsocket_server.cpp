/**
 *   \file uwebsocket_server.cpp
 *   \brief A uWebSocket server instantiation. 
 *
 *  This is an implementation of an http rest server using uwebsockets.
 *
 */

#include <iostream>
#include <vector>
#include "config_file.hpp"
#include "uwebsocket_server.hpp"

using namespace std;

static ConfigMap default_uweb_configuration = {
  {"test_string" , string("A test") },
  {"port"        , int(100)         },
  {"test_bool"   , bool(true)       },
  {"test_float"  , float(1.0)       },
};

Server::Server() {
  this->LoadDefaultParameters();
}

Server::~Server() {

}

void Server::Start(void) {
  while(1);
}

void Server::LoadDefaultParameters(void) {
  ConfigFile config;

  //for( auto const& [key, val] : default_uweb_configuration) {
  //  std::cout << key         // string (key)
  //            << ':'  
  //            << val        // string's value
  //            << std::endl ;
  //}
}
