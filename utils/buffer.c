#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <utils/utils.h>
#include <utils/buffer.h>

buffer_t new_buffer() {
    buffer_t buffer;
    buffer.r_pos = 0;
    buffer.w_pos = 0;
    return buffer;
}

char read_one(buffer_t *buffer) {
    char value = buffer->data[buffer->r_pos];
    ++buffer->r_pos;
    return value;
}

void write_one(buffer_t *buffer, char one) {
    buffer->data[buffer->w_pos] = one;
    ++buffer->w_pos;
}

void reset_buffer(buffer_t *buffer) {
    memset(&buffer->data, 0, sizeof(buffer->data));
    buffer->r_pos = 0;
    buffer->w_pos = 0;
}

int read_int_le(buffer_t *buffer) {
    int result = read_one(buffer);
    result |= (read_one(buffer) << 8);
    result |= (read_one(buffer) << 16);
    result |= (read_one(buffer) << 24);
    return result;
}

void write_int_le(buffer_t *buffer, int value) {
    write_one(buffer, (value & 0xff));
    write_one(buffer, ((value >> 8) & 0xff));
    write_one(buffer, ((value >> 16) & 0xff));
    write_one(buffer, ((value >> 24) & 0xff));
}
