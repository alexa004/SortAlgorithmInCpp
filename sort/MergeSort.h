#ifndef SORTALGORITHM_MERGESORT_H
#define SORTALGORITHM_MERGESORT_H

#include <vector>

void mergeSort(int* array, int n);

void mergeSort(int* array, int left, int right);

void mergeSort(std::vector<int>::iterator array, int n);

void mergeSort(std::vector<int>::iterator array, int left, int right);

static inline void merge(int* array, std::vector<int>::iterator buffer, int left, int mid, int right) {
    for (int i = left; i <= right; i++) buffer[i] = array[i];
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) array[k++] = buffer[i] <= buffer[j] ? buffer[i++] : buffer[j++];
    while (i <= mid) array[k++] = buffer[i++];
    while (j <= right) array[k++] = buffer[j++];
}

void mergeSort(int* array, std::vector<int>::iterator buffer, int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(array, buffer, left, mid);
    mergeSort(array, buffer, mid + 1, right);
    merge(array, buffer, left, mid, right);
}

void mergeSort(int* array, int n) {
    std::vector<int> buffer(n);
    mergeSort(array, buffer.begin(), 0, n - 1);
}

void mergeSort(int* array, int left, int right) {
    mergeSort(array + left, right - left + 1);
}

static inline void merge(std::vector<int>::iterator array
        , std::vector<int>::iterator buffer, int left, int mid, int right) {
    for (int i = left; i <= right; i++) buffer[i] = array[i];
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) array[k++] = buffer[i] <= buffer[j] ? buffer[i++] : buffer[j++];
    while (i <= mid) array[k++] = buffer[i++];
    while (j <= right) array[k++] = buffer[j++];
}

static inline void mergeSort(std::vector<int>::iterator array
        , std::vector<int>::iterator buffer, int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(array, buffer, left, mid);
    mergeSort(array, buffer, mid + 1, right);
    merge(array, buffer, left, mid, right);
}

void mergeSort(std::vector<int>::iterator array, int n) {
    std::vector<int> buffer(n);
    mergeSort(array, buffer.begin(), 0, n - 1);
}

void mergeSort(std::vector<int>::iterator array, int left, int right) {
    mergeSort(array + left, right - left + 1);
}

#endif //SORTALGORITHM_MERGESORT_H
