#include "opstack.h"

#include <stdlib.h>

struct opstack *initStack(char value) {
    struct opstack *s = malloc(sizeof(struct opstack));
    s->value = value;
    return s;
}

struct opstack *pushToStack(struct opstack *opstack, char value) {
    struct opstack *s = initStack(value);
    s->prev = opstack;
    return s;
}

struct opstack *popFromStack(struct opstack *opstack, char *value) {
    *value = opstack->value;
    struct opstack *s = opstack->prev;
    free(opstack);
    return s;
}
