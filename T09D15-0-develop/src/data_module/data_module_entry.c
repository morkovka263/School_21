#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "data_process.h"

int main() {
    double *data = NULL;
    int n;

    // Don`t forget to allocate memory !

    if (input(&data, &n) == 0) {
        if (normalization(data, n) == 0) {
            output(data, n);
        } else {
            printf("ERROR");
        }
    } else {
        printf("ERROR");
    }
    free(data);
    return 0;
}
