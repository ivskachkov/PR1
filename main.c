#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "roman_converter.h"
#include "defines.h"



int main(int argc, char **argv){
    char str[16] = {'\0'};
    int result = 0;
    int value = atoi(argv[1]);
    result = convertA2R(value, str);
    if(result != STATUS_OK){
        ERR("error - value out of range. Enter value from range from 1 to %d\n", ROMAN_MAX);
        return result;
    }
    LOG("%s \n", str);
    return STATUS_OK;
}
