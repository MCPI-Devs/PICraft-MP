#ifndef BUFFER_H
#define BUFFER_H

typedef struct {
    char data[65535];
    unsigned int r_pos;
    unsigned int w_pos;
} buffer_t;

buffer_t new_buffer();

char *pop_buffer(buffer_t *buffer, unsigned int length);

void append_buffer(buffer_t *buffer, char* data);

void reset_buffer(buffer_t *buffer);

#endif
