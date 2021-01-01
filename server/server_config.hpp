/**
 *   \file config_file.hpp
 *   \brief Cconfiguration parametters for the OCR Server
 */

#ifndef _SERVER_CONFIG_H_
#define _SERVER_CONFIG_H_

#include <iostream>

class ServerConfig
{
 public:
  ServerConfig(std::string file_location);
  ~ServerConfig();
};


#endif /* _SERVER_CONFIG_H_ */
