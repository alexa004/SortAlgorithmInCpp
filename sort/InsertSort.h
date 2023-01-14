#ifndef SORTALGORITHM_INSERTSORT_H
#define SORTALGORITHM_INSERTSORT_H

#include <algorithm>

template<typename T>
void insertSort(T array, int n);

template<typename T>
void insertSort(T array, int left, int right);

template<typename T>
void insertSort(T array, int n) {
    for (int i = 1; i < n; i++)
        for (int j = i - 1; j >= 0 && array[j] > array[j + 1]; j--)
            std::swap(array[j], array[j + 1]);
}

template<typename T>
void insertSort(T array, int left, int right) {
    insertSort(array + left, right - left + 1);
}

#endif //SORTALGORITHM_INSERTSORT_H
