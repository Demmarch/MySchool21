#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
} Record;

int main(int argc, char **argv) {
    char file_path[255] = " ";
    char search_date[255] = " ";
    scanf("%s", file_path);
    scanf("%s", search_date);

    int search_day, search_month, search_year;
    if (sscanf(search_date, "%2d.%2d.%4d", &search_day, &search_month, &search_year) != 3) {
        printf("n/a");
        return 1;
    }

    FILE *file = fopen(file_path, "rb");
    if (file == NULL) {
        printf("n/a");
        return 1;
    }

    Record record;
    int found = 0;

    while (fread(&record, sizeof(Record), 1, file) == 1) {
        if (record.day == search_day && record.month == search_month && record.year == search_year) {
            printf("%d\n", record.code);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("n/a");
    }

    fclose(file);
    return 0;
}