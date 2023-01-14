#ifndef SORTALGORITHM_COUNTREVERSE_H
#define SORTALGORITHM_COUNTREVERSE_H

template<typename T>
static void count(T *array, T *buffer, int left, int mid, int right, long long &reverse) {
    for (int i = left; i <= right; i++) buffer[i] = array[i];
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (buffer[i] <= buffer[j]) array[k++] = buffer[i++];
        else array[k++] = buffer[j++], reverse += (long long) (mid - i + 1);
    }
    while (i <= mid)
        array[k++] = buffer[i++];
    while (j <= right)
        array[k++] = buffer[j++];
}

template<typename T>
static void countReverse(T *array, T *buffer, int left, int right, long long &reverse) /* NOLINT */ {
    if (left < right) {
        int mid = (left + right) / 2;
        countReverse(array, buffer, left, mid, reverse);
        countReverse(array, buffer, mid + 1, right, reverse);
        count(array, buffer, left, mid, right, reverse);
    }
}

template<typename T>
long long countReverse(T *array, int n) {
    T *buffer = new T[n];
    long long reverse = 0;
    countReverse(array, buffer, 0, n - 1, reverse);
    return reverse;
}

#endif //SORTALGORITHM_COUNTREVERSE_H
