#ifndef SORTALGORITHM_SELECTSORT_H
#define SORTALGORITHM_SELECTSORT_H

#include <algorithm>

template <typename T> void selectSort(T array, int n);

template <typename T> void selectSort(T array, int left, int right);

template <typename T> void selectSort(T array, int n) {
    for (int i = n; i > 0; i--) {
        int cur = array[0], pos = 0;
        for (int j = 1; j < i; j++)
            if (array[j] > cur) cur = array[j], pos = j;
        if (pos == i - 1) continue;
        std::swap(array[pos], array[i - 1]);
    }
}

template <typename T> void selectSort(T array, int left, int right) {
    selectSort(array + left, right - left + 1);
}

#endif //SORTALGORITHM_SELECTSORT_H
