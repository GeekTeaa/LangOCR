/**
 *   \file ocr_server.hpp
 *   \brief Describes the OCR Server
 *
 *  Detailed description
 *
 */

#ifndef _OCRSERVER_OCR_SERVER_H_
#define _OCRSERVER_OCR_SERVER_H_

#include "uwebsocket_server.hpp"

using namespace http::uwebsocket;

class OcrServer {
 public:
  OcrServer(void);
  ~OcrServer(void);
  void StartServer();
  ServerConfig* LoadConfigFile(std::string file_location); 
 private:
  Server *server_;
  ServerConfig *config_;
};

#endif 
