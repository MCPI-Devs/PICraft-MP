#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utils/byte_array.h>

unsigned int byte_array_size(byte_array_t _byte_array) {
    return (sizeof(_byte_array.v) / sizeof(_byte_array.v[0]));
}
