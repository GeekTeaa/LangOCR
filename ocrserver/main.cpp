#include <iostream>
#include "cpprest/json.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>
#include <lib/log.hpp>
#include "ocr_server.hpp"
#include "ocr_server_signals.hpp"

static void MakeProcessIntoDaemon(void);
static void ForkAndTerminateParent(void);
static void SetSessionId(void);
static void UpdateProgramPermissions(void);
static void CloseAllOpenFileDescriptors(void);
static void StartOcrServer(void);

int main(int argc, char *argv[]) {
  MakeProcessIntoDaemon();
  StartOcrServer();
  exit(EXIT_SUCCESS);
}

static void MakeProcessIntoDaemon(void) {
  signals::SignalInitializer signals;
  
  ForkAndTerminateParent();
  SetSessionId(); 
  signals.SetUpSignalHandling();
  UpdateProgramPermissions();
  chdir("/");
  CloseAllOpenFileDescriptors();
}

static void ForkAndTerminateParent(void) {
  pid_t pid = fork();

  // Error Handling 
  if (pid < 0) exit(EXIT_FAILURE);
  // Terminate the parent. 
  if (pid > 0) exit(EXIT_SUCCESS);
}

static void SetSessionId(void) {
  if (setsid() < 0) exit(EXIT_FAILURE);
}

static void UpdateProgramPermissions(void) {
  // 770 - User and Group has Read, Write, and Execute privileges 
  umask(S_IRWXG | S_IRWXU);
}

static void CloseAllOpenFileDescriptors(void) {
  for (int x = sysconf(_SC_OPEN_MAX); x>=0; x--)
  {
    close (x);
  }
}

static void StartOcrServer(void) {
  ocrserver::OcrServer ocr; 
  ocr.StartServer(); // We should never exit this funciton
}
