#include "data_stat.h"

double max(double *data, int n) {
    double max_el = data[0];
    for (int i = 0; i < n; i++) {
        max_el = (max_el < data[i]) ? data[i] : max_el;
    }
    return max_el;
}
double min(double *data, int n) {
    double min_el = data[0];
    for (int i = 0; i < n; i++) {
        min_el = (min_el > data[i]) ? data[i] : min_el;
    }
    return min_el;
}
double mean(double *data, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / n;
}

double variance(double *data, int n) {
    double mean_v = mean(data, n);
    double sum_sq_diff = 0.0;
    for (int i = 0; i < n; i++) {
        sum_sq_diff += (data[i] - mean_v) * (data[i] - mean_v);
    }
    return sum_sq_diff / n;
}

void sort(double *data, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (data[j] > data[j + 1]) {
                double b = data[j];
                data[j] = data[j + 1];
                data[j + 1] = b;
            }
        }
    }
}