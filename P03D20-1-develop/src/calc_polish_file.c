#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

double calc_polish(const char *polish, double x) {
    Stack stack;
    init_stack(&stack, 0);
    char *buf = (char *)polish;
    puts(polish);

    char *token = strtok(buf, " ");
    while (token != NULL) {
        if (strcmp(token, "+") == 0) {
            double b = pop(&stack);
            double a = pop(&stack);
            push(&stack, a + b);
        } else if (strcmp(token, "-") == 0) {
            double b = pop(&stack);
            double a = pop(&stack);
            push(&stack, a - b);
        } else if (strcmp(token, "*") == 0) {
            double b = pop(&stack);
            double a = pop(&stack);
            push(&stack, a * b);
        } else if (strcmp(token, "/") == 0) {
            double b = pop(&stack);
            double a = pop(&stack);
            push(&stack, a / b);
        } else if (strcmp(token, "sin") == 0) {
            double a = pop(&stack);
            push(&stack, sin(a));
        } else if (strcmp(token, "cos") == 0) {
            double a = pop(&stack);
            push(&stack, cos(a));
        } else if (strcmp(token, "tan") == 0) {
            double a = pop(&stack);
            push(&stack, tan(a));
        } else if (strcmp(token, "ctg") == 0) {
            double a = pop(&stack);
            push(&stack, 1 / tan(a));
        } else if (strcmp(token, "sqrt") == 0) {
            double a = pop(&stack);
            push(&stack, sqrt(a));
        } else if (strcmp(token, "ln") == 0) {
            double a = pop(&stack);
            push(&stack, log(a));
        } else {
            push(&stack, (strcmp(token, "x") == 0) ? x : atof(token));
        }
        printf("\n**%s**", token);
        token = strtok(NULL, " ");
    }
    double result = pop(&stack);
    printf("\nfinish %f;\n", result);
    destroy_stack(&stack);
    return result;
}