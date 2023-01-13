#ifndef SORTALGORITHM_RADIXSORT_H
#define SORTALGORITHM_RADIXSORT_H

#include <vector>

void radixSort(int* array, int n) {
    unsigned modify, plus = 0x80000000;
    std::vector<int> buffer(n);
    std::vector<int> count(65536);
    for (int k = 0; k < 2; k++) {
        count.assign(count.size(), 0);
        for (int i = 0; i < n; i++) {
            modify = plus + (unsigned)array[i];
            count[(modify >> ((unsigned)k << (unsigned)4)) & (unsigned)65535]++;
        }
        for (int i = 1; i < 65536; i++) count[i] += count[i - 1];
        for (int i = n - 1; i >= 0; i--) {
            modify = plus + (unsigned)array[i];
            buffer[--count[(modify >> ((unsigned)k << (unsigned)4)) & (unsigned)65535]] = array[i];
        }
        for (int i = 0; i < n; i++) array[i] = buffer[i];
    }
}

void radixSort(int* array, int left, int right) {
    radixSort(array + left, right - left + 1);
}

void radixSort(std::vector<int>::iterator array, int n) {
    unsigned modify, plus = 0x80000000;
    std::vector<int> buffer(n);
    std::vector<int> count(65536);
    for (int k = 0; k < 2; k++) {
        count.assign(count.size(), 0);
        for (int i = 0; i < n; i++) {
            modify = plus + (unsigned)array[i];
            count[(modify >> ((unsigned)k << (unsigned)4)) & (unsigned)65535]++;
        }
        for (int i = 1; i < 65536; i++) count[i] += count[i - 1];
        for (int i = n - 1; i >= 0; i--) {
            modify = plus + (unsigned)array[i];
            buffer[--count[(modify >> ((unsigned)k << (unsigned)4)) & (unsigned)65535]] = array[i];
        }
        for (int i = 0; i < n; i++) array[i] = buffer[i];
    }
}

void radixSort(std::vector<int>::iterator array, int left, int right) {
    radixSort(array + left, right - left + 1);
}

#endif //SORTALGORITHM_RADIXSORT_H
