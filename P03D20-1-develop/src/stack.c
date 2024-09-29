#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void init_stack(Stack *stack, double first_value) {
    stack->len = 2;
    stack->size = 1;
    stack->data = malloc((stack->len + 1) * sizeof(double));
    if (!stack->data) {
        perror("Failed to initialize stack");
        exit(EXIT_FAILURE);
    }
    stack->data[0] = first_value;
}

void push(Stack *stack, double value) {
    if (stack->size >= stack->len) {
        stack->len *= 2;
        stack->data = realloc(stack->data, stack->len * sizeof(double));
        if (!stack->data) {
            perror("Failed to push to stack");
            exit(EXIT_FAILURE);
        }
    }
    stack->data[stack->size++] = value;
}

double pop(Stack *stack) {
    if (stack->size == 0) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[--stack->size];
}

void destroy_stack(Stack *stack) {
    free(stack->data);
    stack->len = 2;
    stack->size = 1;
}