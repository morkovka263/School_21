#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "decision.h"

int main() {
    double *data = NULL;
    int n;
    if (input(&data, &n) == 0) {
        if (make_decision(data, n))
            printf("YES");
        else
            printf("NO");
    } else {
        printf("Error");
    }

    free(data);
    return 0;
}
