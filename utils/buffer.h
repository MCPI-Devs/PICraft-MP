#ifndef BUFFER_H
#define BUFFER_H

typedef struct {
    char *data;
    int pos;
} buffer_t;

void append_buffer(buffer_t *buffer, char* data);

char *pop_buffer(buffer_t *buffer, unsigned int length);

buffer_t new_buffer();

void reset_buffer(buffer_t *buffer);

#endif
