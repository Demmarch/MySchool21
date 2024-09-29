#include <stdio.h>

int prime(int inp_num);
int largest_prime(int x);

int main() {
    int x;
    if (scanf("%d", &x) != 1) {
        printf("n/a\n");
        return 0;
    }
    if (prime(x) == 1) {
        printf("%d is prime\nn/a\n", x);
    }
    if (x < 0) x = -x;
    int res = largest_prime(x);
    if (res == -1) {
        printf("n/a\n");
    } else {
        printf("%d", res);
    }
    return 0;
}

int prime(int inp_num) {
    if (inp_num <= 1) return 0;
    int deli = 2;
    while (deli < inp_num) {
        int i = inp_num;
        while (i >= deli) {
            i -= deli;
        }
        if (i == 0) return 0;
        deli++;
    }
    return 1;
}

int largest_prime(int x) {
    if (x <= 1) return -1;
    int largest = -1;
    for (int i = 2; i <= x; i++) {
        int temp = x;
        if (prime(i) == 1) {
            while (temp >= i) {
                temp -= i;
            }
            if (temp == 0) {
                largest = i;
            }
        }
    }
    return largest;
}