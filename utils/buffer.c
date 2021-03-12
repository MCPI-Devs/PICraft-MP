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
    char value = buffer.data[buffer->r_pos]
    ++buffer->r_pos;
    return value;
}

void write_one(buffer_t *buffer, char one) {
    buffer->data[buffer->w_pos] = one;
    ++buffer->w_pos;
}

void reset_buffer(buffer_t *buffer) {
    memset(&buffer->data, 0, sizeof(buffer->data));
    buffer.r_pos = 0;
    buffer.w_pos = 0;
}
