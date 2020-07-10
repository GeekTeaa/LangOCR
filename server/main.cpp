#include <stdlib.h>
#include "daemonize_process.h"
#include "ocr_server.hpp"
#include "ocr_server_signals.hpp"

static void StartOcrServer(void);

int main(int argc, char *argv[]) {
  // Upon failure, the program exits before we start the OCR Server.
  MakeProcessIntoDaemon();
  StartOcrServer();
  exit(EXIT_SUCCESS);
}

static void StartOcrServer(void) {
  ocrserver::OcrServer ocr; 
  ocr.StartServer(); // We should never exit this function
}
