#include <math.h>
#include <stdio.h>
#define NMAX 10

int input(int *data, int *n);
void output(int *data, int *n);
void squaring(int *data, int *n);

int main() {
    int n, data[NMAX];

    input(data, &n);
    squaring(data, &n);
    output(data, &n);

    return 0;
}

int input(int *data, int *n) {
    if (scanf("%d", n) != 1) {
        printf("n/a");
    } else {
        for (int *p = data; p - data < *n; p++) {
            if (scanf("%d", p) != 1) {
                printf("n/a");
            }
        }
    }
}

void output(int *data, int *n) {
    for (int i = 0; i < *n - 1; i++) {
        printf("%d ", data[i]);
    }
    printf("%d", data[*n - 1]);
}

void squaring(int *data, int *n) {
    for (int i = 0; i < *n; i++) {
        data[i] = pow(data[i], 2);
    }
}
