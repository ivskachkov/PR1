#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "roman_converter.h"
#include "defines.h"
#include <getopt.h>



#define BUFFER_SIZE 16

int main(int argc, char **argv){
    char str[BUFFER_SIZE] = {'\0'};
    int result = 0;
    int value =  0;
    while (TRUE){
        value = 0;
        LOG("Enter the value in range from 1 to %d \n", ROMAN_MAX);
        scanf("%u", &value);
    
        result = convertA2R(value, str, BUFFER_SIZE);
        if(result != STATUS_OK){
            printStatus(result);
            //return result;
        }else {
            LOG("%s \n", str);
        }
    }
    return STATUS_OK;
}
