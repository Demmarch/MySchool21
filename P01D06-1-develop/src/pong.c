#include <stdio.h>

void render(int racket1Y, int racket2Y, int ballX, int ballY, int score_1, int score_2);
int racket_func(int racketY, char c);
int vect_y(int bally, int vector);
int vect_x(int racket1Y, int racket2Y, int ballx, int bally, int vector);
int ball_touch(int ballx);

int main() {
    const int w = 80;
    const int h = 25;
    int racket1Y = h / 2 - 1;
    int racket2Y = racket1Y;
    int ball_x = w / 2;
    int ball_y = h / 2;
    int vector_x = -1;
    int vector_y = -1;
    const int zero_score = 0;
    int player_1_score = zero_score;
    int player_2_score = zero_score;
    render(racket1Y, racket2Y, ball_x, ball_y, player_1_score, player_2_score);
    while (player_1_score < 21 && player_2_score < 21) {
        char c;
        scanf("%c", &c);
        if (c == 'a' || c == 'z' || c == 'A' || c == 'Z') {
            c = (c == 'a' || c == 'A') ? '0' : '1';
            racket1Y = racket_func(racket1Y, c);
        } else if (c == 'm' || c == 'k' || c == 'M' || c == 'K') {
            c = (c == 'k' || c == 'K') ? '0' : '1';
            racket2Y = racket_func(racket2Y, c);
        } else if (c == ' ') {
            // void if
        } else {
            render(racket1Y, racket2Y, ball_x, ball_y, player_1_score, player_2_score);
            continue;
        }
        vector_y = vect_y(ball_y, vector_y);
        ball_y += vector_y;
        if (ball_y < 1) {
            ball_y = 2;
            vector_y = 1;
        } else if (ball_y > 23) {
            ball_y = 22;
            vector_y = -1;
        }
        vector_x = vect_x(racket1Y, racket2Y, ball_x, ball_y, vector_x);
        ball_x += vector_x;
        int touch_result = ball_touch(ball_x);
        if (touch_result == 1) {
            player_1_score++;
            ball_x = w / 2;
            ball_y = h / 2;
        } else if (touch_result == 2) {
            player_2_score++;
            ball_x = w / 2;
            ball_y = h / 2;
        }
        render(racket1Y, racket2Y, ball_x, ball_y, player_1_score, player_2_score);
    }
    char p_won = (player_1_score > player_2_score) ? '1' : '2';
    printf("\33[0d\33[2J");
    printf("\n\n");
    for (int x = 0; x < w; x++) {
        if (x == 32) {
            printf("Игрок %c победил\n\n\n", p_won);
            return 1;
        } else {
            printf(" ");
        }
    }
}

void render(int racket1Y, int racket2Y, int ballX, int ballY, int score_1, int score_2) {
    printf("\33[0d\33[2J");
    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 80; x++) {
            if (x == ballX && y == ballY) {
                printf("%c", 'o');  // мяч
            } else if (x == 0 || x == 79 || x == 40) {
                printf("%c", '|');  // стены
            } else if (y == 0 || y == 24) {
                printf("-");  // отрисовывается нижняя и верхняя грань
            } else if (x == 1 && (y >= racket1Y && y < racket1Y + 3)) {
                printf("%c", '|');  // левая ракетка
            } else if (x == 78 && (y >= racket2Y && y < racket2Y + 3)) {
                printf("%c", '|');  // правая ракетка
            } else if (x == 34 && y == 12) {
                printf("%02d", score_1);  // очки первого
                x++;                      // crutch
            } else if (x == 46 && y == 12) {
                printf("%02d", score_2);  // второго
                x++;                      // crutch
            } else {
                printf("%c", ' ');  // пустое место
            }
        }
        printf("\n");  // переход на новую строку после каждой строки поля
    }
    return;
}

int racket_func(int racketY, char c) {
    switch (c) {
        case '1': {
            if (racketY < 21) {
                racketY++;
            }
        } break;
        case '0': {
            if (racketY > 1) {
                racketY--;
            }
            break;
        }
        default:

            break;
    }
    return racketY;
}

int vect_y(int bally, int vector) {
    if (bally == 1 || bally == 23) vector = -vector;
    return vector;
}

int vect_x(int racket1Y, int racket2Y, int ballx, int bally, int vector) {
    if ((bally >= racket1Y && bally <= racket1Y + 3) && ballx == 2) vector = -vector;
    if ((bally >= racket2Y && bally <= racket2Y + 3) && ballx == 77) vector = -vector;
    return vector;
}

int ball_touch(int ballx) {
    if (ballx > 78) {
        return 1;
    }
    if (ballx < 1) {
        return 2;
    }
    return 0;
}