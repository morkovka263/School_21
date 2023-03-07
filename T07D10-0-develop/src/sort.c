#include <stdio.h>
#include <stdlib.h>

int input(int **a, int *n);
void output(int *a, int n);
void sort(int *a, int n);

int main() {
  int n, *data = NULL;
  if (input(&data, &n) == 0) {
    sort(data, n);
    output(data, n);
  } else {
    printf("n/a");
  }
  free(data);
  return 0;
}

int input(int **a, int *n) {
  int flag = 0;
  char error;
  if (scanf("%d%c", n, &error) != 2 || *n <= 1 ||
      (error != '\n' && error != ' ')) {
    flag = 1;
  }
  if (flag == 0) {
    *a = (int *)calloc(*n, sizeof(int));
    if (*a == NULL) {
      flag = 1;
    }
    if (flag == 0) {
      for (int p = 0; p < *n; ++p) {
        if (scanf("%d%c", &(*a)[p], &error) != 2 ||
            (error != '\n' && error != ' ')) {
          flag = 1;
        }
      }
    }
  }
  return flag;
}
void output(int *a, int n) {
  for (int i = 0; i < n - 1; i++) {
    printf("%d ", a[i]);
  }
  printf("%d", a[n - 1]);
}
void sort(int *a, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[i]) {
        int tpm = a[i];
        a[i] = a[j];
        a[j] = tpm;
      }
    }
  }
}