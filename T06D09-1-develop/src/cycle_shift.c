#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length, int *shift);
void output(int *buffer, int length);
void rotate(int *buffer, int length, int shift);

int main() {
    int buffer[NMAX];
    int length;
    int shift;

    if (input(buffer, &length, &shift) != 0) {
        printf("n/a");
        return 1;
    }

    rotate(buffer, length, shift);
    output(buffer, length);

    return 0;
}

int input(int *buffer, int *length, int *shift) {
    int flag = 0;
    if (scanf("%d", length) != 1 || *length < 1 || *length > NMAX) {
        return 1;
    }

    for (int i = 0; i < *length; i++) {
        if (scanf("%d", &buffer[i]) != 1) {
            return 1;
        }
    }

    if (scanf("%d", shift) != 1 || shift < 1) {
        return 1;
    }

    return flag;
}

void output(int *buffer, int length) {
    for (int i = 0; i < length - 1; i++) {
        printf("%d ", buffer[i]);
    }
    printf("%d", buffer[length - 1]);
}

void rotate(int *buffer, int length, int shift) {
    int temp[NMAX];
    shift = shift % length;
    for (int i = 0; i < length; i++) {
        temp[i] = buffer[(i + shift) % length];
    }

    for (int i = 0; i < length; i++) {
        buffer[i] = temp[i];
    }
}