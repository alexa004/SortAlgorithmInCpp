#ifndef SORTALGORITHM_FINDKTH_H
#define SORTALGORITHM_FINDKTH_H

#include <algorithm>

template<typename T>
static int solve(T *array, int left, int right, int k) {
    if (left > right) return -1;
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
    if (i >= k) return solve(array, left, i, k);
    if (j <= k) return solve(array, j, right, k);
    return i + 1;
}

template<typename T>
T findKth(T *array, int n, int k) {
    return array[solve(array, 0, n - 1, k - 1)];
}

#endif //SORTALGORITHM_FINDKTH_H
