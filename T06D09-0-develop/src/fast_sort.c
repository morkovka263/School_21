#include <stdio.h>

#define SIZE 10

short Input(int *buff);
short Output(int *buff);
void Swap(int *buff, int left, int right);
void QuickSort(int *buff, int left, int right);
void CopyMas(int *buff, int *buff2);
void SiftDown(int *numbers, int root, int bottom);
void HeapSort(int *numbers, int array_size);

int main(void) {
    int buff[SIZE], buff2[SIZE];
    if (Input(buff)) {
        CopyMas(buff, buff2);
        QuickSort(buff, 0, SIZE - 1);
        Output(buff);
        printf("\n");
        HeapSort(buff2, SIZE);
        Output(buff2);
        return 0;
    }
    printf("n/a");
    return 1;
}

void CopyMas(int *buff, int *buff2) {
    for (int i = 0; i < SIZE; i++) {
        buff2[i] = buff[i];
    }
}

short Input(int *buff) {
    int n = SIZE;
    char buf;
    for (int *p = buff; p - buff < n; p++) {
        if (scanf("%d%c", p, &buf) != 2 || (buf != '\n' && buf != ' ' && buf != EOF)) {
            return 0;
        }
    }
    return 1;
}

short Output(int *buff) {
    int n = SIZE;
    for (int *p = buff; p - buff < n - 1; p++) {
        printf("%d ", *p);
    }
    printf("%d", buff[n - 1]);
    return 1;
}

void Swap(int *buff, int left, int right) {
    int value;
    value = buff[left];
    buff[left] = buff[right];
    buff[right] = value;
}

void QuickSort(int *buff, int left, int right) {
    int pivot = buff[left];
    int l_check = left;
    int r_check = right;

    while (l_check < r_check) {
        //идем с права-конец на лево-начало
        while (buff[r_check] >= pivot && l_check < r_check) {
            r_check--;
        }
        if (r_check != l_check) {
            buff[l_check] = buff[r_check];
            l_check++;
        }
        //идём с лева-начало на право-конец
        while (buff[l_check] <= pivot && l_check < r_check) {
            l_check++;
        }
        if (r_check != l_check) {
            buff[r_check] = buff[l_check];
            r_check--;
        }
    }
    // l_check = r_check
    buff[l_check] = pivot;
    if (left < l_check) {
        QuickSort(buff, left, l_check - 1);
    }
    if (right > l_check) {
        QuickSort(buff, l_check + 1, right);
    }
}

// Функция "просеивания" через кучу - формирование кучи
void SiftDown(int *numbers, int root, int bottom) {
    int maxChild;  // индекс максимального потомка
    int done = 0;  // флаг того, что куча сформирована
    // Пока не дошли до последнего ряда
    while ((root * 2 <= bottom) && (!done)) {
        if (root * 2 == bottom)   // если мы в последнем ряду,
            maxChild = root * 2;  // запоминаем левый потомок
        // иначе запоминаем больший потомок из двух
        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        // если элемент вершины меньше максимального потомка
        if (numbers[root] < numbers[maxChild]) {
            int temp = numbers[root];  // меняем их местами
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        } else         // иначе
            done = 1;  // пирамида сформирована
    }
}

// Функция сортировки на куче
void HeapSort(int *numbers, int array_size) {
    // Формируем нижний ряд пирамиды
    for (int i = (array_size / 2); i >= 0; i--) SiftDown(numbers, i, array_size - 1);
    // Просеиваем через пирамиду остальные элементы
    for (int i = array_size - 1; i >= 1; i--) {
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        SiftDown(numbers, 0, i - 1);
    }
}