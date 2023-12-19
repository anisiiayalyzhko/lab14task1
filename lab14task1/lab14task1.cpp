// lab14task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <stdlib.h>

void findMinMaxAndDistance(int* arr, int size, int* min, int* max, int* distance) {
    // Ініціалізуємо min та max початковими значеннями
    *min = *arr;
    *max = *arr;

    // Знаходимо min та max в масиві
    for (int i = 1; i < size; i++) {
        if (*(arr + i) < *min) {
            *min = *(arr + i);
        }
        if (*(arr + i) > *max) {
            *max = *(arr + i);
        }
    }

    // Знаходимо відстань між min та max
    int minIndex = -1, maxIndex = -1;
    for (int i = 0; i < size; i++) {
        if (*(arr + i) == *min) {
            minIndex = i;
        }
        if (*(arr + i) == *max) {
            maxIndex = i;
        }
    }

    // Обчислюємо відстань
    *distance = abs(maxIndex - minIndex);
}

int main() {
    int size;

    // Ввід розміру масиву
    printf("Enter the massive: ");
    scanf_s("%d", &size);

    // Виділення пам'яті для масиву
    int* arr = (int*)malloc(size * sizeof(int));

    // Ввід елементів масиву
    printf("Enter the elements of the massive:\n");
    for (int i = 0; i < size; i++) {
        scanf_s("%d", arr + i);
    }

    int min, max, distance;

    // Знаходження min, max та відстані
    findMinMaxAndDistance(arr, size, &min, &max, &distance);

    // Виведення результатів
    printf("min: %d\n", min);
    printf("max: %d\n", max);
    printf("distance: %d\n", distance);

    // Звільнення виділеної пам'яті
    free(arr);

    return 0;
}



