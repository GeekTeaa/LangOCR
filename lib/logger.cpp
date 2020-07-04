#include "stdio.h"
#include "stdarg.h"
#include "logger.hpp"

const int kMaximumBufferSize = 256;
const char* kDefaultFileOutput = "./log.txt";

logger::Logger::Logger() {
    this->output_stream_ = fopen(kDefaultFileOutput, "w");
    if (this->output_stream_ == NULL) perror("Error opening file");
    return;
}

logger::Logger::~Logger() {
    fclose(this->output_stream_);
}

void logger::Logger::printInfo(const char *format, ...) {
    char buffer[kMaximumBufferSize];
    va_list args;
    va_start (args, format);
    vfprintf (this->output_stream_, format, args);
    va_end (args);
    fflush(this->output_stream_);
}
