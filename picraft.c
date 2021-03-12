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
    write_one(&buffer, '\xfd');
    print_hex(read_one(&buffer));
}

int main() {
    logger("success", "Done!");
    debug_buffer();
    while (1) {
        command_handler(get_input("> "));
    }
}
