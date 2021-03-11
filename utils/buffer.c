#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utils/buffer.h>
#include <utils/utils.h>

void reset_buffer(buffer_t *_buffer) {
    _buffer->data = "";
    _buffer->pos = 0;
}

void write_buffer(buffer_t *_buffer, char *data) {
    if (strlen(_buffer->data) == 0) {
        _buffer->data = data;
    } else {
        unsigned int length = strlen(_buffer->data) + strlen(data);
        char *result = malloc(length + 1);
        sprintf(result, "%s%s", _buffer->data, data);
        result[length] = 0x00;
        _buffer->data = result;
    }
}

char* read_buffer(buffer_t *_buffer, unsigned int length) {
    char* result = malloc(length + 1);
    unsigned int i;
    for (i = 0; i < length; i++) {
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

unsigned long long read_unum(buffer_t *_buffer, unsigned int length, char *byte_order) {
    char *data = read_buffer(_buffer, length);
    unsigned int i;
    unsigned long long result = 0;
    for (i = 0; i < length; i++) {
        if (strcmp(byte_order, "big") == 0) {
            result |= (data[abs(i - (length - 1))] << (i * 8));
        } else {
            result |= (data[i] << (i * 8));
        }
    }
    return result;
}

void write_unum(buffer_t *_buffer, unsigned long long value, unsigned int length, char *byte_order) {
    if (number_byte_count(value) > length) {
        return;
    }
    char x;
    unsigned int i;
    for (i = 0; i < length; i++) {
        if (strcmp(byte_order, "big") == 0) {
            x = ((value >> (8 * abs(i - (length - 1)))) & 0xff);
        } else {
            x = ((value >> (8 * i)) & 0xff);
        }
        write_buffer(_buffer, &x);
    }
}
