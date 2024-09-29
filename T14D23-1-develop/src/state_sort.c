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

int compare_records(const void *a, const void *b) {
    Record *rec1 = (Record *)a;
    Record *rec2 = (Record *)b;
    if (rec1->year != rec2->year) return rec1->year - rec2->year;
    if (rec1->month != rec2->month) return rec1->month - rec2->month;
    if (rec1->day != rec2->day) return rec1->day - rec2->day;
    if (rec1->hour != rec2->hour) return rec1->hour - rec2->hour;
    if (rec1->minute != rec2->minute) return rec1->minute - rec2->minute;
    return rec1->second - rec2->second;
}

void print_record(Record *rec) {
    printf("%04d-%02d-%02d %02d:%02d:%02d %d %d\n", rec->year, rec->month, rec->day, rec->hour, rec->minute,
           rec->second, rec->status, rec->code);
}

void print_file(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        printf("n/a");
        return;
    }
    Record rec;
    while (fread(&rec, sizeof(Record), 1, file) == 1) {
        print_record(&rec);
    }
    fclose(file);
}

void add_record(const char *file_path) {
    FILE *file = fopen(file_path, "ab");
    if (!file) {
        printf("n/a");
        return;
    }
    Record new_rec;
    printf("year-month-day-hour-minute-second-status-code:\n");
    if (scanf("%d %d %d %d %d %d %d %d", &new_rec.year, &new_rec.month, &new_rec.day, &new_rec.hour,
              &new_rec.minute, &new_rec.second, &new_rec.status, &new_rec.code) != 8) {
        printf("n/a");
        fclose(file);
        return;
    }
    fwrite(&new_rec, sizeof(Record), 1, file);
    fclose(file);
}

void sort_file(const char *file_path) {
    FILE *file = fopen(file_path, "rb+");
    if (!file) {
        printf("n/a");
        return;
    }
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    int num_records = file_size / sizeof(Record);
    if (num_records == 0) {
        printf("n/a");
        fclose(file);
        return;
    }
    Record *records = malloc(file_size);
    fseek(file, 0, SEEK_SET);
    if (fread(records, sizeof(Record), num_records, file) != num_records) {
        printf("n/a");
        free(records);
        fclose(file);
        return;
    }
    qsort(records, num_records, sizeof(Record), compare_records);
    fseek(file, 0, SEEK_SET);
    fwrite(records, sizeof(Record), num_records, file);
    free(records);
    fclose(file);
    printf("Сортировка завершена.\n");
}

int main() {
    int choice;
    char file_path[255] = " ";
    if (scanf("%d", &choice) != 1) {
        printf("n/a");
        return 1;
    }
    scanf("%s", file_path);
    switch (choice) {
        case 0:
            print_file(file_path);
            break;
        case 1:
            sort_file(file_path);
            print_file(file_path);
            break;
        case 2:
            add_record(file_path);
            sort_file(file_path);
            print_file(file_path);
            break;
        default:
            printf("n/a");
            return 1;
    }
    return 0;
}