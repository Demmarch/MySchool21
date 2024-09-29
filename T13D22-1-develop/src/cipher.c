#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef LOG
#include "log_levels.h"
#include "logger.h"
#endif

void caesar_cipher(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }
        text[i] = ch;
    }
}
#ifdef NON_LOG
void read_and_display_file(const char *path) {
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("n/a\n");
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    printf("\n");
    fclose(file);
}
#endif
#ifdef LOG
void read_and_display_file(const char *path, FILE *log_file) {
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("n/a\n");
        logcat(log_file, "Error opening file (mode 1)", error);
        return;
    }
    char log_message[256];
    snprintf(log_message, sizeof(log_message), "File %.*s opened (mode 1)", (int)(sizeof(log_message) - 50),
             path);
    logcat(log_file, log_message, info);

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    printf("\n");
    fclose(file);
    snprintf(log_message, sizeof(log_message), "File %.*s closed (mode 1)", (int)(sizeof(log_message) - 50),
             path);
    logcat(log_file, log_message, info);
}
#endif
#ifdef NON_LOG
void append_to_file(const char *path, const char *text) {
    FILE *file = fopen(path, "a");
    if (file == NULL) {
        printf("n/a\n");
        return;
    }

    fprintf(file, "\n%s", text);
    fclose(file);
    read_and_display_file(path);
}
#endif

#ifdef LOG
void append_to_file(const char *path, const char *text, FILE *log_file) {
    FILE *file = fopen(path, "a");
    if (file == NULL) {
        printf("n/a\n");
        char log_message[256];
        snprintf(log_message, sizeof(log_message), "Error opening file %.*s (mode 2)",
                 (int)(sizeof(log_message) - 50), path);
        logcat(log_file, log_message, error);
        return;
    }
    char log_message[256];
    snprintf(log_message, sizeof(log_message), "File opened %.*s (mode 2)", (int)(sizeof(log_message) - 50),
             path);
    logcat(log_file, log_message, info);

    fprintf(file, "\n%s", text);
    fclose(file);
    snprintf(log_message, sizeof(log_message), "File closed %.*s (mode 2)", (int)(sizeof(log_message) - 50),
             path);
    logcat(log_file, log_message, info);
    read_and_display_file(path, log_file);
}
#endif

void des_encrypt(const unsigned char *input, unsigned char *output) {
    for (int i = 0; i < 8; i++) {
        output[i] = input[i] ^ 0xAA;  // XOR
    }
}
#ifdef LOG
void encrypt_file_with_des(const char *path, FILE *log_file) {
    FILE *file = fopen(path, "rb+");
    if (file == NULL) {
        printf("n/a");
        char log_message[256];
        snprintf(log_message, sizeof(log_message), "Error opening file %*.s (mode 3)",
                 (int)(sizeof(log_message) - 50), path);
        logcat(log_file, log_message, error);
        return;
    }
    char log_message[256];
    snprintf(log_message, sizeof(log_message), "File %*.s opened (mode 3)", (int)(sizeof(log_message) - 50),
             path);
    logcat(log_file, log_message, info);

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    unsigned char *buffer = malloc(size);
    if (buffer == NULL) {
        fclose(file);
        printf("n/a");
        logcat(log_file, "Memory allocation error during encryption", error);
        return;
    }
    fread(buffer, 1, size, file);

    unsigned char *encrypted_buffer = malloc(size);
    if (encrypted_buffer == NULL) {
        free(buffer);
        fclose(file);
        printf("n/a");
        logcat(log_file, "Memory allocation error during encryption", error);
        return;
    }

    for (int i = 0; i < size; i += 8) {
        des_encrypt(buffer + i, encrypted_buffer + i);
    }
    fseek(file, 0, SEEK_SET);
    fwrite(encrypted_buffer, 1, size, file);

    free(buffer);
    free(encrypted_buffer);
    fclose(file);
    snprintf(log_message, sizeof(log_message), "File %*.s encrypted and closed",
             (int)(sizeof(log_message) - 50), path);
    logcat(log_file, log_message, info);
}
#endif
#ifdef LOG
void process_directory(const char *dir_path, int caesar_shift, int use_caesar, FILE *log_file) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);
    if (dp == NULL) {
        printf("n/a\n");
        logcat(log_file, "Error open dir", error);
        return;
    }
    char log_message[256];
    snprintf(log_message, sizeof(log_message), "Directory %*.s opened for processing",
             (int)(sizeof(log_message) - 50), dir_path);
    logcat(log_file, log_message, info);

    while ((entry = readdir(dp))) {
        char file_path[1024];
        snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);

        if (strstr(entry->d_name, ".c") != NULL) {
            if (use_caesar) {
                char log_message[256];
                snprintf(log_message, sizeof(log_message), "Encrypting file with Caesar cipher: %.*s",
                         (int)(sizeof(log_message) - 50), file_path);
                logcat(log_file, log_message, info);

                FILE *file = fopen(file_path, "r+");
                if (file == NULL) {
                    printf("n/a");
                    logcat(log_file, "Error opening file for Caesar encryption", error);
                    return;
                } else {
                    fseek(file, 0, SEEK_END);
                    size_t size = ftell(file);
                    fseek(file, 0, SEEK_SET);
                    char *buffer = malloc(size + 1);
                    fread(buffer, 1, size, file);
                    buffer[size] = '\0';
                    caesar_cipher(buffer, caesar_shift);
                    fseek(file, 0, SEEK_SET);
                    fwrite(buffer, 1, size, file);
                    free(buffer);
                    fclose(file);
                }
            } else {
                char log_message[256];
                snprintf(log_message, sizeof(log_message), "Encrypting file with DES: %.*s",
                         (int)(sizeof(log_message) - 50), file_path);
                logcat(log_file, log_message, info);

                encrypt_file_with_des(file_path, log_file);
            }
        } else if (strstr(entry->d_name, ".h") != NULL) {
            char log_message[256];
            snprintf(log_message, sizeof(log_message), "Clearing file: %.*s", (int)(sizeof(log_message) - 50),
                     file_path);
            logcat(log_file, log_message, info);

            FILE *file = fopen(file_path, "w");
            if (file != NULL) {
                fclose(file);
            }
        }
    }
    closedir(dp);
    logcat(log_file, "Directory processing completed", info);
}
#endif

