#include "expression.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

Token* parse_expression(const char* expr, int* size) {
    int length = strlen(expr);
    Token* tokens = (Token*)malloc(sizeof(Token) * length);
    int token_count = 0;
    char* endptr;

    for (int i = 0; i < length; ++i) {
        if (isdigit(expr[i]) || (expr[i] == '.' && isdigit(expr[i + 1]))) {
            tokens[token_count].type = 'n';
            tokens[token_count].value = strtod(&expr[i], &endptr);
            i = endptr - expr - 1;
        } else if (strchr("+-*/^", expr[i])) {
            tokens[token_count].type = 'o';
            tokens[token_count].op = expr[i];
        } else if (expr[i] == 'x') {
            tokens[token_count].type = 'v';
        } else if (strncmp(&expr[i], "sin", 3) == 0 || strncmp(&expr[i], "cos", 3) == 0 ||
                   strncmp(&expr[i], "tan", 3) == 0) {
            tokens[token_count].type = 'o';
            tokens[token_count].op = expr[i];  // handle trigonometric functions
            i += 2;
        } else if (expr[i] == '(' || expr[i] == ')') {
            tokens[token_count].type = 'o';
            tokens[token_count].op = expr[i];
        }
        token_count++;
    }

    *size = token_count;
    return tokens;
}

void free_tokens(Token* tokens) { free(tokens); }