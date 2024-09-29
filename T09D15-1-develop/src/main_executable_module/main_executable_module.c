#include <stdio.h>
#include <stdlib.h>

#ifdef USE_MACRO_IO
#include "../data_libs/data_io_macro.h"
#else
#include "../data_libs/data_io.h"
#endif

#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"

int main() {
    double *data;
    int n;

    printf("LOAD DATA...\n");
    if (scanf("%d", &n) == 1) {
        data = (double *)malloc(n * sizeof(double));
    } else {
        printf("n/a");
        return 1;
    }
#ifdef USE_MACRO_IO
    INPUT_ARRAY(lf, data, n);
#else
    input(data, n);
#endif

    printf("RAW DATA:\n\t");
    output(data, n);

    printf("\nNORMALIZED DATA:\n\t");
    normalization(data, n);
    output(data, n);

    printf("\nSORTED NORMALIZED DATA:\n\t");
    sort(data, n);
    output(data, n);

    printf("\nFINAL DECISION:\n\t");
    if (make_decision(data, n))
        printf("YES");
    else
        printf("NO");
    free(data);
}
