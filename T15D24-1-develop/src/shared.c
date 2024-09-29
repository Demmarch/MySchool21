#include <stdlib.h>
#include <string.h>

#include "database.h"

MODULE *db_select_module(FILE *db, int id) {
    MODULE *module = malloc(sizeof(MODULE));
    if (!module) {
        return NULL;
    }

    rewind(db);
    while (fread(module, sizeof(MODULE), 1, db)) {
        if (module->id == id) {
            return module;
        }
    }

    free(module);
    return NULL;
}

int db_delete_module(FILE *db, int id) {
    FILE *temp = fopen("temp.db", "wb");
    if (!temp) {
        return 1;
    }

    MODULE module;
    int deleted = 0;
    rewind(db);
    while (fread(&module, sizeof(MODULE), 1, db)) {
        if (module.id != id) {
            fwrite(&module, sizeof(MODULE), 1, temp);
        } else {
            deleted = 1;
        }
    }

    fclose(db);
    fclose(temp);

    remove("modules.db");
    if (rename("temp.db", "modules.db") != 0) {
        return 1;
    }

    return deleted ? 0 : 1;
}

int db_insert_module(FILE *db, MODULE *module) {
    fseek(db, 0, SEEK_END);
    if (fwrite(module, sizeof(MODULE), 1, db) != 1) {
        return 1;
    }
    return 0;
}

int db_update_module(FILE *db, int id, MODULE *module) {
    FILE *temp = fopen("temp.db", "wb");
    if (!temp) {
        return 1;
    }

    MODULE current;
    int updated = 0;

    rewind(db);
    while (fread(&current, sizeof(MODULE), 1, db)) {
        if (current.id == id) {
            fwrite(module, sizeof(MODULE), 1, temp);
            updated = 1;
        } else {
            fwrite(&current, sizeof(MODULE), 1, temp);
        }
    }

    fclose(db);
    fclose(temp);

    remove("modules.db");
    rename("temp.db", "modules.db");

    return updated ? 0 : 1;
}

MODULE *get_all_modules(FILE *db, int *count) {
    MODULE *modules = NULL;
    int module_count = 0;
    MODULE temp;

    rewind(db);
    while (fread(&temp, sizeof(MODULE), 1, db)) {
        MODULE *new_modules = realloc(modules, sizeof(MODULE) * (module_count + 1));
        if (!new_modules) {
            free(modules);
            return NULL;
        }
        modules = new_modules;
        modules[module_count++] = temp;
    }

    *count = module_count;
    return modules;
}