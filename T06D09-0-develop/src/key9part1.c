#include <stdio.h>
#define NMAX 10
int input(int* a, int* n);
void output(int* a, int n);
int sum_numbers(int* a, int n);
int find_numbers(int* a, int n, int number, int* numbers);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 0) {
        printf("n/a");
    } else {
        int number, numbers[NMAX];
        number = sum_numbers(data, n);
        int numbers_len = find_numbers(data, n, number, numbers);
        printf("%d\n", number);
        output(numbers, numbers_len);
    }
    return 0;
}

int input(int* a, int* n) {
    int flag = 1;
    char error;
    if (scanf("%d%c", n, &error) != 2 || (*n <= 1 || *n > 10) || (error != '\n' && error != ' ')) {
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

    return flag;
}
void output(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", a[i]);
    }
    printf("%d", a[n - 1]);
}

int sum_numbers(int* a, int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            sum = sum + a[i];
        }
    }
    return sum;
}

int find_numbers(int* a, int n, int number, int* numbers) {
    int z = 0;
    for (int* i = a; i - a < n; i++) {
        if (*i != 0 && number % (*i) == 0) {
            numbers[z] = (*i);
            z++;
        }
    }
    return z;
}
