#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <utils/utils.h>
#include <utils/buffer.h>

buffer_t new_buffer() {
    buffer_t buffer;
    buffer.data = "";
    buffer.pos = 0;
    return buffer;
}

char *pop_buffer(buffer_t *buffer, unsigned int length) {
    char* value = substr(buffer->data, buffer->pos, length);
    buffer->pos += length;
    return value;
}

void append_buffer(buffer_t *buffer, char* data) {
    buffer->data = joinstr(buffer->data, data);
}

void reset_buffer(buffer_t *buffer) {
    buffer->data = "";
    buffer->pos = 0;
}
