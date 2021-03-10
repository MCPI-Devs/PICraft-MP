#ifndef UTILS_H
#define UTILS_H

unsigned int digit_count(int value);

char *time_now();

void logger(char *type, char *content);

char *get_input(char *prompt);

#endif // UTILS_H