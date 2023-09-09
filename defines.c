#include "defines.h"
#include <stdio.h>

void printStatus(int status){
    switch (status)
    {
    case STATUS_OK:
        LOG("Status %s \n", "OK"); 
        break;
    case STATUS_OUT_OF_RANGE:
        ERR("Status %s \n", "Out of range"); 
        break;
    case STATUS_OUT_OF_BUFFER:
        ERR("Status %s \n", "Out of buffer"); 
        break;

    default:
        ERR("Status %s \n", "undefiend");
        break;
    }
}
