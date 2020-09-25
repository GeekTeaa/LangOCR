/**
 *   \file uwebsocket_server.hpp
 *   \brief The header module for uwebsocket style server
 */

#ifndef UWEBSOCKET_SERVER_H
#define UWEBSOCKET_SERVER_H

#include "server_config.hpp"

namespace uwebsocket {
namespace http {

class Server {
 public:
  Server(ServerConfig config);
  virtual ~Server(); 
};


}  // http
}  // uwebsocket

#endif /* UWEBSOCKET_SERVER_H */
