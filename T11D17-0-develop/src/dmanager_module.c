#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void sort_doors(struct door* doors);
void doors_closed(struct door* doors);
void output(struct door* doors);

int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    sort_doors(doors);
    doors_closed(doors);
    output(doors);
    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void output(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        if (i < DOORS_COUNT - 1) {
            printf("%d, ", doors[i].id);
            printf("%d\n", doors[i].status);
        } else {
            printf("%d, ", doors[i].id);
            printf("%d", doors[i].status);
        }
    }
}

void sort_doors(struct door* doors) {
    for (int i = DOORS_COUNT - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            // сравниваем элементы массива структур по сумме баллов студента
            if ((doors[j].id) > (doors[j + 1].id)) {
                int tmp = doors[j].id;
                doors[j].id = doors[j + 1].id;
                doors[j + 1].id = tmp;
            }
        }
    }
}
void doors_closed(struct door* doors) {
    for (int i = DOORS_COUNT; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (doors[j].status == 1) {
                doors[j].status = 0;
            }
        }
    }
}