#include <math.h>
#include <stdio.h>

int main() {
    double x;
    if (scanf("%lf", &x) != 1) {
        printf("n/a\n");
        return 1;
    }

    double y = 7e-3 * pow(x, 4) + ((22.8 * pow(x, 1.0 / 3) - 1e3) * x + 3) / (pow(x, 2) / 2) -
               x * pow((10 + x), (2 / x)) - 1.01;
    printf("%.1f\n", y);

    return 0;
}
