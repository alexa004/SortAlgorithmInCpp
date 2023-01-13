#ifndef SORTALGORITHM_HEAPSORT_H
#define SORTALGORITHM_HEAPSORT_H

#include "../utils/heap.h"

template <typename T> void heapSort(T array, int n);

template <typename T> void heapSort(T array, int left, int right);

template <typename T> void heapSort(T array, int n) {
    for (int i = n / 2; i > 0; i--) siftDown(array, n, i);
    while (n >= 1) std::swap(array[0], array[--n]), siftDown(array, n, 1);
}

template <typename T> void heapSort(T array, int left, int right) {
    heapSort(array + left, right - left + 1);
}

#endif //SORTALGORITHM_HEAPSORT_H
