#include "data_io.h"

#include <stdio.h>

void input(double *data, const int n) {
    for (int i = 0; i < n; i++) {
        if (scanf("%lf", &data[i]) != 1) {
            printf("n/a");
            return;
        }
    }
}

void output(double *data, const int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%lf ", data[i]);
    }
    printf("%lf", data[n - 1]);
}