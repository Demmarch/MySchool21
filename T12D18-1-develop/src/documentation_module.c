#include "documentation_module.h"

#include <stdarg.h>
#include <stdlib.h>

int* check_available_documentation_module(int (*validate)(char*), int document_count, ...) {
    int* availability_mask = (int*)malloc(document_count * sizeof(int));
    if (!availability_mask) {
        return NULL;
    }

    va_list args;
    va_start(args, document_count);

    for (int i = 0; i < document_count; i++) {
        char* document_name = va_arg(args, char*);
        availability_mask[i] = validate(document_name);
    }

    va_end(args);
    return availability_mask;
}

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}
