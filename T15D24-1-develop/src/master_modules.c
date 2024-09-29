#include "master_modules.h"

#include <stdio.h>
#include <stdlib.h>

#include "database.h"

void display_modules(FILE *db, int count_records);
void select_module(FILE *db);
void insert_module(FILE *db);
void update_module(FILE *db);
void delete_module(FILE *db);

void modules_menu(FILE *db) {
    int record_count = 0;
    printf("Insert the number of records or leave empty to output all of them: ");
    scanf("%d", &record_count);

    display_modules(db, record_count);

    printf("Please choose one operation:\n");
    printf("    1. SELECT\n");
    printf("    2. INSERT\n");
    printf("    3. UPDATE\n");
    printf("    4. DELETE\n");
    printf(">");
    int operation_choice;
    scanf("%d", &operation_choice);

    switch (operation_choice) {
        case 1:
            select_module(db);
            break;
        case 2:
            insert_module(db);
            break;
        case 3:
            update_module(db);
            break;
        case 4:
            delete_module(db);
            break;
        default:
            printf("Function not implemented yet.\n");
            break;
    }
}

void display_modules(FILE *db, int count_records) {
    int count;
    MODULE *modules = get_all_modules(db, &count);
    if (!modules) {
        printf("Failed to retrieve modules.\n");
        return;
    }

    if (count_records > count) {
        printf("n/a");
    }

    for (int i = 0; i < count_records; i++) {
        MODULE module = modules[i];
        printf("%d %s %d %d %d\n", module.id, module.name, module.memory_level, module.number, module.delete_flag);
    }

    free(modules);
}

void select_module(FILE *db) {
    printf("Enter module ID to select: ");
    int id;
    scanf("%d", &id);

    MODULE *module = db_select_module(db, id);
    if (module) {
        printf("Module found: %d %s %d %d %d\n", module->id, module->name, module->memory_level, module->number, module->delete_flag);
        free(module);
    } else {
        printf("Module not found.\n");
    }
}

void insert_module(FILE *db) {
    MODULE module;
    printf("Enter module details (id, name, memory_level, number, delete_flag): ");
    
    scanf("%d", &module.id);
    scanf("%s", module.name);
    scanf("%d", &module.memory_level);
    scanf("%d", &module.number);
    scanf("%d", &module.delete_flag);

    if (db_insert_module(db, &module) == 0) {
        printf("Module inserted successfully.\n");
    } else {
        printf("Failed to insert module.\n");
    }
}

void update_module(FILE *db) {
    printf("Enter module ID to update: ");
    int id;
    scanf("%d", &id);

    MODULE module;
    printf("Enter new module details (name, memory_level, number, delete_flag): ");
    scanf("%s", module.name);
    scanf("%d", &module.memory_level);
    scanf("%d", &module.number);
    scanf("%d", &module.delete_flag);

    if (db_update_module(db, id, &module) == 0) {
        printf("Module updated successfully.\n");
    } else {
        printf("Failed to update module.\n");
    }
}

void delete_module(FILE *db) {
    printf("Enter module ID to delete: ");
    int id;
    scanf("%d", &id);

    if (db_delete_module(db, id) == 0) {
        printf("Module deleted successfully.\n");
    } else {
        printf("Failed to delete module.\n");
    }
}