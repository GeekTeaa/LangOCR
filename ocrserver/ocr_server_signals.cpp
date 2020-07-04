#include <csignal>
#include <vector>
#include <stdlib.h>
#include "lib/logger.hpp"
#include "ocr_server_signals.hpp"

static void HandleInterruptSignal(int signum);
static void HandleSegmentationFaultSignal(int signum);

signals::Signal AllSignals[] = {
  {.sig = SIGINT, .func = HandleInterruptSignal},
  {.sig = SIGSEGV , .func = HandleSegmentationFaultSignal}
};

void signals::SignalInitializer::SetUpSignalHandling(void) {
  
}

static void HandleInterruptSignal(int signum) {
  logger::Logger log;
  log.printInfo("Interrupt Signal Received: %d\r\n", signum);
  // TODO Add graceful shutdown logic
  exit(signum);
}

static void HandleSegmentationFaultSignal(int signum) {
  logger::Logger log;
  log.printInfo("Segmentation Fault Signal Received: %d\r\n", signum);
  // TODO Add system core dump from segmentation fault. 
  exit(signum);
}
