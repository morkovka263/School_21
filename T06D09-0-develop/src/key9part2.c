#include <stdio.h>

#define LEN 100

void Sum(int *mas_b, int *mas_m, int nB, int nM, int *rez);
short Input(int *mas, int *n);
void Output(int *buffer, int lengths);
void Sub(int *mas_b, int *mas_m, int nB, int nM, int *rez);

int main() {
    int mas1[LEN], n1;
    int mas2[LEN], n2;
    int rez[LEN + 1], nR;

    if (Input(mas1, &n1) && Input(mas2, &n2)) {
        nR = (n1 < n2) ? n2 : n1;
        rez[0] = 0;
        rez[1] = 0;
        Sum(mas1, mas2, n1, n2, rez);
        Output(rez, nR);
        printf("\n");
        Sub(mas1, mas2, n1, n2, rez);
        Output(rez, nR);
        return 0;
    }
    printf("n/a");
    return 1;
}

short Input(int *mas, int *n) {
    char buf;
    int index = 0;
    while (1) {
        if (scanf("%d%c", &mas[index], &buf) == 2 && index < 100 && (buf == ' ' || buf == '\n') &&
            mas[index] < 10 && mas[index] > -1) {
            index++;
            if (buf == '\n') {
                *n = index++;
                return 1;
            }
        } else {
            return 0;
        }
    }
}

void Sum(int *mas_b, int *mas_m, int nB, int nM, int *rez) {
    int pnt1 = nB;
    int pnt2 = nM;
    int maxpnt = 0;
    maxpnt = (pnt1 > pnt2) ? pnt1 : pnt2;
    //остаток
    int rem = 0;
    for (int i = maxpnt; i >= 0; i--) {
        pnt1--;
        pnt2--;
        int value1;
        int value2;
        value1 = (pnt1 >= 0) ? (int)mas_b[pnt1] : 0;
        value2 = (pnt2 >= 0) ? (int)mas_m[pnt2] : 0;
        rez[i] = value1 + value2 + rem;
        if (rez[i] > 9) {
            rem = 1;
            rez[i] -= 10;
        } else {
            rem = 0;
        }
    }
}

void Sub(int *mas_b, int *mas_m, int nB, int nM, int *rez) {
    int pnt1 = nB;
    int pnt2 = nM;
    int maxpnt = 0;
    maxpnt = (pnt1 > pnt2) ? pnt1 : pnt2;
    //остаток
    int rem = 0;
    for (int i = maxpnt; i >= 0; i--) {
        pnt1--;
        pnt2--;
        int value1;
        int value2;
        value1 = (pnt1 >= 0) ? (int)mas_b[pnt1] : 0;
        value2 = (pnt2 >= 0) ? (int)mas_m[pnt2] : 0;
        rez[i] = value1 - value2 + rem;
        if (rez[i] < 0) {
            rem = -1;
            rez[i] += 10;
        } else {
            rem = 0;
        }
    }
}
void Output(int *buffer, int length) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (count == 0 && buffer[i] != 0) {
            printf("%d ", buffer[i]);
            count = 1;
        } else {
            if (count == 1) {
                printf("%d ", buffer[i]);
            }
        }
    }
    printf("%d", buffer[length]);
}