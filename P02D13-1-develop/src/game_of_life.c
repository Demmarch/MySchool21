#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 25
#define COLUMNS 80

void printField(int arr[ROWS][COLUMNS], int delay, int generation, int population);
void updateGame(int arr[ROWS][COLUMNS], int next_arr[ROWS][COLUMNS]);
void countCells(int arr[ROWS][COLUMNS], int x, int y, int *cells_around);
void loadpreset(int arr[ROWS][COLUMNS], const char *choice);
void randomize(int arr[ROWS][COLUMNS]);
void countPopulation(int arr[ROWS][COLUMNS], int *population);

int main() {
    printf(
        "Choose preset:\n1. 5x5_square.txt\n2. cow.txt\n3. "
        "gospel_glider_gun.txt\n4. gunSim.txt\n5. "
        "pulsar.txt\n6. Random preset\n");
    char c = getchar();
    const char *map = NULL;
    switch (c) {
        case '1':
            map = "5x5_square.txt";
            break;
        case '2':
            map = "cow.txt";
            break;
        case '3':
            map = "gospel_glider_gun.txt";
            break;
        case '4':
            map = "gunSim.txt";
            break;
        case '5':
            map = "pulsar.txt";
            break;
        case '6':
            c = 'r';
            break;
        default:
            return 1;
    }

    int field[ROWS][COLUMNS];
    if (c != 'r') {
        loadpreset(field, map);
    } else {
        randomize(field);
    }
    int next_field[ROWS][COLUMNS];
    if (field[0][0] == 404) {
        endwin();
        return 1;
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            next_field[i][j] = 0;
        }
    }
    initscr();
    noecho();
    cbreak();
    timeout(10);
    int gameover = 0;
    int delay = 10000;
    int generation = 0;
    int population = 0;
    while (!gameover) {
        printField(field, delay, generation, population);

        char key = getch();

        switch (key) {
            case 'q':
                gameover = 1;
                printw("\nGame is over");
                break;
            case 'k':
                if (delay < 1000000) delay *= 10;
                break;
            case 'm':
                if (delay > 1) {
                    delay /= 10;
                }
                break;
        }
        updateGame(field, next_field);
        countPopulation(field, &population);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                field[i][j] = next_field[i][j];
            }
        }
        generation++;
        usleep(delay);
    }
    timeout(-1);
    getch();

    endwin();
    return 0;
}

void loadpreset(int arr[ROWS][COLUMNS], const char *choice) {
    FILE *map;
    char c;
    if ((map = fopen(choice, "r")) == NULL) {
        printw("Failed to open file");
        arr[0][0] = 404;
    } else {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                fscanf(map, " %c", &c);
                arr[i][j] = c - '0';
            }
        }
        fclose(map);
    }
}

void randomize(int arr[ROWS][COLUMNS]) {
    srand(0);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            arr[i][j] = rand() % 2;
        }
    }
}

void printField(int arr[ROWS][COLUMNS], int delay, int generation, int population) {
    clear();
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (arr[i][j] == 0)
                mvaddch(i, j, '-');
            else
                mvaddch(i, j, '0');
        }
    }
    printw("\nDelay: %d", delay);
    printw("\nGeneration: %d", generation);
    printw("\nPopulation: %d", population);
    refresh();
}

void updateGame(int arr[ROWS][COLUMNS], int next_arr[ROWS][COLUMNS]) {
    for (int x = 0; x < ROWS; x++) {
        for (int y = 0; y < COLUMNS; y++) {
            int cells_around;
            countCells(arr, x, y, &cells_around);

            if (arr[x][y] == 1 && (cells_around < 2 || cells_around > 3))
                next_arr[x][y] = 0;
            else if (arr[x][y] == 0 && cells_around == 3)
                next_arr[x][y] = 1;
            else
                next_arr[x][y] = arr[x][y];
        }
    }
    for (int x = 0; x < ROWS; x++) {
        for (int y = 0; y < COLUMNS; y++) {
            int cells_around;
            countCells(arr, x, y, &cells_around);

            if (arr[x][y] == 1 && (cells_around < 2 || cells_around > 3))
                next_arr[x][y] = 0;
            else if (arr[x][y] == 0 && cells_around == 3)
                next_arr[x][y] = 1;
            else
                next_arr[x][y] = arr[x][y];
        }
    }
}

void countCells(int arr[ROWS][COLUMNS], int x, int y, int *cells_around) {
    int nx, ny;
    *cells_around = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i != 0 || j != 0) {
                nx = (x + i + ROWS) % ROWS;
                ny = (y + j + COLUMNS) % COLUMNS;
                *cells_around += arr[nx][ny];
            }
        }
    }
}

void countPopulation(int arr[ROWS][COLUMNS], int *population) {
    *population = 0;
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLUMNS; j++)
            if (arr[i][j] == 1) (*population)++;
}
