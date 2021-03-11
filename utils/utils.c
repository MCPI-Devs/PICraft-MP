#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <utils/utils.h>
#include <constant/t_format.h>

unsigned int digit_count(int value) {
    unsigned int count = 0;
    unsigned int i;
    for (i = value; i != 0; i /= 10) {
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
    char *h_c = malloc(3);
    char *m_c = malloc(3);
    char *s_c = malloc(3);
    if (digit_count(h) == 0) {
        sprintf(h_c, "%d%d", 0, 0);
    } else if (digit_count(h) == 1) {
        sprintf(h_c, "%d%d", 0, h);
    } else {
        sprintf(h_c, "%d", h);
    }
    h_c[2] = 0x00;
    if (digit_count(m) == 0) {
        sprintf(m_c, "%d%d", 0, 0);
    } else if (digit_count(m) == 1) {
        sprintf(m_c, "%d%d", 0, m);
    } else {
        sprintf(m_c, "%d", m);
    }
    m_c[2] = 0x00;
    if (digit_count(s) == 0) {
        sprintf(s_c, "%d%d", 0, 0);
    } else if (digit_count(s) == 1) {
        sprintf(s_c, "%d%d", 0, s);
    } else {
        sprintf(s_c, "%d", s);
    }
    s_c[2] = 0x00;
    char *result = malloc(9);
    sprintf(result, "%s:%s:%s", h_c, m_c, s_c);
    result[8] = 0x00;
    return result;
}

void logger(char *type, char* content) {
    char *color;
    if (strcmp(type, "info") == 0) {
        color = LIGHT_BLUE;
    } else if (strcmp(type, "warn") == 0) {
        color = LIGHT_YELLOW;
    } else if (strcmp(type, "success") == 0) {
        color = LIGHT_GREEN;
    } else if (strcmp(type, "error") == 0) {
        color = LIGHT_RED;
    } else {
        return;
    }
    printf("%s<%s%s %s| %s%s%s> %s%s%s\n", YELLOW, LIGHT_CYAN, time_now(), YELLOW, color, type, YELLOW, RESET, content, RESET);
}

char *get_input(char *prompt) {
    printf("%s", prompt);
    int size;
    char* input = malloc(size);
    fgets(input, size, stdin);
    input[strcspn(input, "\n")] = 0x00;
    return input;
}

unsigned int number_byte_count(long long number) {
    unsigned int byte_count = 0;
    while (number != 0) {
        number >>= 8;
        ++byte_count;
    }
    return byte_count;
}
