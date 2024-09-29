#include "print_module.h"

#include <stdio.h>
#include <time.h>

char print_char(char ch) { return putchar(ch); }

void print_log(char (*print_func)(char), const char* message) {
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    char time_str[9];

    const char* log_prefix = Log_prefix;
    while (*log_prefix) {
        print_func(*log_prefix++);
    }
    snprintf(time_str, sizeof(time_str), "%02d:%02d:%02d", t->tm_hour, t->tm_min, t->tm_sec);
    print_func(' ');

    for (int i = 0; i < 10; i++) {
        print_func(time_str[i]);
    }

    print_func(' ');

    for (int i = 0; message[i] != '\0'; i++) {
        print_func(message[i]);
    }
}