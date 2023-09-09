#include "roman_converter.h"

const char ROMAN[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
const int ROMAN_MAX = 3999;
const int DOZENS_REDUCTION_MAX = 3;


char* convert(int value, char *out, char c1, char c5, char c10){
    if(value == 4){
        *out++ = c1;
        *out++ = c5;
    }else if(value == 9){
        *out++ = c1;
        *out++ = c10;
    }else{
        if(value > 4){
            *out++ = c5;
            value = value - 5;
        }
        for(int i = 0; i < value; i++){
            *out++ = c1;
        }
    }
    return out;
}

int convertA2R(int value, char *out){
    int x = 0;
    if(value < 1 || value > ROMAN_MAX){
        return STATUS_OUT_OF_RANGE;
    }
    for(int i = 1000, g = DOZENS_REDUCTION_MAX; i>0; i /= 10, --g ){
        x = value/ i;
        value = value % i;
        out = convert(x, out, ROMAN[g*2], ROMAN[g*2 + 1], ROMAN[g*2 +2]);
    }
    return STATUS_OK;
}