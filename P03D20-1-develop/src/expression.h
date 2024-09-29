#ifndef EXPRESSION_H
#define EXPRESSION_H

typedef struct Token {
    char type;  // 'n' for number, 'o' for operator, 'v' for variable
    double value;
    char op;
} Token;

Token* parse_expression(const char* expr, int* size);
void free_tokens(Token* tokens);

#endif