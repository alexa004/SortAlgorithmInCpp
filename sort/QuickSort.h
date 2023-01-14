#ifndef SORTALGORITHM_QUICKSORT_H
#define SORTALGORITHM_QUICKSORT_H

#include <algorithm>

template<typename T>
void quickSort(T array, int n);

template<typename T>
void quickSort(T array, int left, int right);

template<typename T>
void quickSort(T array, int n) {
    quickSort(array, 0, n - 1);
}

template<typename T>
void quickSort(T array, int left, int right) {
    if (left > right) return;
    int mid = (left + right) / 2;
    if (array[left] > array[right])
        std::swap(array[left], array[right]);
    if (array[right] < array[mid])
        std::swap(array[right], array[mid]);
    if (array[left] < array[mid])
        std::swap(array[left], array[mid]);
    int i = left, j = right, tmp = array[left];
    while (i != j) {
        while (array[j] >= tmp && i < j) j--;
        while (array[i] <= tmp && i < j) i++;
        if (i < j) std::swap(array[i], array[j]);
    }
    array[left] = array[i], array[i] = tmp, mid = j = i;
    while (i >= left && array[i] == array[mid]) i--;
    while (j <= right && array[j] == array[mid]) j++;
    quickSort(array, left, i), quickSort(array, j, right);
}

#endif //SORTALGORITHM_QUICKSORT_H
