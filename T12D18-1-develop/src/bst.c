#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

t_btree *bstree_create_node(int item) {
    t_btree *new_node = (t_btree *)malloc(sizeof(t_btree));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->item = item;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

int int_comparator(int a, int b) { return (a - b); }

void bstree_insert(t_btree **root, int item, int (*cmpf)(int, int)) {
    if (*root == NULL) {
        *root = bstree_create_node(item);
        return;
    }

    if (cmpf(item, (*root)->item) < 0) {
        bstree_insert(&((*root)->left), item, cmpf);
    } else if (cmpf(item, (*root)->item) > 0) {
        bstree_insert(&((*root)->right), item, cmpf);
    }
}

void bstree_apply_infix(t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        bstree_apply_infix(root->left, applyf);
        applyf(root->item);
        bstree_apply_infix(root->right, applyf);
    }
}

void bstree_apply_prefix(t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        applyf(root->item);
        bstree_apply_prefix(root->left, applyf);
        bstree_apply_prefix(root->right, applyf);
    }
}

void bstree_apply_postfix(t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        bstree_apply_postfix(root->left, applyf);
        bstree_apply_postfix(root->right, applyf);
        applyf(root->item);
    }
}

void applyf(int item) { printf("%d ", item); }