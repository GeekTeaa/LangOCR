#include <thread>
#include <chrono>
#include "lib/log.hpp"
#include "ocr_server.hpp"

void ocrserver::OcrServer::StartServer(void) {
  sys::Log log;
  log.Info("Starting OCR Server\r\n");
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
}
