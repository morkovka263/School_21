#include <math.h>
#include <stdio.h>
#define NMAX 10

int input(int* a, int* n);
void output(int* a, int n);
int max(int* a, int n);
int min(int* a, int n);
double mean(int* a, int n);
double variance(int* a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 0) {
        printf("n/a");
    } else {
        output(data, n);

        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
    }
    return 0;
}

int input(int* a, int* n) {
    int flag = 1;
    scanf("%d", n);
    if (*n < 1 || *n > 10) {
        flag = 0;
    }
    for (int p = 0; p < *n; p++) {
        scanf("%d", &a[p]);
    }
    if (getc(stdin) != '\n') {
        flag = 0;
    }
    return flag;
}

void output(int* a, int n) {
    for (int* i = a; i - a < n; i++) {
        printf("%d\n", *i);
    }
}

int max(int* a, int n) {
    int max = *a;
    for (int* i = a; i - a < n; i++) {
        if (max <= *i) {
            max = *i;
        }
    }
    return max;
}
int min(int* a, int n) {
    int min = *a;
    for (int* i = a; i - a < n; i++) {
        if (min >= *i) {
            min = *i;
        }
    }
    return min;
}
double mean(int* a, int n) {
    double sum = 0;

    for (int* i = a; i - a < n; ++i) {
        sum = sum + (*i);
    }
    sum = sum / n;
    return sum;
}
double variance(int* a, int n) {
    double sum = 0;
    for (int* i = a; i - a < n; ++i) {
        sum += pow(*i, 2);
    }
    double x = mean(a, n);
    sum = sum / 4 - pow(x, 2);
    return sum;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d ", max_v);
    printf("%d ", min_v);
    printf("%lf ", mean_v);
    printf("%lf", variance_v);
}