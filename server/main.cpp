#include <stdlib.h>
#include "daemonize_process.h"
#include "ocr_server.hpp"
#include "ocr_server_signals.hpp"
#include "server_config.hpp"

const std::string kDefaultConfigFile = "~/proj/langOCR/server/.config";
static void StartOcrServer(void);

int main(int argc, char *argv[]) {
  Port port(10);
  ConfigParam par;
  printf("Port size = %d\n", port.size_);
  printf("ConfigParam size = %d\n", par.size_);
  
  //signals::SignalInitializer signals; 
  //MakeProcessIntoDaemon();
  //signals.SetUpSignalHandling();
  //StartOcrServer();
  //exit(EXIT_SUCCESS);
}

static void StartOcrServer(void) {
  OcrServer ocr;
  ocr.LoadConfigFile(kDefaultConfigFile);
  ocr.StartServer(); // We should never exit this function
}
