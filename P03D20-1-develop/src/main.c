#include <stdio.h>

#include "graph.h"

int main() {
    char expression[256];
    printf("Enter the expression: ");
    scanf("%255s", expression);
    plot_graph(expression);
    return 0;
}