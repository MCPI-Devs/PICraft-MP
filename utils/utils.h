#ifndef UTILS_H
#define UTILS_H

unsigned int digit_count(int value);

char *time_now();

void logger(char *type, char *content);

char *get_input(char *prompt);

unsigned int number_byte_count(long long number);

void print_hex(char* data);

char *substr(char *value, unsigned int pos, unsigned int length);

#endif
