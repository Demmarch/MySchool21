#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();
void s21_strchr_test();
void s21_strstr_test();
void s21_strtok_test();

int main() {
#ifdef TEST_LEN
    s21_strlen_test();
#endif

#ifdef TEST_COMPARE
    s21_strcmp_test();
#endif

#ifdef TEST_COPY
    s21_strcpy_test();
#endif

#ifdef TEST_CAT
    s21_strcat_test();
#endif

#ifdef TEST_CHR
    s21_strchr_test();
#endif

#ifdef TEST_STR
    s21_strstr_test();
#endif

#ifdef TEST_TOK
    s21_strtok_test();
#endif
    return 0;
}

void s21_strlen_test() {
    size_t test1 = s21_strlen("Hello");
    size_t test2 = s21_strlen("");
    if (test1 == 5 && test2 == 0) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}
void s21_strcmp_test() {
    int test1 = s21_strcmp("TEST", "TEST");
    int test2 = s21_strcmp("abc", "bcd");
    if (test1 == 0 && test2 == -1) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}
void s21_strcpy_test() {
    char test_char[100] = "";

    if (s21_strcmp(s21_strcpy(test_char, "TEST"), "TEST") == 0 &&
        s21_strcmp(s21_strcpy(test_char, "long_test_string_____"), "long_test_string_____") == 0 &&
        s21_strcmp(s21_strcpy(test_char, " "), " ") == 0) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strcat_test() {
    char test_char[100] = "Hello ";

    if (s21_strcmp(s21_strcat(test_char, "TEST"), "Hello TEST") == 0 &&
        s21_strcmp(s21_strcat(test_char, "long_string______________________"),
                   "Hello TESTlong_string______________________") == 0 &&
        s21_strcmp(s21_strcat(test_char, " "), "Hello TESTlong_string______________________ ") == 0) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strchr_test() {
    if (s21_strcmp(s21_strchr("hello", 'l'), "llo") == 0 && s21_strcmp(s21_strchr("DOOM", 'O'), "OOM") == 0) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}
void s21_strstr_test() {
    if (s21_strcmp(s21_strstr("hello DOOM", "jjjo"), "hello") != 0 &&
        s21_strcmp(s21_strstr("hello DOOM", "DOOM"), "DOOM") == 0) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void s21_strtok_test() {
    char test_char[] = "dir1/dir2/file.file";
    char *token;
    int flag1 = 0, flag2 = 0, flag3 = 0;
    token = s21_strtok(test_char, "/");
    while (token != NULL) {
        if (s21_strcmp(token, "dir1") == 0) {
            flag1 = 1;
        }
        if (s21_strcmp(token, "dir2") == 0) {
            flag2 = 1;
        }
        if (s21_strcmp(token, "file.file") == 0) {
            flag3 = 1;
        }
        printf("%s\n", token);
        token = s21_strtok(NULL, "/");
    }
    if (flag1 == 1 && flag2 == 1 && flag3 == 1) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}