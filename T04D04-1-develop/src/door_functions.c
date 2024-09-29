#include <math.h>
#include <stdio.h>

#define PI 3.14159265358979323846

// Agnesi
double verziere(double x) { return ((1.0 / (1 + pow(x, 2)))); }

// Bernoulli
double lemniscate(double x) { return sqrt(sqrt(1 + 4 * pow(x, 2)) - pow(x, 2) - 1); }

// Квадратичная гипербола
double hyperbola(double x) { return (1.0 / pow(x, 2)); }

int main() {
    double x;
    double step = (2 * PI) / 41;

    for (int i = 0; i < 42; i++) {
        x = -PI + i * step;
        double res = verziere(x);
        printf("%.7lf | ", x);
        if (isnan(res) || isinf(res)) {
            printf("- | ");
        } else {
            printf("%.7lf | ", res);
        }
        res = lemniscate(x);
        if (isnan(res) || isinf(res)) {
            printf("- | ");
        } else {
            printf("%.7lf | ", res);
        }
        res = hyperbola(x);
        if (isnan(res) || isinf(res)) {
            printf("-\n");
        } else {
            printf("%.7lf\n", res);
        }
    }
    return 0;
}
