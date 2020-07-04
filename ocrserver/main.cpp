#include <iostream>
#include "cpprest/json.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>
#include <lib/logger.hpp>
#include "ocr_server_signals.hpp"

static void makeProcessIntoDaemon(void);

int main(int argc, char *argv[]) {
  makeProcessIntoDaemon();

}

static void makeProcessIntoDaemon(void) {
  pid_t pid;
  signals::SignalInitializer signal_init;

  pid = fork();

  if (pid < 0) exit(EXIT_FAILURE);

  // Terminate the parent. 
  if (pid > 0) exit(EXIT_SUCCESS);

  // Make the child fork the session leader.
  if (setsid() < 0) exit(EXIT_FAILURE);

  logger::Logger log;
  log.printInfo("See, It's working!\r\n");
  signal_init.SetUpSignalHandling();
  sleep(10);
  exit(EXIT_SUCCESS);
}
