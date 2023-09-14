#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "roman_converter.h"
#include "defines.h"
#include <getopt.h>
#include <ctype.h>

#define BUFFER_SIZE 16
#define END_SYMBOL 27

int isNumber(const char *str){
    int size = strlen(str);
    for(int i = 0; i < size; ++i){
        if(!isdigit(str[i])){
            return STATUS_NOT_A_DIGIT;
        }
    }
    return STATUS_OK;
}

int main(int argc, char **argv){
    char str[BUFFER_SIZE] = {'\0'};
    int result;
    int value;
    while (TRUE){
        result = 0;
        value = 0;
        LOG("Enter the value in range from 1 to %d \n", ROMAN_MAX);
        scanf("%15s", str);
        if(str[0] == END_SYMBOL){
            LOG("Status %s\n", "closing application");
            return STATUS_OK;
        }
        result = isNumber(str);
        if(result != STATUS_OK){
            printStatus(result);
            continue;
        }
        value = atoi(str);
        result = convertA2R(value, str, BUFFER_SIZE);
        if(result != STATUS_OK){
            printStatus(result);
            continue;
        }
        LOG("%s \n", str);
    }
    return STATUS_OK;
}
