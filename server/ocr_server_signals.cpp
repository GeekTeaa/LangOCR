#include <csignal>
#include <vector>
#include <stdlib.h>
#include "lib/log.hpp"
#include "ocr_server_signals.hpp"

static void HandleInterruptSignal(int signum);
static void HandleSegmentationFaultSignal(int signum);
static void HandleHangupSignal(int signum);
// TODO I don't like this module as it currently is, but it will do
// for now. I want to be able to add function calls to a list of
// called functions when a signal is fired.
// e.x. SignalHandler.addSignalResponse(SIGHUP, someFunctionPointer);

static signals::Signal all_signals[] = {
  {.sig = SIGHUP, .func = HandleSegmentationFaultSignal},
  {.sig = SIGINT, .func = HandleInterruptSignal},
  {.sig = SIGSEGV , .func = HandleHangupSignal}
};

const int kSizeOfSignalList = (sizeof(all_signals)/sizeof(all_signals[0]));

void signals::SignalInitializer::SetUpSignalHandling(void) {
  signals::Signal handler;
  for (int i = 0; i < kSizeOfSignalList; i++) {
    handler = all_signals[i];
    signal(handler.sig, handler.func);
  }
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

static void HandleHangupSignal(int signum) {
  sys::Log log;
  log.Info("Hangeup Signal Recieved: %d\r\n", signum);
  // TODO Add system core dump from segmentation fault. 
  exit(signum);  
}
