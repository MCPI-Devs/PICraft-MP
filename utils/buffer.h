#ifndef BUFFER_H
#define BUFFER_H

typedef struct {
    char *data;
    int pos;
} buffer_t;

buffer_t new_buffer();

char *pop_buffer(buffer_t *buffer, unsigned int length);

void append_buffer(buffer_t *buffer, char* data);

void reset_buffer(buffer_t *buffer);

#endif
