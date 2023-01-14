#ifndef SORTALGORITHM_MAINTAINKTH_H
#define SORTALGORITHM_MAINTAINKTH_H

#include "../utils/heap.h"

template<typename T>
T maintainKth(T *array, int n, int k) {
    for (int i = k / 2; i > 0; i--) siftDown(array, k, i);
    for (int i = k + 1; i <= n; i++)
        if (array[i - 1] < array[0])
            array[0] = array[i - 1], siftDown(array, k, 1);
    return array[0];
}

#endif //SORTALGORITHM_MAINTAINKTH_H
