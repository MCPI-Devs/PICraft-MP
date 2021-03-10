#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <utils/utils.h>
#include <constant/text_format.h>

unsigned int digit_count(int value) {
    unsigned int count = 0;
    for (int i = value; i != 0; i /= 10) {
        ++count;
    }
    return count;
}

char *time_now() {
    time_t now = time(NULL);
    struct tm *st = localtime(&now);
    unsigned int h = st->tm_hour;
    unsigned int m = st->tm_min;
    unsigned int s = st->tm_sec;
    unsigned int length = 2;
    length += digit_count(h);
    length += digit_count(m);
    length += digit_count(s);
    char *result = malloc(length + 1);
    sprintf(result, "%d:%d:%d", h, m, s);
    result[length] = 0x00;
    return result;
}

void logger(char *type, char* content) {
    char *color;
    if (strcmp(type, "info") == 0) {
        color = BLUE;
    } else if (strcmp(type, "warn") == 0) {
        color = YELLOW;
    } else if (strcmp(type, "success") == 0) {
        color = GREEN;
    } else if (strcmp(type, "error") == 0) {
        color = RED;
    } else {
        return;
    }
    printf("%s<%s%s %s| %s%s%s> %s%s%s\n", GOLD, AQUA, time_now(), GOLD, color, type, GOLD, RESET, content, RESET);
}

char *get_input(char *prompt) {
    printf("%s", prompt);
    int size;
    char* input = malloc(size);
    fgets(input, size, stdin);
    input[strcspn(input, "\n")] = 0x00;
    return input;
}