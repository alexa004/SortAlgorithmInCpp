#ifndef SORTALGORITHM_REVERSEBRUTE_H
#define SORTALGORITHM_REVERSEBRUTE_H

template<typename T>
long long reverseBrute(T array, int n) {
    long long reverse = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (array[i] > array[j])
                reverse++;
    return reverse;
}

#endif //SORTALGORITHM_REVERSEBRUTE_H
