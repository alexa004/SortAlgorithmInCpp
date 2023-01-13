#ifndef SORTALGORITHM_COUNTREVERSE_H
#define SORTALGORITHM_COUNTREVERSE_H

#include <vector>

static inline void count(int* array, std::vector<int>::iterator buffer
        , int left, int mid, int right, long long& reverse) {
    for (int i = left; i <= right; i++) buffer[i] = array[i];
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (buffer[i] <= buffer[j]) array[k++] = buffer[i++];
        else array[k++] = buffer[j++], reverse += (long long)(mid - i + 1);
    }
    while (i <= mid) array[k++] = buffer[i++];
    while (j <= right) array[k++] = buffer[j++];
}

void countReverse(int* array, std::vector<int>::iterator buffer
        , int left, int right, long long& reverse) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    countReverse(array, buffer, left, mid, reverse);
    countReverse(array, buffer, mid + 1, right, reverse);
    count(array, buffer, left, mid, right, reverse);
}

long long countReverse(int* array, int n) {
    std::vector<int> buffer(n);
    long long reverse = 0;
    countReverse(array, buffer.begin(), 0, n - 1, reverse);
    return reverse;
}

static inline void count(std::vector<int>::iterator array
        , std::vector<int>::iterator buffer, int left, int mid, int right, long long& reverse) {
    for (int i = left; i <= right; i++) buffer[i] = array[i];
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (buffer[i] <= buffer[j]) array[k++] = buffer[i++];
        else array[k++] = buffer[j++], reverse += (long long)(mid - i + 1);
    }
    while (i <= mid) array[k++] = buffer[i++];
    while (j <= right) array[k++] = buffer[j++];
}

static inline void countReverse(std::vector<int>::iterator array
        , std::vector<int>::iterator buffer, int left, int right, long long& reverse) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    countReverse(array, buffer, left, mid, reverse);
    countReverse(array, buffer, mid + 1, right, reverse);
    count(array, buffer, left, mid, right, reverse);
}

long long countReverse(std::vector<int>::iterator array, int n) {
    std::vector<int> buffer(n);
    long long reverse = 0;
    countReverse(array, buffer.begin(), 0, n - 1, reverse);
    return reverse;
}

#endif //SORTALGORITHM_COUNTREVERSE_H
