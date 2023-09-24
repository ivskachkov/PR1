#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defines.h"
#include <ctype.h>

static int isNumber(const char *str){
    int size = strlen(str);
    for(int i = 0; i < size; ++i){
        if(!isdigit(str[i])){
            return STATUS_NOT_A_DIGIT;
        }
    }
    return STATUS_OK;
}

int readNumber(char *str, int maxSize){
    int str_size;
    fgets(str, maxSize, stdin);
    str_size = strlen(str);
    if ((str_size > 0) && (str[str_size - 1] == '\n'))
        str[str_size - 1] = '\0';
    return isNumber(str);
}