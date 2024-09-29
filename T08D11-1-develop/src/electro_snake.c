#include <stdio.h>
#include <stdlib.h>

void sort_vertical(int **matrix, int n, int m, int **result_matrix);
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);
int input(int ***matrix, int *n, int *m);
void output(int **matrix, int n, int m);

int main() {
    int **matrix, **result;
    int n, m;

    if (input(&matrix, &n, &m) == 1) {
        printf("n/a");
        return 1;
    }

    result = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        result[i] = (int *)malloc(m * sizeof(int));
    }

    sort_vertical(matrix, n, m, result);
    output(result, n, m);

    printf("\n\n");

    sort_horizontal(matrix, n, m, result);
    output(result, n, m);

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
        free(result[i]);
    }
    free(matrix);
    free(result);

    return 0;
}

void sort_vertical(int **matrix, int n, int m, int **result_matrix) {
    for (int i = 0; i < m; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                result_matrix[j][i] = matrix[j][i];
            }
        } else {
            for (int j = n - 1; j >= 0; j--) {
                result_matrix[j][i] = matrix[j][i];
            }
        }
    }
}

void sort_horizontal(int **matrix, int n, int m, int **result_matrix) {
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
                result_matrix[i][j] = matrix[i][j];
            }
        } else {
            for (int j = m - 1; j >= 0; j--) {
                result_matrix[i][j] = matrix[i][j];
            }
        }
    }
}
int input(int ***matrix, int *n, int *m) {
    int flag = 0;
    if (scanf("%d %d", n, m) != 2) {
        flag = 1;
    }
    if (*n == 0 || *m == 0) {
        flag = 1;
    }
    if (flag != 1) {
        *matrix = (int **)malloc(*n * sizeof(int *));
        for (int i = 0; i < *n; i++) {
            (*matrix)[i] = (int *)malloc(*m * sizeof(int));
        }

        for (int i = 0; i < *n; i++) {
            for (int j = 0; j < *m; j++) {
                scanf("%d", &(*matrix)[i][j]);
            }
        }
    }
    return flag;
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("%d", matrix[i][m - 1]);
        printf("\n");
    }
    for (int j = 0; j < m - 1; j++) {
        printf("%d ", matrix[n - 1][j]);
    }
    printf("%d", matrix[n - 1][m - 1]);
}