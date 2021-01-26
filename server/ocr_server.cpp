#include "uwebsocket_server.hpp"
#include "server_config.hpp"
#include "lib/log.hpp"
#include "ocr_server.hpp"

using namespace sys;
using namespace std;

OcrServer::OcrServer(void) {
  this->server_ = new Server();
}

OcrServer::~OcrServer(void) {
  delete server_;
}

void OcrServer::StartServer(void) {
  Log log;
  log.Notice("Starting OCR Server\r\n");
  server_->Start();
}
