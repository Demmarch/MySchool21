#include <stdio.h>

#define LEN 100

int input(int *buffer);
void output(int *buffer, int length);
void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(const int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);

int main() {
    int number1[LEN];
    int number2[LEN];
    int len1 = 0;
    int len2 = 0;
    int sum_result[LEN] = {0};
    int sum_length = 0;
    int sub_result[LEN] = {0};
    int sub_length = 0;

    len1 = input(number1);
    if (len1 == 404) {
        printf("n/a");
        return 1;
    }
    len2 = input(number2);

    if (len2 == 404) {
        printf("n/a");
        return 1;
    }
    sum(number1, len1, number2, len2, sum_result, &sum_length);
    if (sum_length == 0) {
        printf("n/a\n");
    } else {
        output(sum_result, sum_length);
        printf("\n");
    }
    sub(number1, len1, number2, len2, sub_result, &sub_length);
    if (sub_length > 0) {
        output(sub_result, sub_length);
        printf("\n");
    } else {
        printf("n/a\n");
    }
    return 0;
}

int input(int *buffer) {
    int len = 0;
    char c;

    do {
        if (scanf("%d%c", &buffer[len], &c) != 2 && buffer[len] < 10 && buffer[len] >= 0) {
            len = 404;
            continue;
        }
        len++;
    } while (c != '\n' && len < LEN);

    return len;
}

void output(int *buffer, int length) {
    for (int i = 0; i < length - 1; i++) {
        printf("%d ", buffer[i]);
    }
    printf("%d", buffer[length - 1]);
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int max_len = len1 > len2 ? len1 : len2;
    *result_length = max_len;

    int carry = 0;
    for (int i = 0; i < max_len; i++) {
        int digit1 = (i < len1) ? buff1[len1 - 1 - i] : 0;
        int digit2 = (i < len2) ? buff2[len2 - 1 - i] : 0;
        int total = digit1 + digit2 + carry;

        result[max_len - 1 - i] = total % 10;
        carry = total / 10;
    }

    // Если остались десятки
    if (carry > 0) {
        for (int i = max_len; i > 1; i--) {
            result[i] = result[i - 1];
        }
        result[0] = carry;
        (*result_length)++;
    }
    while (result[0] == 0) {
        for (int i = 0; i < *result_length - 1; i++) {
            result[i] = result[i + 1];
        }
        (*result_length)--;
    }
}

void sub(const int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    if (len2 > len1 || (len2 == len1 && buff2[0] > buff1[0])) {
        *result_length = 0;
        return;
    }

    int borrow = 0;  // для взятия
    *result_length = len1;

    for (int i = 0; i < len1; i++) {
        int digit1 = buff1[len1 - 1 - i];
        int digit2 = (i < len2) ? buff2[len2 - 1 - i] : 0;

        if (digit1 < digit2 + borrow) {
            result[*result_length - 1 - i] = digit1 + 10 - digit2 - borrow;
            borrow = 1;
        } else {
            result[*result_length - 1 - i] = digit1 - digit2 - borrow;
            borrow = 0;
        }
    }
    while (*result_length > 1 && result[0] == 0) {
        for (int i = 0; i < *result_length - 1; i++) {
            result[i] = result[i + 1];
        }
        (*result_length)--;
    }
}