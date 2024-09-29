#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void sort(struct door* doors);
void output(struct door* doors);

int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    sort(doors);
    output(doors);

    return 0;
}

void sort(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        int flag = 1;
        for (int j = 0; j < DOORS_COUNT - (i + 1); j++) {
            if (doors[j].id > doors[j + 1].id) {
                flag = 0;
                int buff = doors[j].id;
                doors[j].id = doors[j + 1].id;
                doors[j + 1].id = buff;
                buff = doors[j].status;
                doors[j].status = doors[j + 1].status;
                doors[j + 1].status = buff;
            }
        }
        if (flag) {
            break;
        }
    }
}

void output(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        printf("%d, %d\n", doors[i].id, doors[i].status);
    }
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}
