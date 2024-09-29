#include <stdio.h>
#include <stdlib.h>

double det(double **matrix, int n, int m);
int input(double ***matrix, int *n, int *m);
void output(double det);

int main() {
    double **matrix;
    int n, m;

    if (input(&matrix, &n, &m) == 1) {
        printf("n/a");
        return 1;
    }

    double determinant = det(matrix, n, m);
    if (determinant == 404.404404) {
        printf("n/a");
        return 1;
    }

    output(determinant);

    // Освобождение памяти
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

double det(double **matrix, int n, int m) {
    if (n != m) {
        return 404.404404;  // Матрица не является квадратной
    }

    if (n == 1) {
        return matrix[0][0];  // Определитель единственного элемента равен самому
                              // элементу
    }

    double determinant = 0.0;

    for (int i = 0; i < n; i++) {
        double cofactor = matrix[0][i];

        int submatrix_size = n - 1;
        double **submatrix = (double **)malloc(submatrix_size * sizeof(double *));
        for (int j = 0; j < submatrix_size; j++) {
            submatrix[j] = (double *)malloc(submatrix_size * sizeof(double));
        }

        int submatrix_row = 0;
        for (int j = 1; j < n; j++) {
            int submatrix_col = 0;
            for (int k = 0; k < n; k++) {
                if (k != i) {
                    submatrix[submatrix_row][submatrix_col] = matrix[j][k];
                    submatrix_col++;
                }
            }
            submatrix_row++;
        }

        double submatrix_det = det(submatrix, submatrix_size, submatrix_size);
        determinant += (i % 2 == 0 ? 1 : -1) * cofactor * submatrix_det;

        for (int j = 0; j < submatrix_size; j++) {
            free(submatrix[j]);
        }
        free(submatrix);
    }

    return determinant;
}

int input(double ***matrix, int *n, int *m) {
    int flag = 0;
    if (scanf("%d %d", n, m) != 2) {
        flag = 1;
    }
    if (*n == 0 || *m == 0) {
        flag = 1;
    }
    if (flag != 1) {
        *matrix = (double **)malloc(*n * sizeof(double *));
        if (!(*matrix)) {
            flag = 1;
        } else {
            for (int i = 0; i < *n; i++) {
                (*matrix)[i] = (double *)malloc(*m * sizeof(double));
            }
            for (int i = 0; i < *n; i++) {
                for (int j = 0; j < *m; j++) {
                    scanf("%lf", &(*matrix)[i][j]);
                }
            }
        }
    }
    return flag;
}

void output(double det) { printf("%.6lf", det); }