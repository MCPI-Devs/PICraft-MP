#ifndef BUFFER_H
#define BUFFER_H

typedef struct {
    char data[65535];
    unsigned int r_pos;
    unsigned int w_pos;
} buffer_t;

buffer_t new_buffer();

char read_one(buffer_t *buffer);

void write_one(buffer_t *buffer, char one);

void reset_buffer(buffer_t *buffer);

int read_int_le(buffer_t *buffer);

void write_int_le(buffer_t *buffer, int value);

#endif
