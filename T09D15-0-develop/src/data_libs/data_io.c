#include "data_io.h"

#include <stdio.h>
#include <stdlib.h>
int input(double **data, int *n) {
    int flag = 0;
    char error;
    if (scanf("%d%c", n, &error) == 2 || (error != '\n' && error != ' ')) {
        *data = (double *)calloc(*n, sizeof(double));
        for (int i = 0; i < *n; ++i) {
            if (scanf("%lf%c", &(*data)[i], &error) != 2 || (error != '\n' && error != ' ')) {
                flag = 1;
            }
        }
    } else {
        flag = 1;
    }
    return flag;
}

void output(double *data, int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%.2lf ", data[i]);
    }
    printf("%.2lf", data[n - 1]);
}