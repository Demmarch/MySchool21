#include <stdio.h>
#include <stdlib.h>

void dyn1(const int size1, const int size2);
void dyn2(const int size1, const int size2);
void dyn3(const int size1, const int size2);
void stat(const int size1, const int size2);

int main() {
    int flag = 0;
    int mode;
    int size1;
    int size2;
    scanf("%d%d%d", &mode, &size1, &size2);
    if (mode == (int)mode && size1 == (int)size1 && size2 == (int)size2 && mode >= 1 && mode <= 4) {
        if (mode == 1) {
            stat(size1, size2);
        } else if (mode == 2) {
            dyn1(size1, size2);
        } else if (mode == 3) {
            dyn2(size1, size2);
        } else if (mode == 4) {
            dyn3(size1, size2);
        }
    } else {
        printf("n/a");
        flag = 1;
    }
    return flag;
}

void dyn1(const int size1, const int size2) {
    int** a = NULL;

    a = (int**)malloc(size1 * size2 * sizeof(int*) + size1 * sizeof(int));
    if (!a) {
        printf("n/a");
        return;
    }
    a[0] = (int*)(a + size1);
    for (int i = 1; i < size1; i++) {
        a[i] = a[0] + i * size2;
    }

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (scanf("%d", &a[i][j]) != 1) {
                printf("n/a");
                return;
            }
        }
    }

    for (int i = 0; i < size1 - 1; i++) {
        for (int j = 0; j < size2 - 1; j++) {
            printf("%d ", a[i][j]);
        }
        printf("%d", a[i][size2 - 1]);
        printf("\n");
    }
    for (int i = size1 - 1; i < size1; i++) {
        for (int j = 0; j < size2 - 1; j++) {
            printf("%d ", a[i][j]);
        }
        printf("%d", a[i][size2 - 1]);
    }
    free(a);
}

void dyn2(const int size1, const int size2) {
    int** a = NULL;

    a = (int**)malloc(size1 * sizeof(int*));
    if (!a) {
        printf("n/a");
        return;
    }
    for (int i = 1; i < size1; i++) {
        a[i] = malloc(size2 * sizeof(int));
    }

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (scanf("%d", &a[i][j]) != 1) {
                printf("n/a");
                return;
            }
        }
    }

    for (int i = 0; i < size1 - 1; i++) {
        for (int j = 0; j < size2 - 1; j++) {
            printf("%d ", a[i][j]);
        }
        printf("%d", a[i][size2 - 1]);
        printf("\n");
    }
    for (int i = size1 - 1; i < size1; i++) {
        for (int j = 0; j < size2 - 1; j++) {
            printf("%d ", a[i][j]);
        }
        printf("%d", a[i][size2 - 1]);
    }
    for (int i = 0; i < size1; i++) {
        free(a[i]);
    }
    free(a);
}

void dyn3(const int size1, const int size2) {
    int** a = NULL;
    int* val = NULL;

    a = (int**)malloc(size1 * sizeof(int*));
    if (!a) {
        printf("n/a");
        return;
    }
    val = (int*)malloc(size1 * size2 * sizeof(int));
    for (int i = 1; i < size1; i++) {
        a[i] = val + size2 * i;
    }

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (scanf("%d", &a[i][j]) != 1) {
                printf("n/a");
                return;
            }
        }
    }

    for (int i = 0; i < size1 - 1; i++) {
        for (int j = 0; j < size2 - 1; j++) {
            printf("%d ", a[i][j]);
        }
        printf("%d", a[i][size2 - 1]);
        printf("\n");
    }
    for (int i = size1 - 1; i < size1; i++) {
        for (int j = 0; j < size2 - 1; j++) {
            printf("%d ", a[i][j]);
        }
        printf("%d", a[i][size2 - 1]);
    }
    free(val);
    free(a);
}

void stat(const int size1, const int size2) {
    int a[size1][size2];
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (scanf("%d", &a[i][j]) != 1) {
                printf("n/a");
                return;
            }
        }
    }

    for (int i = 0; i < size1 - 1; i++) {
        for (int j = 0; j < size2 - 1; j++) {
            printf("%d ", a[i][j]);
        }
        printf("%d", a[i][size2 - 1]);
        printf("\n");
    }
    for (int i = size1 - 1; i < size1; i++) {
        for (int j = 0; j < size2 - 1; j++) {
            printf("%d ", a[i][j]);
        }
        printf("%d", a[i][size2 - 1]);
    }
}