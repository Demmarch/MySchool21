#include <stdio.h>

#define N 15
#define M 13

void transform(int *buf, int **matr, int n, int m);
void make_picture(int **picture, int n, int m);
void reset_picture(int **picture, int n, int m);
void print_picture(int **picture, int n, int m);

int main() {
    int picture_data[N][M];
    int *picture[N];
    transform((int *)picture_data, picture, N, M);

    make_picture(picture, N, M);
    print_picture(picture, N, M);

    return 0;
}

void make_picture(int **picture, int n, int m) {
    int frame_w[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int frame_h[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int tree_trunk[] = {7, 7, 7, 7};
    int tree_foliage[] = {3, 3, 3, 3};
    int sun_data[6][5] = {{0, 6, 6, 6, 6}, {0, 0, 6, 6, 6}, {0, 0, 6, 6, 6},
                          {0, 6, 0, 0, 6}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

    reset_picture(picture, n, m);

    int foliage_start_col = 3;
    int foliage_start_row = 2;
    int length_tree_foliage = sizeof(tree_foliage) / sizeof(tree_foliage[0]);

    for (int i = 0; i < length_tree_foliage; i++) {
        if (i == 1) {
            picture[foliage_start_row + i][foliage_start_col + i + 1] = tree_foliage[i];
            picture[foliage_start_row + i][foliage_start_col - i] = tree_foliage[i];
        } else if (i == 2) {
            picture[foliage_start_row + i][foliage_start_col + i] = tree_foliage[i];
            picture[foliage_start_row + i][foliage_start_col - 1] = tree_foliage[i];
        }
        picture[foliage_start_row + i][foliage_start_col] = tree_foliage[i];
        picture[foliage_start_row + i][foliage_start_col + 1] = tree_foliage[i];
    }
    int trunk_start_col = 4;
    int trunk_start_row = 7;
    int length_tree_trunk = sizeof(tree_trunk) / sizeof(tree_trunk[0]);

    for (int i = 0; i < length_tree_trunk; i++) {
        if (i == 1) {
            picture[trunk_start_row - i][trunk_start_col] = tree_trunk[i];
            picture[trunk_start_row - i][trunk_start_col - i] = tree_trunk[i];
        } else if (i == 3) {
            picture[trunk_start_row + i][trunk_start_col + 1] = tree_trunk[i];
            picture[trunk_start_row + i][trunk_start_col - 2] = tree_trunk[i];
        }
        picture[trunk_start_row + i][trunk_start_col] = tree_trunk[i];
        picture[trunk_start_row + i][trunk_start_col - 1] = tree_trunk[i];
    }
    int sun_start_col = 7;
    int sun_start_row = 1;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            picture[sun_start_row + i][sun_start_col + j] = sun_data[i][j];
        }
    }
    int length_frame_w = sizeof(frame_w) / sizeof(frame_w[0]);
    int length_frame_h = sizeof(frame_h) / sizeof(frame_h[0]);

    for (int i = 0; i < length_frame_w; i++) {
        picture[0][i] = frame_w[i];
        picture[n / 2][i] = frame_w[i];
        picture[n - 1][i] = frame_w[i];
    }

    for (int i = 0; i < length_frame_h; i++) {
        picture[i][0] = frame_h[i];
        picture[i][m / 2] = frame_h[i];
        picture[i][m - 1] = frame_h[i];
    }
}

void reset_picture(int **picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            picture[i][j] = 0;
        }
    }
}

void transform(int *buf, int **matr, int n, int m) {
    for (int i = 0; i < n; i++) {
        matr[i] = buf + i * m;
    }
}

void print_picture(int **picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (picture[i][j] == 0) {
                printf(" 0 ");
            } else {
                printf(" %d ", picture[i][j]);
            }
        }
        printf("\n");
    }
}