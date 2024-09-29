#include "graph_lib.h"

#include <stdio.h>

void print_graph(const int values[80]) {
    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < 80; ++j) {
            if (values[j] == i - 12) {
                putchar('*');
            } else {
                putchar('.');
            }
        }
        putchar('\n');
    }
}