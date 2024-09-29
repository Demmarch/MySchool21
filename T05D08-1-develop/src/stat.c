#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];

    if (input(data, &n) == 1) {
        printf("n/a");
        return 1;
    }

    output(data, n);
    output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

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

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int max(int *a, int n) {
    int max_v = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max_v) {
            max_v = a[i];
        }
    }
    return max_v;
}

int min(int *a, int n) {
    int min_v = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min_v) {
            min_v = a[i];
        }
    }
    return min_v;
}

double mean(int *a, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum / n;
}

double variance(int *a, int n) {
    double mean_v = mean(a, n);
    double sum_sq_diff = 0.0;
    for (int i = 0; i < n; i++) {
        sum_sq_diff += (a[i] - mean_v) * (a[i] - mean_v);
    }
    return sum_sq_diff / n;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}