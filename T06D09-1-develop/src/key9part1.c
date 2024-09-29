#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(const int *buffer, int length);
int find_numbers(const int *buffer, int length, int number, int *numbers);

int main() {
    int buffer[NMAX];
    int length;

    if (input(buffer, &length) != 0) {
        printf("n/a");
        return 1;
    }

    int sum = sum_numbers(buffer, length);
    if (sum == 0) {
        printf("n/a");
        return 1;
    }

    int result[NMAX];
    int result_length = find_numbers(buffer, length, sum, result);

    if (result_length == 0) {
        printf("n/a");
        return 1;
    }

    printf("%d\n", sum);
    output(result, result_length);

    return 0;
}

int input(int *buffer, int *length) {
    int flag = 0;
    if (scanf("%d", length) != 1 || *length < 1 || *length > NMAX) {
        flag = 1;
    }

    for (int i = 0; i < *length; i++) {
        if (scanf("%d", &buffer[i]) != 1) {
            flag = 1;
        }
    }

    if (getchar() != '\n') {
        flag = 1;  // check input (for example, if n = 2 but input 1 2 3 -> n/a)
    }

    return flag;
}

void output(int *buffer, int length) {
    for (int i = 0; i < length - 1; i++) {
        printf("%d ", buffer[i]);
    }
    printf("%d", buffer[length - 1]);
}

int sum_numbers(const int *buffer, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum += buffer[i];
        }
    }
    return sum;
}

int find_numbers(const int *buffer, int length, int number, int *numbers) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[count] = buffer[i];
            count++;
        }
    }
    return count;
}