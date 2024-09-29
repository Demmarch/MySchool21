#include "graph.h"

#include <math.h>
#include <stdio.h>
#include <string.h>

#include "calc_polish_file.h"
#include "graph_lib.h"
#include "perevod.h"
#include "polish_notation.h"

#define WIDTH 80
#define HEIGHT 25
#define PI 3.14159265358979323846
#define STEP 0.15906798246

// void plot_graph(const char* expr) {
//     char grid[HEIGHT][WIDTH];
//     for (int i = 0; i < HEIGHT; ++i)
//         for (int j = 0; j < WIDTH; ++j) grid[i][j] = '.';

//     int token_size = 0;
//     Token* tokens = parse_expression(expr, &token_size);

//     for (int x = 0; x < WIDTH; ++x) {
//         double real_x = (4 * PI) * x / (WIDTH - 1);
//         double real_y = evaluate_rpn(tokens, token_size, real_x);
//         int y = (int)((HEIGHT - 1) / 2) - (int)round(real_y * (HEIGHT - 1) / 2);

//         if (y >= 0 && y < HEIGHT) {
//             grid[y][x] = '*';
//         }
//     }
//     for (int i = 0; i < HEIGHT; ++i) {
//         for (int j = 0; j < WIDTH; ++j) {
//             putchar(grid[i][j]);
//         }
//         putchar('\n');
//     }

//     free_tokens(tokens);
// }

int main() {
    int buffer[80];
    char infix[MAXEXPR], postfix[MAXEXPR];
    fgets(infix, MAXEXPR, stdin);
    infix[strlen(infix) - 1] = '\0';
    infixToPostfix(infix, postfix);
    int token_size = 0;
    Token* tokens = parse_expression(postfix, &token_size);
    printf("\npostfix: \"%s\"\n", postfix);

    char sample[] = "1 x /";
    // printf("#%f#", (int)calc_polish(sample, 1));
    for (int i = 0; i < 80; ++i) {
        buffer[i] = (int)round(12.0 * calc_polish(sample, STEP * i));

        // buffer[i] = (int)round(12.0 * calc_polish(sample, STEP * i));
        // buffer[i] = (int)round(12.0*sin(STEP * i));
        printf("%f,", calc_polish(sample, STEP * i));
    }
    print_graph(buffer);
}