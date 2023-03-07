#include "../data_libs/data_io.h"
#include "../data_libs/data_sort.h"
#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"
int main() {
    double *data = NULL;
    int n;

    printf("LOAD DATA...\n");
    if (input(&data, &n) == 0) {
        printf("RAW DATA:\n\t");
        output(data, n);

        printf("\nNORMALIZED DATA:\n\t");
        normalization(data, n);
        output(data, n);

        printf("\nSORTED NORMALIZED DATA:\n\t");
        sort(data, n);
        output(data, n);

        printf("\nFINAL DECISION:\n\t");
        if (make_decision(data, n)) {
            printf("YES");
        } else {
            printf("NO");
        }
    } else {
        printf("ERROR");
    }

    free(data);
    return 0;
}
