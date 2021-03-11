#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utils/buffer.h>
#include <utils/utils.h>
#include <utils/byte_array.h>

void reset_buffer(buffer_t *_buffer) {
    _buffer->data = "";
    _buffer->pos = 0;
}

void write_buffer(buffer_t *_buffer, byte_array_t _byte_array) {unsigned int i;
    for (i = 0; i < byte_array_size(data); i++) {
        _buffer->data.v[_buffer->w_pos] = data.v[i];
        ++_buffer->w_pos;
    }
}

byte_array_t read_buffer(buffer_t *_buffer, unsigned int length) {
    byte_array_t result;
    unsigned int i;
    for (i = 0; i < length; i++) {
        result.v[i] = _buffer->data.v[i + _buffer->pos];
        _buffer->pos += i
    }
    return result;
}

unsigned int end_of_buffer(buffer_t *_buffer) {
    /*if (strlen(_buffer->data.v) <= _buffer->pos) {
        return 1;
    } else {
        return 0;
    }*/
}

unsigned long long read_unum(buffer_t *_buffer, unsigned int length, char *byte_order) {
    byte_array_t data = read_buffer(_buffer, length);
    unsigned int i;
    unsigned long long result = 0;
    for (i = 0; i < length; i++) {
        if (strcmp(byte_order, "big") == 0) {
            result |= (data.v[abs(i - (length - 1))] << (i * 8));
        } else {
            result |= (data.v[i] << (i * 8));
        }
    }
    return result;
}

void write_unum(buffer_t *_buffer, unsigned long long value, unsigned int length, char *byte_order) {
    if (number_byte_count(value) > length) {
        return;
    }
    byte_array_t data;
    char x;
    unsigned int i;
    for (i = 0; i < length; i++) {
        if (strcmp(byte_order, "big") == 0) {
            x = ((value >> (8 * abs(i - (length - 1)))) & 0xff);
        } else {
            x = ((value >> (8 * i)) & 0xff);
        }
        data.v[i] = x;
    }
    write_buffer(_buffer, data);
}
