#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utils/buffer.h>
#include <utils/utils.h>
#include <constant/text_format.h>

void command_handler(char* command) {
    if (strcmp(command, "stop") == 0) {
        logger("info", "Stopping server...");
        logger("info", "Server stopped.");
        exit(0);
    } else if (strcmp(command, "") == 0) {
    } else {
        logger("error", "Invalid command!");
    }
}

int main() {
    logger("success", "Done!");
    while (1) {
        command_handler(get_input("> "));
    }
}