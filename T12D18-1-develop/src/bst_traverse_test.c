#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void test_bstree_traversals() {
    t_btree *root = NULL;

    bstree_insert(&root, 10, int_comparator);
    bstree_insert(&root, 5, int_comparator);
    bstree_insert(&root, 15, int_comparator);

    printf("Infix (левое поддерево -> корень -> правое поддерево):\n");
    bstree_apply_infix(root, applyf);
    printf("\n");

    printf("Prefix (корень -> левое поддерево -> правое поддерево):\n");
    bstree_apply_prefix(root, applyf);
    printf("\n");

    printf("Postfix (левое поддерево -> правое поддерево -> корень):\n");
    bstree_apply_postfix(root, applyf);

    free(root->left);
    free(root->right);
    free(root);
}

int main() {
    test_bstree_traversals();
    return 0;
}