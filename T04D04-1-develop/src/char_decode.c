#include <stdio.h>

void encode();
void decode();

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("n/a\n");
        return 1;
    }

    int mode = argv[1][0] - '0';
    if (mode < 0 || mode > 1) {
        printf("n/a\n");
        return 1;
    }

    if (mode == 0) {
        encode();
    } else {
        decode();
    }

    return 0;
}

void encode() {
    char c;
    char c1;  // crutch, lol
    while (1) {
        c = getchar();
        c1 = getchar();
        if ((c1 == ' ' || c1 == '\n') && c != ' ') {
            if (c == ' ') continue;  // Пробелы
            if (c < 32 || c > 126) {
                printf("n/a\n");
                return;
            }
            printf("%02X ", c);  // Кароче, я афигел, но оно работает
        } else {
            printf("n/a\n");
            return;
        }
        if (c1 == '\n') {
            return;
        }
    }
    printf("\n");
}

void decode() {
    char first;
    char second;
    char third;  // crutch, lol
    while (1) {
        first = getchar();
        if (first == '\n') {
            return;
        }
        if (first == ' ') {
            printf("n/a\n");
            return;
        }
        if (first == ' ') continue;  // Пробелы
        second = getchar();
        if (second == '\n') {
            printf("n/a\n");
            return;
        }
        if (second == ' ') continue;  // Пробелы
        third = getchar();
        // No comment, only pain
        if (third == ' ' || third == '\n') {
            if (!((first >= '0' && first <= '9') || (first >= 'A' && first <= 'F')) ||
                !((second >= '0' && second <= '9') || (second >= 'A' && second <= 'F'))) {
                printf("n/a\n");
                return;
            }
            int ascii = 0;
            // First symbol => ASCII code
            if (first >= '0' && first <= '9') {
                ascii = first - '0';
            } else if (first >= 'A' && first <= 'F') {
                ascii = first - 'A' + 10;  // + 10 cuz without it, it will be equal ASCII code 1 - 9
            }
            ascii *= 16;  // так надо (мы как никак в 16-ричной системе, увы)
            // Second symbol => ascii code
            if (second >= '0' && second <= '9') {
                ascii += second - '0';
            } else if (second >= 'A' && second <= 'F') {
                ascii += second - 'A' + 10;
            }
            // Check ASCII code
            if (ascii < 32 || ascii > 126) {
                printf("n/a\n");
                return;
            }
            putchar(ascii);
            putchar(' ');
        } else {
            printf("n/a\n");
            return;
        }
        if (third == '\n') {
            return;  // crutch, lol
        }
    }
}  //