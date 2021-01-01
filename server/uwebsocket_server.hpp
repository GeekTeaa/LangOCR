/**
 *   \file uwebsocket_server.hpp
 *   \brief The header module for uwebsocket style server
 */

#ifndef UWEBSOCKET_SERVER_H
#define UWEBSOCKET_SERVER_H

#include "server_config.hpp"

class Server {
 public:
  Server();
  ~Server();
  void Start(void);
 private:
  void LoadDefaultParameters(void);
};

#endif /* UWEBSOCKET_SERVER_H */
