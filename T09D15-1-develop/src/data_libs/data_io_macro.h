#ifndef DATA_IO_MACRO_H
#define DATA_IO_MACRO_H

#include <stdio.h>

#define INPUT_ARRAY(TYPE, ARRAY, SIZE) \
    do { \
        for (int i = 0; i < (SIZE); i++) { \
            if (scanf("%" #TYPE, &(ARRAY)[i]) != 1) { \
                printf("n/a"); \
                return; \
            } \
        } \
    } while (0)

#define OUTPUT_ARRAY(TYPE, ARRAY, SIZE) \
    do { \
        for (int i = 0; i < (SIZE) - 1; i++) { \
            printf("%" #TYPE " ", (ARRAY)[i]); \
        } \
        printf("%" #TYPE, (ARRAY)[(SIZE) - 1]); \
    } while (0)

#endif