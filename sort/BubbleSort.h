#ifndef SORTALGORITHM_BUBBLESORT_H
#define SORTALGORITHM_BUBBLESORT_H

#include <algorithm>

template<typename T>
void bubbleSort(T *array, int n);

template<typename T>
void bubbleSort(T *array, int left, int right);

template<typename T>
void bubbleSort(T *array, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (array[j] > array[j + 1])
                std::swap(array[j], array[j + 1]);
}

template<typename T>
void bubbleSort(T *array, int left, int right) {
    bubbleSort(array + left, right - left + 1);
}

#endif //SORTALGORITHM_BUBBLESORT_H