#ifdef NON_LOG
void encrypt_file_with_des(const char *path) {
    FILE *file = fopen(path, "rb+");
    if (file == NULL) {
        printf("n/a");
        return;
    }

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    unsigned char *buffer = malloc(size);
    if (buffer == NULL) {
        fclose(file);
        printf("n/a");
        return;
    }
    fread(buffer, 1, size, file);

    unsigned char *encrypted_buffer = malloc(size);
    if (encrypted_buffer == NULL) {
        free(buffer);
        fclose(file);
        printf("n/a");
        return;
    }

    for (int i = 0; i < size; i += 8) {
        des_encrypt(buffer + i, encrypted_buffer + i);
    }
    fseek(file, 0, SEEK_SET);
    fwrite(encrypted_buffer, 1, size, file);

    free(buffer);
    free(encrypted_buffer);
    fclose(file);
}
#endif

#ifdef NON_LOG
void process_directory(const char *dir_path, int caesar_shift, int use_caesar) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);
    if (dp == NULL) {
        printf("n/a\n");
        return;
    }

    while ((entry = readdir(dp))) {
        char file_path[1024];
        snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, entry->d_name);

        if (strstr(entry->d_name, ".c") != NULL) {
            if (use_caesar) {
                FILE *file = fopen(file_path, "r+");
                if (file == NULL) {
                    printf("n/a");
                    return;
                } else {
                    fseek(file, 0, SEEK_END);
                    size_t size = ftell(file);
                    fseek(file, 0, SEEK_SET);
                    char *buffer = malloc(size + 1);
                    fread(buffer, 1, size, file);
                    buffer[size] = '\0';
                    caesar_cipher(buffer, caesar_shift);
                    fseek(file, 0, SEEK_SET);
                    fwrite(buffer, 1, size, file);
                    free(buffer);
                    fclose(file);
                }
            } else {
                encrypt_file_with_des(file_path);
            }
        } else if (strstr(entry->d_name, ".h") != NULL) {
            FILE *file = fopen(file_path, "w");
            if (file != NULL) {
                fclose(file);
            }
        }
    }
    closedir(dp);
}
#endif

void display_menu() {
    printf("Menu:\n");
    printf("1. Display file\n");
    printf("2. Append file and display\n");
    printf("3. Encrypt .c and clear .h with Caesar cipher\n");
    printf("4. Encrypt .c and clear .h with DES(XOR)\n");
    printf("-1. Exit\n");
}

int main() {
    int choice = 0;
    char file_path[256];
    char text[1024];
    char dir_path[256];
    int caesar_shift;

#ifdef LOG
    FILE *log_file = log_init("log.txt");
    if (log_file == NULL) {
        return 1;
    }
#endif
    while (choice != -1) {
        display_menu();
        scanf("%d", &choice);

        if (choice == 1) {
            scanf("%s", file_path);
#ifdef LOG
            read_and_display_file(file_path, log_file);
#endif
#ifdef NON_LOG
            read_and_display_file(file_path);
#endif
        } else if (choice == 2 && file_path != NULL) {
            scanf(" %s", text);
#ifdef LOG
            append_to_file(file_path, text, log_file);
#endif
#ifdef NON_LOG
            append_to_file(file_path, text);
#endif
        } else if (choice == 3) {
            scanf("%s", dir_path);
            scanf("%d", &caesar_shift);
#ifdef LOG
            process_directory(dir_path, caesar_shift, 1, log_file);
#endif
#ifdef NON_LOG
            process_directory(dir_path, caesar_shift, 1);
#endif
        } else if (choice == 4) {
            scanf("%s", dir_path);
#ifdef LOG
            process_directory(dir_path, 0, 0, log_file);
#endif
#ifdef NON_LOG
            process_directory(dir_path, 0, 0);
#endif
        }
    }
#ifdef LOG
    log_close(log_file);
#endif
    return 0;
}