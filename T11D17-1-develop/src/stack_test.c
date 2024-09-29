#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

char* test_push(Node **plist);
char* test_pop(Node **plist);

int main() {
    Node *stack = init();
    if (stack == NULL) {
        printf("Failed to initialize stack\n");
        return 1;
    }

    printf("%s\n", test_push(&stack));
    printf("%s", test_pop(&stack));

    destroy(stack);
    return 0;
}

char* test_push(Node **plist) {
    int flag = 1;

    push(*plist, 10);
    push(*plist, 20);
    push(*plist, 30);

    if ((*plist)->next->data != 30) flag = 0;
    if ((*plist)->next->next->data != 20) flag = 0;
    if ((*plist)->next->next->next->data != 10) flag = 0;

    return (flag == 1) ? "SUCCESS" : "FAIL";
}

char* test_pop(Node **plist) {
    int flag = 1;
    int value;

    pop(*plist, &value);
    if (value != 30) flag = 0;

    pop(*plist, &value);
    if (value != 20) flag = 0;

    pop(*plist, &value);
    if (value != 10) flag = 0;

    return (flag == 1) ? "SUCCESS" : "FAIL";
}