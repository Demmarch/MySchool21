#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void print_tree(t_btree *root) {
    if (root != NULL) {
        print_tree(root->left);
        printf("%d ", root->item);
        print_tree(root->right);
    }
}

void test_bstree_insert() {
    t_btree *root = NULL;

    printf("Insertions test 1:\n");
    bstree_insert(&root, 10, int_comparator);
    printf("Insert 10 (Root)\n");
    bstree_insert(&root, 5, int_comparator);
    printf("Insert 5 (Left 10)\n");
    bstree_insert(&root, 15, int_comparator);
    printf("Insert 15 (Right 10)\n");
    print_tree(root);
    printf("\n");

    printf("Insertions test 2:\n");
    t_btree *root2 = NULL;
    bstree_insert(&root2, 20, int_comparator);
    printf("Inserted 20 (Root)\n");
    bstree_insert(&root2, 10, int_comparator);
    printf("Inserted 10 (Left 20)\n");
    bstree_insert(&root2, 30, int_comparator);
    printf("Inserted 30 (Right 20)\n");
    print_tree(root2);
    printf("\n");

    free(root->left);
    free(root->right);
    free(root);

    free(root2->left);
    free(root2->right);
    free(root2);
}

int main() {
    test_bstree_insert();
    return 0;
}