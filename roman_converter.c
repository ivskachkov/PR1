#include "roman_converter.h"

#define SAFE_WRITE(SP,E,C) \
    if(*SP == E){ \
        return STATUS_OUT_OF_BUFFER; \
    } \
    **SP = C; \
    (*SP)++;

const char ROMAN[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
const int ROMAN_MAX = 3999;
const int DOZENS_REDUCTION_MAX = 3;


static int convert(int value, char **out, char * end, char c1, char c5, char c10){
    if(value == 4){
        SAFE_WRITE(out, end, c1);
        SAFE_WRITE(out, end, c5);
    }else if(value == 9){
        SAFE_WRITE(out, end, c1);
        SAFE_WRITE(out, end, c10);
    }else{
        if(value > 4){
            SAFE_WRITE(out, end, c5);
            value = value - 5;
        }
        for(int i = 0; i < value; i++){
            SAFE_WRITE(out, end, c1);
        }
    }
    return STATUS_OK;
}

int convertA2R(int value, char *out, size_t size){
    int x = 0;
    int result = STATUS_OK;
    char * end = out + size;
    if(value < 1 || value > ROMAN_MAX){
        return STATUS_OUT_OF_RANGE;
    }
    for(int i = 1000, g = DOZENS_REDUCTION_MAX; i>0 && result == STATUS_OK; i /= 10, --g ){
        x = value/ i;
        value = value % i;
        result = convert(x, &out, end, ROMAN[g*2], ROMAN[g*2 + 1], ROMAN[g*2 +2]);
    }
    return result;
}