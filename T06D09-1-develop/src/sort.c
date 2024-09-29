#include <stdio.h>
#define NMAX 10

int input(int *a);
int sort(int *a);
void output(int *a);

int main() {
    int data[NMAX];

    if (input(data) != 0) {
        printf("n/a");
        return 1;
    }
    sort(data);
    output(data);
    return 0;
}

int input(int *a) {
    for (int i = 0; i < NMAX; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return 1;
        }
    }

    if (getchar() != '\n') {
        return 1;  // check input (for example, if n = 2 but input 1 2 3 -> n/a)
    }
    return 0;
}

int sort(int *a) {
    for (int i = 0; i < NMAX; i++) {
        for (int j = 0; j < NMAX - 1; j++) {
            if (a[j] > a[j + 1]) {
                int b = a[j];
                a[j] = a[j + 1];
                a[j + 1] = b;
            }
        }
    }
    return 0;
}

void output(int *a) {
    for (int i = 0; i < NMAX - 1; i++) {
        printf("%d ", a[i]);
    }
    printf("%d", a[9]);
}