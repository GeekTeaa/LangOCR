#include <csignal>
#include <vector>
#include <stdlib.h>
#include "lib/log.hpp"
#include "ocr_server_signals.hpp"

static void HandleInterruptSignal(int signum);
static void HandleSegmentationFaultSignal(int signum);

signals::Signal AllSignals[] = {
  {.sig = SIGINT, .func = HandleInterruptSignal},
  {.sig = SIGSEGV , .func = HandleSegmentationFaultSignal}
};

const int kSizeOfSignalList = (sizeof(AllSignals)/sizeof(AllSignals[0]));

void signals::SignalInitializer::SetUpSignalHandling(void) {
  
}

static void HandleInterruptSignal(int signum) {
  sys::Log log;
  log.Info("Interrupt Signal Received: %d\r\n", signum);
  // TODO Add graceful shutdown logic
  exit(signum);
}

static void HandleSegmentationFaultSignal(int signum) {
  sys::Log log;
  log.Info("Segmentation Fault Signal Received: %d\r\n", signum);
  // TODO Add system core dump from segmentation fault. 
  exit(signum);
}
