#include "polish_notation.h"

#include <math.h>
#include <stdio.h>

#include "stack.h"

double apply_operator(char op, double a, double b) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '^':
            return pow(a, b);
    }
    return 0;
}

double evaluate_rpn(Token* tokens, int size, double x) {
    Stack* stack = create_stack(size);
    for (int i = 0; i < size; ++i) {
        printf("%c %d\n", tokens[i].type, size);
        if (tokens[i].type == 'n') {
            push(stack, tokens[i].value);
        } else if (tokens[i].type == 'v') {
            push(stack, x);
        } else if (tokens[i].type == 'o') {
            if (tokens[i].op == 's') {
                double val = pop(stack);
                push(stack, sin(val));
            } else if (tokens[i].op == 'c') {
                double val = pop(stack);
                push(stack, cos(val));
            } else if (tokens[i].op == 't') {
                double val = pop(stack);
                push(stack, tan(val));
            } else {
                double b = pop(stack);
                double a = pop(stack);
                push(stack, apply_operator(tokens[i].op, a, b));
            }
        }
    }
    double result = pop(stack);
    free_stack(stack);
    return result;
}