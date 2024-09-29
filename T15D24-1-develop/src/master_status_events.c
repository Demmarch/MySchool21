#include <stdio.h>
#include <stdlib.h>

void menuddd() {
    int table_choice;
    printf("Please choose a table:\n");
    printf("    1. Modules\n");
    printf("    2. Levels\n");
    printf("    3. Status events\n");
    printf(">");
    scanf("%d", &table_choice);

    switch (table_choice) {
        case 1:
            break;
        default:
            printf("Invalid table choice.\n");
    }
}