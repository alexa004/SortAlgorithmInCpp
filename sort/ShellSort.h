#ifndef SORTALGORITHM_SHELLSORT_H
#define SORTALGORITHM_SHELLSORT_H

#include <algorithm>

template<typename T>
void shellSort(T array, int n);

template<typename T>
void shellSort(T array, int left, int right);

template<typename T>
void shellSort(T array, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i++)
            for (int j = i - gap; j >= 0 && array[j] > array[j + gap]; j -= gap)
                std::swap(array[j], array[j + gap]);
}

template<typename T>
void shellSort(T array, int left, int right) {
    shellSort(array + left, right - left + 1);
}

#endif //SORTALGORITHM_SHELLSORT_H
