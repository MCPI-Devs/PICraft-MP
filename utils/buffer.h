#ifndef BUFFER_H
#define BUFFER_H

typedef struct {
    byte_array_t data;
    int pos;
} buffer_t;

void reset_buffer(buffer_t *_buffer);

void write_buffer(buffer_t *_buffer, char *data);

char* read_buffer(buffer_t *_buffer, unsigned int length);

unsigned int end_of_buffer(buffer_t *_buffer);

unsigned long long read_unum(buffer_t *_buffer, unsigned int length, char *byte_order);

void write_unum(buffer_t *_buffer, unsigned long long value, unsigned int length, char *byte_order);

#endif
