#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <utils/utils.h>
#include <utils/buffer.h>

void append_buffer(buffer_t *buffer, char* data) {
    if (strlen(buffer->data) == 0) {
        buffer->data = data;
    } else {
        int length = strlen(buffer->data) + strlen(data);
        char *result = malloc(length + 1);
        sprintf(result, "%s%s", buffer->data, data);
        result[length] = 0x00;
        buffer->data = result;
    }
}

char *pop_buffer(buffer_t *buffer, unsigned int length) {
    char* value = substr(buffer->data, buffer->pos, length);
    buffer->pos += length;
    return value;
}

buffer_t new_buffer() {
    buffer_t buffer;
    buffer.data = "";
    buffer.pos = 0;
    return buffer;
}

void reset_buffer(buffer_t *buffer) {
    buffer->data = "";
    buffer->pos = 0;
}
