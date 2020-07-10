#include "daemonize_process.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>

static void ForkAndTerminateParent(void);
static void SetSessionId(void);
static void UpdateProgramPermissions(int);
static void CloseAllOpenFileDescriptors(char *);

// The process outlined in this function for daemonization of a
// process is standard practice for creating Daemons in a Linux
// environment. For the sake of potential contributors who may not be
// familiar with Linux software best practices, I will be adding
// superfluous comments to this module.

// TODO Make a version for Windows and Mac OS 
void MakeProcessIntoDaemon(void) {
  
  // Assuming the process is started by command line, this allows the
  // process to continue as a child thread in the background and
  // relinquish control back to the terminal. 
  ForkAndTerminateParent();

  // Setting a session Id ensures that the process is not associated
  // with any terminal.
  SetSessionId();

  // Technically speaking, this process can open a terminal device
  // after it becomes a daemon. In Linux, this is prevented by forking
  // again because it is no longer a session leader.
  ForkAndTerminateParent();

  // Updates the program permissions. This stops the process from
  // touching files it has no control over. 
  UpdateProgramPermissions(0);

  // Change to a directory of operation. Root directory is preferred
  // since it prevents relative file pathing within the program. This
  // can be changed if appropriate.
  ChangeDirectoryTo("/");

  // By default, a process has stdin, stdout, and stderr open in a
  // linux system. Since a daemon is not associated with a terminal,
  // these file descriptors should be closed so they are not
  // accidentally written to. (e.x. printf writes to stdout)
  CloseAllOpenFileDescriptors();

  // Lastly, open the standard stdin, stdout, and stderr (0, 1, and 2)
  // for file /dev/null. This way any time these file descriptors are
  // written to they won't cause unexpected behavior when those calls fail.
  OpenStdInOutAndErrorToDevNull();
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

static void UpdateProgramPermissions(int usr_perissions) {
  umask(usr_permissions);
}

static void CloseAllOpenFileDescriptors(void) {
  for (int x = sysconf(_SC_OPEN_MAX); x>=0; x--) {
    close (x);
  }
}

static ChangeDirectoryTo(char *dir) {
  chdir(dir);
}

static void OpenStdInOutAndErrorToDevNull(void) {
  close(STDIN_FILENO);
  
  int fd = open("/dev/null", O_RDWR);

  if (fd != STDIN_FILENO) exit(EXIT_FAILURE);
  if (dup2(STDIN_FILENO, STDOUT_FILENO) != STDOUT_FILENO) exit(EXIT_FAILURE);
  if (dup2(STDIN_FILENO, STDERR_FILENO) != STDERR_FILENO) exit(EXIT_FAILURE);
}
