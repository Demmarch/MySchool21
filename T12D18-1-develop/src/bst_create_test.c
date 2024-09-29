#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void test_bstree_create_node() {
    t_btree *node1 = bstree_create_node(10);
    if (node1) {
        printf("tree - node1 -> item - 10 - %s\n", (node1->item == 10) ? "SUCCES" : "FAIL");
    } else {
        printf("Failed to create node for item = 10\n");
    }

    t_btree *node2 = bstree_create_node(-5);
    if (node2) {
        printf("tree - node2 -> item - -5 - %s\n", (node2->item == -5) ? "SUCCES" : "FAIL");
    } else {
        printf("Failed to create node for item = -5\n");
    }

    free(node1);
    free(node2);
}

int main() {
    test_bstree_create_node();
    return 0;
}