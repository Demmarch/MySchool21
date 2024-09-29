#include <stdio.h>

int sum(float a, float b);
int dif(float a, float b);
int mult(float a, float b);
float divi(float a, float b);

int main() {
    float x;
    float y;

    scanf("%f %f", &x, &y);
    if (x != (int)x) {
        printf("n/a\n");
        return 0;
    }

    if (divi(x, y) == -1) {
        printf("%d %d %d n/a\n", sum(x, y), dif(x, y), mult(x, y));
        return 0;
    }

    printf("%d %d %d %.2f\n", sum(x, y), dif(x, y), mult(x, y), divi(x, y));
    return 0;
}

int sum(float a, float b) { return (int)(a + b); }

int dif(float a, float b) { return (int)(a - b); }

int mult(float a, float b) { return (int)(a * b); }

float divi(float a, float b) {
    if (b == 0) {
        return -1;
    }
    return a / b;
}