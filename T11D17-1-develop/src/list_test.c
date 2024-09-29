#include "list.h"

#include <stdio.h>
#include <stdlib.h>

char *test_add_door() {
    int flag = 1;
    struct door d1 = {1, 0};
    struct door d2 = {2, 1};

    struct node *list = init(&d1);
    if (list == NULL || list->data.id != 1) flag = 0;

    struct node *new_door = add_door(list, &d2);
    if (find_door(2, list)->data.id != 2) flag = 0;
    remove_door(new_door, list);
    destroy(list);

    return (flag == 1) ? "SUCCESS" : "FAIL";
}

char *test_remove_door() {
    int flag = 1;
    struct door d1 = {1, 0};
    struct door d2 = {2, 1};
    struct door d3 = {3, 0};

    struct node *list = init(&d1);
    struct node *new_door_1 = add_door(list, &d2);
    struct node *new_door_2 = add_door(list, &d3);

    list = remove_door(new_door_1, list);
    if (find_door(3, list)->data.id != 3) {
        flag = 0;
    }
    list = remove_door(new_door_2, list);
    if (list->next != NULL) {
        flag = 0;
    }
    list = remove_door(list, list);
    if (list != NULL) {
        flag = 0;
    }

    return (flag == 1) ? "SUCCESS" : "FAIL";
}

int main() {
    printf("%s\n", test_add_door());
    printf("%s", test_remove_door());
    return 0;
}