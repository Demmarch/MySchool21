#ifndef PEREVOD_H
#define PEREVOD_H

#define MAXSTACK 100
#define MAXEXPR 100

typedef struct {
    char items[MAXSTACK];
    int top;
} PerStack;

int isOperator(char c);
int my_isalpha(char c);
int my_isspace(char c);
int my_isalnum(char c);
int precedence(char op);
char peek(PerStack *s);
char popFromStack(PerStack *s);
void pushToStack(PerStack *s, char item);
int isFull(PerStack *s);
int isEmpty(PerStack *s);
void initStack(PerStack *s);
void infixToPostfix(char *infix, char *postfix);

#endif  // PEREVOD_H