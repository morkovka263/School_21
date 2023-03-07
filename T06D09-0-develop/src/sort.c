#include <stdio.h>
#define NMAX 10

int input(int* a);
void output(int* a);
void sort(int* a);

int main() {
    int data[NMAX];
    if (input(data) == 0) {
        printf("n/a");
    } else {
        sort(data);
        output(data);
    }
    return 0;
}

int input(int* a) {
    int flag = 1;
    for (int p = 0; p < NMAX; p++) {
        scanf("%d", &a[p]);
    }
    if (getc(stdin) != '\n') {
        flag = 0;
    }
    return flag;
}
void output(int* a) {
    for (int i = 0; i < NMAX-1; i++) {
            printf("%d ", a[i]);
    }
        printf("%d", a[NMAX-1]);
}
void sort(int* a) {
    for (int i = 0; i < NMAX; i++) {
        for (int j = i + 1; j < NMAX; j++) {
            if (a[j] < a[i]) {
                int tpm = a[i];
                a[i] = a[j];
                a[j] = tpm;
            }
        }
    }
}