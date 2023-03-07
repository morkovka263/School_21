#include <stdio.h>
#define MAX_SCORE 21
#define FIELD_SIZE_Y 25
#define FIELD_SIZE_X 80
#define START_POS_R_1 -11
#define START_POS_R_2 -11

char ClearScreen();
int WindowResult(int pobeditel);
int WindowRendering(int ball_PosY, int ball_PosX, int racket1_PosY, int racket1_PosX, int racket2_PosY,
                    int racket2_PosX, int scoreFirst, int scoreSecond);

int main() {
    int scoreFirst = 0;
    int scoreSecond = 0;
    int racket1_PosX = 1;
    int racket1_PosY = START_POS_R_1;
    int racket2_PosX = 78;
    int racket2_PosY = START_POS_R_2;
    int ball_PosX = 40;
    int ball_PosY = -11;
    int directionX = 1;
    int directionY = -1;
    while (scoreFirst < MAX_SCORE && scoreSecond < MAX_SCORE) {
        WindowRendering(ball_PosY, ball_PosX, racket1_PosY, racket1_PosX, racket2_PosY, racket2_PosX,
                        scoreFirst, scoreSecond);
        // dvijenie raketki
        char symbol;
        while (scanf("%c", &symbol) != EOF) {
            if (symbol == '\n') {
                continue;
            }
            switch (symbol) {
                case 'a':
                    if (racket1_PosY < -1) racket1_PosY++;
                    break;
                case 'z':
                    if (racket1_PosY > -21) racket1_PosY--;
                    break;
                case 'k':
                    if (racket2_PosY < -1) racket2_PosY++;
                    break;
                case 'm':
                    if (racket2_PosY > -21) racket2_PosY--;
                    break;
                case 'A':
                    if (racket1_PosY < -1) racket1_PosY++;
                    break;
                case 'Z':
                    if (racket1_PosY > -21) racket1_PosY--;
                    break;
                case 'K':
                    if (racket2_PosY < -1) racket2_PosY++;
                    break;
                case 'M':
                    if (racket2_PosY > -21) racket2_PosY--;
                    break;
                case ' ':
                    break;
            }
            break;
        };
        // dvijenie mycha
        if ((ball_PosX >= 2 && ball_PosX <= 78) && (ball_PosY == -1 || ball_PosY == -23)) {
            directionY *= -1;
        }
        if (ball_PosX == 2) {
            if (ball_PosY == racket1_PosY || racket1_PosY - 1 == ball_PosY || racket1_PosY - 2 == ball_PosY) {
                directionX *= -1;
            } else {
                scoreSecond++;
                ball_PosX = 41;
                ball_PosY = -11;
                directionY *= -1;
                directionX *= -1;
                racket1_PosY = START_POS_R_1;
                racket2_PosY = START_POS_R_2;
                continue;
            }
        }
        if (ball_PosX == 77) {
            if (ball_PosY + directionY == racket2_PosY || racket2_PosY - 1 == ball_PosY + directionY ||
                racket2_PosY - 2 == ball_PosY + directionY) {
                directionX *= -1;
            } else {
                scoreFirst++;
                ball_PosX = 40;
                ball_PosY = -11;
                directionY *= -1;
                directionX *= -1;
                racket1_PosY = START_POS_R_1;
                racket2_PosY = START_POS_R_2;
                continue;
            }
        }
        ball_PosX += directionX;
        ball_PosY += directionY;
    }
    if (scoreFirst == MAX_SCORE) {
        WindowResult(1);
        return 0;
    } else if (scoreSecond == MAX_SCORE) {
        WindowResult(2);
        return 0;
    }
    return 0;
}

char ClearScreen() { return printf("\33[0d\33[2J"); }
int WindowResult(int pobeditel) {
    ClearScreen();
    for (int y = 0; y >= -FIELD_SIZE_Y + 1; y--) {
        if (y != -13) {
            for (int x = 0; x <= FIELD_SIZE_X - 1; x++) {
                if ((y == 0 || y == -FIELD_SIZE_Y + 1) || (x == 0 || x == FIELD_SIZE_X - 1))
                    printf("#");
                else
                    printf(" ");
            }
        }
        if (y == -11)
            printf("#                        Поздравляем победителя Игрок %d !!!                    #",
                   pobeditel);
    }
    return 0;
}
int WindowRendering(int ball_PosY, int ball_PosX, int racket1_PosY, int racket1_PosX, int racket2_PosY,
                    int racket2_PosX, int scoreFirst, int scoreSecond) {
    ClearScreen();
    for (int y = 0; y >= -FIELD_SIZE_Y + 1; y--) {
        for (int x = 0; x <= FIELD_SIZE_X - 1; x++) {
            if (y == 0 || y == -FIELD_SIZE_Y + 1) {
                printf("=");
            } else if (x == 0 || x == FIELD_SIZE_X - 1) {
                printf("|");
            } else if (y == ball_PosY && x == ball_PosX) {
                printf("0");
            } else if (y == racket1_PosY && x == racket1_PosX) {
                printf("]");
            } else if (y + 1 == racket1_PosY && x == racket1_PosX) {
                printf("]");
            } else if (y + 2 == racket1_PosY && x == racket1_PosX) {
                printf("]");
            } else if (y == racket2_PosY && x == racket2_PosX) {
                printf("[");
            } else if (y + 1 == racket2_PosY && x == racket2_PosX) {
                printf("[");
            } else if (y + 2 == racket2_PosY && x == racket2_PosX) {
                printf("[");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("      Игрок 1: %d           Нажмите Ctrl-C для выхода.           Игрок 2: %d\n\n", scoreFirst,
           scoreSecond);
    return 0;
}
