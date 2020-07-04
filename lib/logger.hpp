#ifndef _LIB_LOGGER_
#define _LIB_LOGGER_
#include <stdio.h>

namespace logger {
    class Logger {
    public:
        Logger(void);
        ~Logger(void);
        void printInfo(const char *format, ...);
    private:
        FILE *output_stream_;
    };

}

#endif 
