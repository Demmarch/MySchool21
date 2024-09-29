#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

struct Node* init() {
    struct Node* s = (struct Node*)malloc(sizeof(struct Node));
    if (s == NULL) {
        return NULL; 
    }

    s->next = NULL;
    return s;
}

void push(struct Node* s, int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        return;
    }
    new_node->data = value;
    new_node->next = s->next;
    s->next = new_node;
}

void pop(struct Node* s, int* value) {
    if (s->next == NULL) {
        return;
    }
    struct Node* temp = s->next;
    *value = temp->data;
    s->next = temp->next;
    free(temp);
}

void destroy(struct Node* s) {
    while (s->next != NULL) {
        struct Node* temp = s->next;
        s->next = temp->next;
        free(temp);
    }
    free(s);
}