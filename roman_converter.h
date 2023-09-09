#ifndef ROMAN_CONVERTER_H
#define ROMAN_CONVERTER_H
#include <stddef.h>
#include "defines.h"


extern const int ROMAN_MAX;

int convertA2R(int value, char *out, size_t size);

#endif//ROMAN_CONVERTER_H