#include "perevod.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTACK 100
#define MAXEXPR 100

void initStack(PerStack *s) { s->top = -1; }

int isEmpty(PerStack *s) { return s->top == -1; }

int isFull(PerStack *s) { return s->top == MAXSTACK - 1; }

void pushtoStack(PerStack *s, char item) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->items[++(s->top)] = item;
}

char popFromStack(PerStack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

char peek(PerStack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[s->top];
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

int isOperator(char c) { return c == '+' || c == '-' || c == '*' || c == '/'; }

int my_isalpha(char c) { return (c >= 'a' && c <= 'z'); }

int my_isspace(char c) { return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v'; }

int my_isalnum(char c) { return (c >= '0' && c <= '9') || my_isalpha(c); }

void infixToPostfix(char *infix, char *postfix) {
    PerStack s;
    initStack(&s);
    int i = 0, j = 0;
    char token, topOp;
    char function[10];
    int funcIndex = 0;
    int inFunction = 0;
    while ((token = infix[i++]) != '\0') {
        if (my_isspace(token)) {
            continue;
        }
        if (my_isalnum(token) || token == '.') {
            postfix[j++] = token;
        } else if (token == '(') {
            pushtoStack(&s, token);
        } else if (token == ')') {
            while (!isEmpty(&s) && (topOp = popFromStack(&s)) != '(') {
                postfix[j++] = ' ';
                postfix[j++] = topOp;
            }

        } else if (isOperator(token)) {
            postfix[j++] = ' ';
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(token)) {
                postfix[j++] = popFromStack(&s);
                postfix[j++] = ' ';
            }
            pushtoStack(&s, token);
        }
    }
    while (!isEmpty(&s)) {
        postfix[j++] = ' ';
        postfix[j++] = popFromStack(&s);
    }
    postfix[j] = '\0';
}

// int main() {
//     char infix[MAXEXPR], postfix[MAXEXPR];

//     printf("Введите математическое выражение: ");
//     fgets(infix, MAXEXPR, stdin);
//     infix[strlen(infix) - 1] = '\0';  // Убираем символ новой строки

//     infixToPostfix(infix, postfix);
//     printf("Обратная польская нотация: %s\n", postfix);

//     return 0;
// }