#ifndef BYTE_ARRAY_H
#define BYTE_ARRAY_H

typedef struct {
    char v[65535];
} byte_array_t;

unsigned int byte_array_size(byte_array_t _byte_array);

#endif
