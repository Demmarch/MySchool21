#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int n);
void sigma_func(int *a, int n, double *sigma);
int check_num(int num, double mean_v, double sigma);

int main() {
    int n, data[NMAX];

    if (input(data, &n) != 0) {
        printf("n/a");
        return 1;
    }

    double mean_v = mean(data, n);
    double sigma;
    sigma_func(data, n, &sigma);

    for (int i = 0; i < n; i++) {
        if (check_num(data[i], mean_v, sigma)) {
            printf("%d", data[i]);
            return 0;
        }
    }
    printf("0");
    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) != 1 || *n < 1 || *n > NMAX) {
        return 1;
    }

    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return 1;
        }
    }

    if (getchar() != '\n') {
        return 1;  // check input (for example, if n = 2 but input 1 2 3 -> n/a)
    }

    return 0;
}

double mean(int *a, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum / n;
}

void sigma_func(int *a, int n, double *sigma) {
    double mean_v = mean(a, n);
    double variance = 0;

    for (int i = 0; i < n; i++) {
        variance += (a[i] - mean_v) * (a[i] - mean_v);
    }

    *sigma = (n > 1) ? mean_v + 3 * sqrt(variance / (n - 1)) : mean_v;
}

int check_num(int num, double mean_v, double sigma) {
    return (num % 2 == 0) && (num >= mean_v) && (num != 0) && (num <= sigma);
}