#ifndef _SERVER_DAEMONIZE_PROCESS_H_
#define _SERVER_DAEMONIZE_PROCESS_H_

// MakeProcessIntoDaemon
//
// Turn the current process into a Daemon process.
//
// This should only be called once in any process. After this is
// called, the process will continue in the background until the
// process terminates.
void MakeProcessIntoDaemon(void);

#endif 
