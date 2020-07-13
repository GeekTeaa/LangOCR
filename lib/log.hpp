#ifndef _LIB_LOGGER_
#define _LIB_LOGGER_
#include <stdio.h>

namespace sys {
class Log {
 public:
  Log(void);
  ~Log(void);
  void Critical(const char *format, ...);
  void Error(const char *format, ...);
  void Warning(const char *format, ...);
  void Notice(const char *format, ...);
  void Info(const char *format, ...);
  void Debug(const char *format, ...);
};
}

#endif 
