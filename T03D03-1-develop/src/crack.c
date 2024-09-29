#include <stdio.h>

int crack(float a, float b);

int main() {
    double x;
    double y;
    if (scanf("%lf %lf", &x, &y) != 2) {
        printf("n/a\n");
        return 0;
    }
    if (crack(x, y) == 1) {
        printf("GOTCHA");
        return 0;
    }
    printf("MISS");
    return 0;
}

int crack(float a, float b) {
    if (a * a + b * b < 25) {
        return 1;
    }
    return 0;
}