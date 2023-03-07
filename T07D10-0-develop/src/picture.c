#include <stdio.h>
#define N 15
#define M 13

void transform(int *buf, int **matr, int n, int m);
void make_picture(int **picture, int n, int m);
void reset_picture(int **picture, int n, int m);
void show_picture(int **picture);

int main() {
  int picture_data[N][M];
  int *picture[N];
  transform(*picture_data, picture, N, M);
  make_picture(picture, N, M);

  show_picture(picture);
  return 0;
}

void show_picture(int **picture) {
  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 13; j++) {
      if (j == 0) {
        printf("%d", picture[i][j]);
      } else {
        printf(" %d", picture[i][j]);
      }
    }
    printf("\n");
  }
}

void make_picture(int **picture, int n, int m) {
  int frame_w[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  int frame_h[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  int tree_trunk[] = {7, 7, 7, 7};
  int tree_foliage[] = {3, 3, 3, 3};
  int sun_data[6][5] = {{0, 6, 6, 6, 6}, {0, 0, 6, 6, 6}, {0, 0, 6, 6, 6},
                        {0, 6, 0, 0, 6}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

  reset_picture(picture, n, m);

  int length_frame_w = 13;
  int length_frame_h = 15;

  for (int i = 1; i < 6; i++) {
    for (int j = 7; j < 12; j++) {
      picture[i][j] = sun_data[i - 1][j - 7];
    }
  }

  for (int i = 2; i < 10; i++) {
    for (int j = 3; j < 5; j++) {
      if (i < 6) {
        picture[i][j] = tree_foliage[j - 3];
      } else if (i > 5) {
        picture[i][j] = tree_trunk[j - 3];
      }
    }
  }

  for (int i = 3; i < 5; i++) {
    for (int j = 2; j < 7; j++) {
      picture[i][j] = tree_foliage[j - 2];
    }
  }

  for (int i = 10; i < 11; i++) {
    for (int j = 2; j < 6; j++) {
      picture[i][j] = tree_trunk[j - 2];
    }
  }
  for (int i = 0; i < length_frame_w; i++) {
    picture[0][i] = frame_w[i];
    picture[7][i] = frame_w[i];
    picture[14][i] = frame_w[i];
  }
  for (int i = 0; i < length_frame_h; i++) {
    picture[i][0] = frame_h[i];
    picture[i][12] = frame_h[i];
    picture[i][6] = frame_h[i];
  }
}
void reset_picture(int **picture, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      picture[i][j] = 0;
    }
  }
}

void transform(int *buf, int **matr, int n, int m) {
  for (int i = 0; i < n; i++) {
    matr[i] = buf + i * m;
  }
}