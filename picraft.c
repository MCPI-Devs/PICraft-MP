#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utils/buffer.h>
#include <utils/utils.h>

void command_handler(char* command) {
    if (strcmp(command, "stop") == 0) {
        logger("info", "Stopping server...");
        logger("info", "Server stopped.");
        exit(0);
    } else if (strlen(command) <= 0) {
    } else {
        logger("error", "Invalid command!");
    }
}

void debug_buffer() {
    buffer_t buffer = new_buffer();
    append_buffer(&buffer, "\x01\x02\x03\xfd");
    print_hex(pop_buffer(&buffer, 4));
}

int main() {
    logger("success", "Done!");
    debug_buffer();
    while (1) {
        command_handler(get_input("> "));
    }
}
