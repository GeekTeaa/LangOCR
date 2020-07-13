#include <stdio.h>
#include <stdarg.h>
#include <syslog.h>
#include "log.hpp"

const int kMaximumBufferSize = 256;
const int kLogOptions = LOG_CONS | LOG_PID;
const int kLogFacilities = LOG_DAEMON;

sys::Log::Log() {
  openlog(NULL, kLogOptions, kLogFacilities);
  return;
}

sys::Log::~Log() {
  closelog();
}

void sys::Log::Critical(const char *format, ...) {
  char buffer[kMaximumBufferSize];
  va_list args;
  va_start (args, format);
  vsyslog (LOG_CRIT, format, args);
  va_end (args);
}

void sys::Log::Error(const char *format, ...) {
  char buffer[kMaximumBufferSize];
  va_list args;
  va_start (args, format);
  vsyslog (LOG_ERR, format, args);
  va_end (args);
}

void sys::Log::Warning(const char *format, ...) {
  char buffer[kMaximumBufferSize];
  va_list args;
  va_start (args, format);
  vsyslog (LOG_WARNING, format, args);
  va_end (args);
}

void Notice(const char *format, ...) {
  char buffer[kMaximumBufferSize];
  va_list args;
  va_start (args, format);
  vsyslog (LOG_NOTICE, format, args);
  va_end (args);
}

void sys::Log::Info(const char *format, ...) {
  char buffer[kMaximumBufferSize];
  va_list args;
  va_start (args, format);
  vsyslog (LOG_INFO, format, args);
  va_end (args);
}

void sys::Log::Debug(const char *format, ...) {
  char buffer[kMaximumBufferSize];
  va_list args;
  va_start (args, format);
  vsyslog (LOG_DEBUG, format, args);
  va_end (args);
}
