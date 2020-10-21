/**
 *   \file uwebsocket_server.hpp
 *   \brief The header module for uwebsocket style server
 */

#ifndef UWEBSOCKET_SERVER_H
#define UWEBSOCKET_SERVER_H

#include "server_config.hpp"

namespace http {
namespace uwebsocket {

class Server {
 public:
  Server();
  ~Server();
  void Start(void);
};


}  // uwebsocket
}  // http

#endif /* UWEBSOCKET_SERVER_H */
