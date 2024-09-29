#ifndef DATABASE_H
#define DATABASE_H

#include <stdio.h>

typedef struct {
    int id;
    char name[30];
    int memory_level;
    int number;
    int delete_flag;
} MODULE;

typedef struct {
    int memory_level;
    int cell_count;
    int protection_flag;
} LEVEL;

typedef struct {
    int event_id;
    int module_id;
    int new_status;
    char status_date[11];
    char status_time[9];
} STATUS_EVENT;

MODULE *db_select_module(FILE *db, int id);
int db_delete_module(FILE *db, int id);
int db_insert_module(FILE *db, MODULE *module);
int db_update_module(FILE *db, int id, MODULE *module);

MODULE *get_all_modules(FILE *db, int *count);
MODULE *get_modules_by_memory_level(FILE *db, int memory_level, int *count);

#endif