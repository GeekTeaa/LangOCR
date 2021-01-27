#include <stdlib.h>
#include "daemonize_process.h"
#include "ocr_server.hpp"
#include "ocr_server_signals.hpp"
#include "server_config.hpp"

const std::string kDefaultConfigFile = "~/repo/langocr/server/tests/toml_ex.toml";
static void StartOcrServer(void);

int main(int argc, char *argv[]) {
  signals::SignalInitializer signals; 
  //MakeProcessIntoDaemon();
  //signals.SetUpSignalHandling();
  StartOcrServer();
  exit(EXIT_SUCCESS);
}

static void StartOcrServer(void) {
  OcrServer ocr;
  ocr.StartServer(); // We should never exit this function
}
