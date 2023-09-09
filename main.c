#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "roman_converter.h"
#include "defines.h"
#include <getopt.h>

static const int BUFFER_SIZE = 16;

int main(int argc, char **argv){

    char str[16] = {'\0'};
    int result = 0;
    int value =  0;//atoi(argv[1]);
    if(argc > 1){
        char c = 0;
        // Get a string representation of value
        while ( (c = getopt(argc, argv, "hv:")) != -1 ) {
            switch (c){
            case 'v':
                value = atoi(optarg);
                break;
            case 'h':
                LOG("Usage %s -v value\n", argv[0]);
                return STATUS_OK;
            }
        }
        //value = atoi(argv[1]);
    }else{
        LOG("Enter the value in range from 1 to %d \n", ROMAN_MAX);
        scanf("%u", &value);
    }
    result = convertA2R(value, str, BUFFER_SIZE);
    if(result != STATUS_OK){
        printStatus(result);
        return result;
    }
    LOG("%s \n", str);
    return STATUS_OK;
}
