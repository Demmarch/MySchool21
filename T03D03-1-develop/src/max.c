#include <stdio.h>

int max(int a, int b);

int main() {
    int x;
    int y;
    if (scanf("%d %d", &x, &y) != 2) {
        printf("n/a\n");
        return 0;
    }
    printf("%d\n", max((int)x, (int)y));

    return 0;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}