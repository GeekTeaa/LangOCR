#include "server_config.hpp"
#include "uwebsocket_server.hpp"
#include "lib/log.hpp"
#include "ocr_server.hpp"

using namespace sys;
using namespace std;

OcrServer::OcrServer(void) {
  this->server_ = new Server();
  this->config_ = new ServerConfig();
}

OcrServer::~OcrServer(void) {
  delete server_;
  delete config_;
}

void OcrServer::StartServer(void) {
  Log log;
  log.Notice("Starting OCR Server\r\n");
  server_->Start();
}

ServerConfig* OcrServer::LoadConfigFile(string file_location) {
  Log log;
  try {
    this->config_ =  NULL;
  } catch (const std::exception& e) {
    log.Error("Failed to open config file. Reason: %s", e.what());
  }
  return NULL;
}
