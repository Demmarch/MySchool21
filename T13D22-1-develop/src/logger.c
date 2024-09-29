#include "logger.h"

#include <string.h>
#include <time.h>

const char *log_level_to_string(enum log_level level) {
    switch (level) {
        case debug:
            return "DEBUG";
        case info:
            return "INFO";
        case warning:
            return "WARNING";
        case error:
            return "ERROR";
        default:
            return "UNKNOWN";
    }
}

FILE *log_init(const char *filename) {
    FILE *log_file = fopen(filename, "a");
    if (log_file == NULL) {
        printf("Error opening log file: %s\n", filename);
    }
    return log_file;
}

int logcat(FILE *log_file, const char *message, enum log_level level) {
    if (log_file == NULL) {
        return -1;
    }

    time_t now;
    time(&now);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0';  // Удалить символ новой строки

    fprintf(log_file, "[%s] [%s]: %s\n", log_level_to_string(level), time_str, message);
    return 0;
}

int log_close(FILE *log_file) {
    if (log_file == NULL) {
        return -1;
    }
    fclose(log_file);
    return 0;
}