#ifndef DEFINES_H
#define DEFINES_H

#define ERR(FORMAT,...) fprintf(stderr, FORMAT, __VA_ARGS__)
#define LOG(FORMAT,...) fprintf(stdout, FORMAT, __VA_ARGS__)


#define STATUS_OK                   0
#define STATUS_OUT_OF_RANGE         1
#define STATUS_OUT_OF_BUFFER        2

void printStatus(int status);
#endif//DEFINES_H

