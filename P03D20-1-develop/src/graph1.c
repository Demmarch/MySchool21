#include <math.h>
#include <stdio.h>
#include <string.h>

#include "graph_lib.h"
#include "opstack.h"
#include "outlist.h"

double calc_polish(char *polish, double x) { return sin(x); }

int precedence(char op) {
    int ret = -1;
    switch (op) {
        case '+':
        case '-':
            ret = 1;
            break;
        case '*':
        case '/':
            ret = 2;
    }
    return ret;
}

void stacktostr(struct opstack *opstack, char *dest) {
    while (opstack->value != '\0') {
        strcat(dest, &opstack->value);
        strcat(dest, ", ");
    }
}

/* Reads a string, converts it to reverse Polish notation and returns the
   result or NULL on error. */
char *to_polish(char *str) {
    // char output[1000];
    char inbuffer[10];
    int len = strlen(str);
    struct outlist *outlist = NULL;

    // int resIndex = 0;
    struct opstack *opstack = initStack('\0');
    for (int i = 0; i < len; ++i) {
        char *c = &str[i];
        if (*c == 'x' || (*c >= '0' && *c <= '9')) {
            // output[resIndex++] = *c;
            addToOutlist(outlist, *c);
        } else {
            opstack = pushToStack(opstack, 'c');
            strcat(inbuffer, c);
            printf("%s\n", inbuffer);
            if (strcmp(inbuffer, "(") == 0) {
                opstack = pushToStack(opstack, '(');
            } else if (strcmp(inbuffer, ")") == 0) {
                while (opstack->value != '\0' && opstack->value != '(') {
                    char *topOperator = NULL;
                    opstack = popFromStack(opstack, topOperator);
                    // addToOutlist(outlist, )
                }
            }
        }
    }
    return NULL;
}

int main() {
    int buffer[80];
    for (int i = 0; i < 80; ++i) {
        buffer[i] = (int)round(12.0 * calc_polish("x sin", STEP * i));
    }
    print_graph(buffer);
    to_polish("sin");
}