#include "stackper.h"

#include <stdlib.h>

Stack* create_stack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (double*)malloc(sizeof(double) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

void push(Stack* stack, double value) {
    if (stack->top == stack->capacity - 1) return;
    stack->data[++stack->top] = value;
}

double pop(Stack* stack) {
    if (stack->top == -1) return 0;
    return stack->data[stack->top--];
}

int is_empty(Stack* stack) { return stack->top == -1; }

void free_stack(Stack* stack) {
    free(stack->data);
    free(stack);
}