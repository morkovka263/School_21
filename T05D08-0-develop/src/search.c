#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int* a, int* n);
void output(int* a, int n);
int max(int* a, int n);
double mean(int* a, int n);
int max_mean(int* a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 0) {
        printf("n/a");
    } else {
        output(data, n);
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
    printf("%d", max_mean(a, n));
}

int max(int* a, int n) {
    int max = *a;
    for (int* i = a; i - a < n; i++) {
        if (max <= *i) {
            if ((*i % 2) == 0) {
                max = *i;
            }
        }
    }
    return max;
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
int max_mean(int* a, int n) {
    int max_mean_v = 0;
    if (max(a, n) >= mean(a, n)) {
        int max_mean_v = max(a, n);
        if (max_mean_v <= (mean(a, n) + (3 * sqrt(variance(a, n))))) {
            return max_mean_v;
        }

        return max_mean_v;
    }
}
