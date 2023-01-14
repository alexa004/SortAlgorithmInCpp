#ifndef SORTALGORITHM_FINDMAJORITY_H
#define SORTALGORITHM_FINDMAJORITY_H

template<typename T>
T findMajority(T array, int n) {
    int count = 0, index;
    for (int i = 0; i < n; i++) {
        if (count == 0) index = i, count++;
        else if (array[index] != array[i]) count--;
        else count++;
    }
    return array[index];
}

#endif //SORTALGORITHM_FINDMAJORITY_H
