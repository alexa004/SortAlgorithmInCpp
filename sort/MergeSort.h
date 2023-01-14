#ifndef SORTALGORITHM_MERGESORT_H
#define SORTALGORITHM_MERGESORT_H

template<typename T>
void mergeSort(T array, int n);

template<typename T>
void mergeSort(T array, int left, int right);

template<typename T, typename V>
static void merge(T array, V *buffer, int left, int mid, int right) {
    for (int i = left; i <= right; i++) buffer[i] = array[i];
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right)
        array[k++] = buffer[i] <= buffer[j] ? buffer[i++] : buffer[j++];
    while (i <= mid)
        array[k++] = buffer[i++];
    while (j <= right)
        array[k++] = buffer[j++];
}

template<typename T, typename V>
static void mergeSort(T array, V *buffer, int left, int right) /* NOLINT */ {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(array, buffer, left, mid);
        mergeSort(array, buffer, mid + 1, right);
        merge(array, buffer, left, mid, right);
    }
}

template<typename T>
void mergeSort(T array, int n) {
    typedef typename std::iterator_traits<T>::value_type V;
    V *buffer = new V[n];
    mergeSort(array, buffer, 0, n - 1);
    delete[] buffer;
}

template<typename T>
void mergeSort(T array, int left, int right) {
    mergeSort(array + left, right - left + 1);
}

#endif //SORTALGORITHM_MERGESORT_H
