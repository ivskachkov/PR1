#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void convert(int value, char *out){
    char c1 = 'X';
    char c5 = 'L';
    char c10 = 'C';
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
}

int main(int argc, char **argv){
    char str[5] = {'\0'};
    int value = atoi(argv[1]);
    convert(value, str);
    printf("%s \n", str);

    int a = 7;
    int *p = &a;
    *p = 78;
    printf("%d \n" , a);
    return 0;
}
