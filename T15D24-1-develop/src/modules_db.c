#include <stdio.h>
#include <stdlib.h>

#include "database.h"
#include "master_modules.h"

void menu(FILE *db);

int main() {
    FILE *db = fopen("../materials/master_modules.db", "rb+");
    if (!db) {
        perror("Failed to open database");
        return 1;
    }

    menu(db);

    fclose(db);
    return 0;
}

void menu(FILE *db) {
    int table_choice;
    printf("Please choose a table:\n");
    printf("    1. Modules\n");
    printf("    2. Levels\n");
    printf("    3. Status events\n");
    printf(">");
    scanf("%d", &table_choice);

    switch (table_choice) {
        case 1:
            modules_menu(db);
            break;
        default:
            printf("Invalid table choice.\n");
    }
}