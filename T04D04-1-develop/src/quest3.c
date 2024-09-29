#include <stdio.h>

int fibo(int n) {
    if (n < 0) {
        return -1;  // not correct
    } else if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibo(n - 1) + fibo(n - 2);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        printf("n/a\n");
        return 1;
    }
    int res = fibo(n);
    if (res == -1) {
        printf("n/a\n");
    } else {
        printf("%d\n", res);
    }
    return 0;
}