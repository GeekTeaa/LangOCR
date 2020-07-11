#include "lib/log.hpp"
#include <unistd.h>
#include "ocr_server.hpp"

void ocrserver::OcrServer::StartServer(void) {
  sys::Log log;
  log.Info("Starting OCR Server\r\n");
  sleep(10);
}
