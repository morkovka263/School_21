#include <stdio.h>

void maxmin(int x, int y, int z, int *max, int *min);

/* Find a max & min probabilities */
int main() {
    int x, y, z;
    if (scanf("%d", &x) != 1) {
        printf("n/a");
        return 0;
    } else {
        if (scanf("%d", &y) != 1) {
            printf("n/a");
            return 0;
        } else {
            if (scanf("%d", &z) != 1) {
                printf("n/a");
                return 0;
            } else {
            }
        }
    }

    int max, min;

    maxmin(x, y, z, &max, &min);

    printf("%d %d", max, min);

    return 0;
}

/* This function should be kept !!! (Your AI) */
/* But errors & bugs should be fixed         */
void maxmin(int x, int y, int z, int *max, int *min) {
    *max = *min = x;

    if (y > *max) *max = y;
    if (y < *min) *min = y;

    if (z > *max) *max = z;
    if (z < *min) *min = z;
}