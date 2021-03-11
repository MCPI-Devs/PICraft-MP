#ifndef BUFFER_H
#define BUFFER_H

typedef struct {
    char v[65535];
} byte_array_t;

typedef struct {
    byte_array_t data;
    unsigned int pos;
    unsigned int w_pos;
} buffer_t;

unsigned int byte_array_size(byte_array_t _byte_array);

void reset_buffer(buffer_t *_buffer);

void write_buffer(buffer_t *_buffer, byte_array_t _byte_array);

byte_array_t read_buffer(buffer_t *_buffer, unsigned int length);

unsigned int end_of_buffer(buffer_t *_buffer);

unsigned long long read_unum(buffer_t *_buffer, unsigned int length, char *byte_order);

void write_unum(buffer_t *_buffer, unsigned long long value, unsigned int length, char *byte_order);

#endif
