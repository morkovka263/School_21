#include <stdio.h>
#include <stdlib.h>

#define NMAX 100
#define YMAX 100

int input(int *swint, int *legth_n, int *legth_y);
int inputBuffStat(int buff[NMAX][YMAX], int legth_n, int legth_y);
int inputBuffDyn(int **Buff, int legth_n, int length_y);
void outputStat(int buff[NMAX][YMAX], int legth_n, int length_y);
void outputDyn(int **Buff, int legth_n, int legth_y);

int main() {
  int legth_n, legth_y, sw, buff[NMAX][YMAX];
  int **Buff = NULL;
  input(&sw, &legth_n, &legth_y);
  switch (sw) {
  case 1:
    inputBuffStat(buff, legth_n, legth_y);
    outputStat(buff, legth_n, legth_y);
    break;
  case 2:
  case 3:
  case 4:
    inputBuffDyn((int **)Buff, legth_n, legth_y);
    outputDyn((int **)Buff, legth_n, legth_y);
    break;
  default:
    printf("n/a");
    break;
  }
  free(Buff);
  return 0;
}

int input(int *sw, int *legth_n, int *legth_y) {
  printf("input switch:\n");
  scanf("%d", sw);
  printf("input n:\n");
  scanf("%d", legth_n);
  printf("input y:\n");
  scanf("%d", legth_y);
  return *sw;
}
int inputBuffStat(int buff[NMAX][YMAX], int legth_n, int legth_y) {
  for (int y = 0; y < legth_y; y++) {
    for (int x = 0; x < legth_n; x++) {
      scanf("%d", &buff[y][x]);
    }
  }
  return 0;
}

int inputBuffDyn(int **Buff, int legth_n, int length_y) {
  Buff = (int **)malloc(legth_n * sizeof(int *));
  for (int i = 0; i < legth_n; i++) {
    Buff[i] = (int *)malloc(length_y * sizeof(int));

    for (int i = 0; i < length_y; i++) {
      for (int j = 0; j < legth_n; j++) {
        Buff[i][j];
      }
    }
    for (int i = 0; i < legth_n; i++)
      free(Buff[i]);
    free(Buff);
  }
  return 0;
}

void outputStat(int buff[NMAX][YMAX], int legth_n, int legth_y) {
  for (int i = 0; i < legth_y; ++i) {
    printf("\n");
    for (int j = 0; j < legth_n; ++j) {
      printf("%d ", buff[i][j]);
    }
  }
}
void outputDyn(int **Buff, int legth_n, int legth_y) {
  for (int i = 0; i < legth_y; i++) {
    for (int j = 0; j < legth_n; j++) {
      printf("%d ", Buff[i][j]);
    }
  }
  for (int i = 0; i < legth_y; i++) {
    free(Buff[i]);
  }
  free(Buff);
}