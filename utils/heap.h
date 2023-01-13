#ifndef SORTALGORITHM_HEAP_H
#define SORTALGORITHM_HEAP_H

#include <algorithm>

static inline int leftSon(int index) {
    return index * 2;
}

static inline int rightSon(int index) {
    return index * 2 + 1;
}

template <typename T> static inline void siftDown(T array, int size, int index) {
    while (true) {
        int next = index;
        if (leftSon(index) <= size && array[next - 1] < array[leftSon(index) - 1])
            next = leftSon(index);
        if (rightSon(index) <= size && array[next - 1] < array[rightSon(index) - 1])
            next = rightSon(index);
        if (next != index) std::swap(array[index - 1], array[next - 1]), index = next;
        else return;
    }
}

#endif //SORTALGORITHM_HEAP_H
