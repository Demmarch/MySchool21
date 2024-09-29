#include "outlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct outlist *initOutlist(int value) {
    struct outlist *outlist = malloc(sizeof(struct outlist));
    *outlist = (struct outlist){.value = value, .next = NULL};
    return outlist;
}

struct outlist *addToOutlist(struct outlist *root, int value) {
    if (!root) {
        root = initOutlist(value);
        return root;
    } else {
        struct outlist *temp = initOutlist(value);
        getLastOutElem(root)->next = temp;
        return temp;
    }
}

struct outlist *getLastOutElem(struct outlist *root) {
    struct outlist *a = root;
    if (a) {
        while (a->next) {
            a = a->next;
        }
    }
    return a;
}

char *outlistToStr(struct outlist *root, char *destination) {
    struct outlist *a = root;
    if (a) {
        while (a->next) {
            char t[10];
            sprintf(t, "%d", a->value);
            strcat(destination, t);
            a = a->next;
        }
    }
    return destination;
}
