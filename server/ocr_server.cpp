#include <thread>
#include <chrono>
#include "lib/log.hpp"
#include "ocr_server.hpp"

void ocrserver::OcrServer::StartServer(void) {
  sys::Log log;
  log.Notice("Starting OCR Server\r\n");
}
