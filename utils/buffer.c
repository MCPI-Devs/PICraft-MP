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

char read_int_8(buffer_t *buffer) {
    char result = pop_buffer(buffer, 1)[0];
    return result;
}

void write_int_8(buffer_t *buffer, char value) {
    append_buffer(buffer, &value);
}

unsigned char read_u_int_8(buffer_t *buffer) {
    unsigned char result = pop_buffer(buffer, 1)[0];
    return result;
}

void write_u_int_8(buffer_t *buffer, unsigned char value) {
    append_buffer(buffer, &value);
}

short read_int_16(buffer_t *buffer) {
    char *data = pop_buffer(buffer, 2);
    short result = data[0];
    result |= (data[1] << 8);
    return result;
}

void write_int_16(buffer_t *buffer, short value) {
    char *result = malloc(3);
    result[0] = (value & 0xff);
    result[1] = ((value >> 8) & 0xff);
    result[2] = 0x00;
    append_buffer(buffer, result);
}

unsigned short read_u_int_16(buffer_t *buffer) {
    char *data = pop_buffer(buffer, 2);
    unsigned short result = data[0];
    result |= (data[1] << 8);
    return result;
}

void write_u_int_16(buffer_t *buffer, unsigned short value) {
    char *result = malloc(3);
    result[0] = (value & 0xff);
    result[1] = ((value >> 8) & 0xff);
    result[2] = 0x00;
    append_buffer(buffer, result);
}
