#include <stdio.h>
#include <stdlib.h>

size_t s21_strlen(const char *str) {
    size_t length = 0;
    while (str[length]) {
        length++;
    }
    return length;
}

int s21_strcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

char *s21_strcpy(char *dest, const char *src) {
    char *original_dest = dest;
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
    return original_dest;
}

char *s21_strcat(char *dest, const char *src) {
    char *original_dest = dest;
    while (*dest) {
        dest++;
    }
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
    return original_dest;
}

char *s21_strchr(const char *str, int c) {
    while (*str) {
        if (*str == (char)c) {
            return (char *)str;
        }
        str++;
    }
    return NULL;
}

char *s21_strstr(const char *haystack, const char *needle) {
    if (!*needle) {
        return (char *)haystack;
    }

    while (*haystack) {
        const char *h = haystack;
        const char *n = needle;

        while (*h && *n && (*h == *n)) {
            h++;
            n++;
        }

        if (!*n) {
            return (char *)haystack;
        }
        haystack++;
    }
    return NULL;
}

char *s21_strtok(char *str, const char *delim) {
    static char *static_str = NULL;  // Указатель сохраняющий строку между вызовами функции
    if (str != NULL) {
        static_str = str;
    }
    if (static_str == NULL) {
        return NULL;
    }

    // Пропустить начальные разделители
    while (*static_str && s21_strchr(delim, *static_str)) {
        static_str++;
    }

    if (*static_str == '\0') {
        return NULL;
    }

    char *token_start = static_str;

    // Найти конец токена
    while (*static_str && !s21_strchr(delim, *static_str)) {
        static_str++;
    }

    if (*static_str) {
        *static_str = '\0';
        static_str++;
    } else {
        static_str = NULL;
    }

    return token_start;
}
