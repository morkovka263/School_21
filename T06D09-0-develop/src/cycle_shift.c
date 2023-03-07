#include <math.h>
#include <stdio.h>
#define NMAX 10
int input(int* a, int* n, int* ef);
void output(int* a, int n);
void shift(int* a, int n, int ef);
void shift_left(int* a, int ef, int n);
void shift_right(int* a, int ef, int n);

int main() {
    int n, ef, data[NMAX];
    if (input(data, &n, &ef) == 0) {
        printf("n/a");
    } else {
        shift(data, n, ef);
    }
    return 0;
}

int input(int* a, int* n, int* ef) {
    int flag = 1;
    char error;
    if (scanf("%d%c", n, &error) != 2 || (*n > 10 || *n <= 1) || (error != '\n' && error != ' ')) {
        flag = 0;
    }
    if (*n < 1 || *n > 10) {
        flag = 0;
    }

    for (int p = 0; p < *n; p++) {
        scanf("%d", &a[p]);
    }
    if (getc(stdin) != '\n') {
        flag = 0;
    }

    if (scanf("%d%c", ef, &error) != 2 || (error != '\n' && error != ' ')) {
        flag = 0;
    }
    return flag;
}
void output(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", a[i]);
    }
    printf("%d", a[n - 1]);
}

void shift(int* a, int n, int ef) {
    if (ef > 0) {
        shift_left(a, ef, n);
        output(a, n);
    } else if (ef < 0) {
        shift_right(a, ef, n);
        output(a, n);
    }
}

void shift_left(int* a, int ef, int n) {
    for (int i = 0; i < ef; i++) {
        int buff = a[0];
        for (int j = 0; j < n - 1; j++) {
            a[j] = a[j + 1];
        }
        a[n - 1] = buff;
    }
}
void shift_right(int* a, int ef, int n) {
    for (int i = 0; i > ef; i--) {
        int buff = a[n - 1];
        for (int j = n - 1; j > 0; j--) {
            a[j] = a[j - 1];
        }
        a[0] = buff;
    }
}
