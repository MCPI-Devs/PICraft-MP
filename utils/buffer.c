#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utils/buffer.h>

void reset_buffer(buffer_t *_buffer) {
    _buffer->data = "";
    _buffer->pos = 0;
}

void write_buffer(buffer_t *_buffer, char *data) {
    unsigned int length = strlen(_buffer->data) + strlen(data) + 1;
    char* result = malloc(length);
    for (unsigned int i = 0; i < strlen(_buffer->data); i++) {
        result[i] = _buffer->data[i];
    }
    for (unsigned int i = 0; i < strlen(data); i++) {
        result[i + strlen(_buffer->data)] = data[i];
    }
    result[length - 1] = 0x00;
    _buffer->data = result;
}

char* read_buffer(buffer_t *_buffer, unsigned int length) {
    char* result = malloc(length + 1);
    for (unsigned int i = 0; i < length; i++) {
        result[i] = _buffer->data[i + _buffer->pos];
    }
    _buffer->pos += length;
    result[length] = 0x00;
    return result;
}

unsigned int end_of_buffer(buffer_t *_buffer) {
    if (strlen(_buffer->data) <= _buffer->pos) {
        return 1;
    } else {
        return 0;
    }
}