#ifndef SORTALGORITHM_ABSTRACTGENERATOR_H
#define SORTALGORITHM_ABSTRACTGENERATOR_H

#include <vector>
#include <random>
#include <chrono>
#include <cstdlib>
#include <algorithm>

class AbstractGenerator {
protected:
    int *array;
    int *answer;
    std::vector<int> *vector;
    int left, right, size, index;

    inline void getAnswer() {
        int *leftPtr = answer + (left == -1 ? 0 : left);
        int *rightPtr = answer + (right == -1 ? size : right + 1);
        std::sort(leftPtr, rightPtr);
    }

public:
    constexpr static int ONE = 1;
    constexpr static int TWO = 2;
    constexpr static int FOUR = 4;
    constexpr static int SQUARE = 5000;
    constexpr static int LINEAR = 1000000;
    constexpr static int LINE_LOG = 500000;

    constexpr static bool ALL = false;
    constexpr static bool RANGE = true;

    constexpr static bool ARRAY = false;
    constexpr static bool VECTOR = true;

    AbstractGenerator(int size, bool type, bool store) : size(size) {
        array = !store ? (int *) malloc(sizeof(int) * size) : nullptr;
        vector = store ? new std::vector<int>(size) : nullptr;
        answer = (int *) malloc(sizeof(int) * size);
        std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
        left = type ? ((int) generator() % size + size) % size : -1;
        right = type ? ((int) generator() % size + size) % size : -1;
        index = ((int) generator() % size + size) % size;
        if (left > right) std::swap(left, right);
    }

    virtual ~AbstractGenerator() {
        free(answer);
        if (array != nullptr) free(array);
        if (vector != nullptr) {
            vector->clear();
            delete vector;
        }
    }

    inline int getSize() const {
        return size;
    }

    inline int getLeft() const {
        return left;
    }

    inline int getRight() const {
        return right;
    }

    inline int getIndex() const {
        return index + 1;
    }

    inline bool checkAnswer() {
        getAnswer();
        for (int i = 0; i < size; i++) {
            if (array != nullptr && answer[i] != array[i]) return false;
            if (vector != nullptr && answer[i] != (*vector)[i]) return false;
        }
        return true;
    }

    inline bool checkAnswer(int value) {
        getAnswer();
        return value == answer[index];
    }

    inline void display() {
        printf("left : %d, right : %d\n", left, right);
        printf("out : ");
        if (array != nullptr) for (int i = 0; i < size; i++) printf("%d ", array[i]);
        if (vector != nullptr) for (int i = 0; i < size; i++) printf("%d ", (*vector)[i]);
        putchar('\n');
        printf("std : ");
        for (int i = 0; i < size; i++) printf("%d ", answer[i]);
        putchar('\n');
    }

    static inline int generator() {
        static std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
        return generator();
    }

    virtual const char *name() = 0;

    virtual int *generateArray() = 0;

    virtual std::vector<int>::iterator generateVector() = 0;
};

#endif //SORTALGORITHM_ABSTRACTGENERATOR_H
