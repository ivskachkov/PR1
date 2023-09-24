#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "roman_converter.h"
#include "defines.h"
#include <getopt.h>
#include "utils.h"

#define BUFFER_SIZE 16
#define END_SYMBOL 27

int main(int argc, char **argv){
    char str[BUFFER_SIZE] = {'\0'};
    int result;
    int value;
    printf("To close application put Ctrl + C or Esc + Enter\n");
    do{
        result = 0;
        value = 0;
        LOG("Enter integer in range from 1 to %d \n", ROMAN_MAX);
        result = readNumber(str, BUFFER_SIZE);
        if(result == STATUS_OK){
            value = atoi(str);
            result = convertA2R(value, str, BUFFER_SIZE);
            if(result != STATUS_OK){
                printStatus(result);
                continue;
            }
            LOG("%s \n", str);
        }else{  
            printStatus(result);
        }
    }while(str[0] != END_SYMBOL);
    return STATUS_OK;
}















