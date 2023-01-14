#ifndef SORTALGORITHM_ABSTRACTGENERATOR_H
#define SORTALGORITHM_ABSTRACTGENERATOR_H

#include <vector>
#include <random>
#include <chrono>
#include <cstdlib>
#include <algorithm>

static int generator() {
    static std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
    return (int) generator();
}

class AbstractGenerator {
protected:
    int *array;
    int *answer;
    std::vector<int> *vector;
    int left, right, size, index;

    void getAnswer() {
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
        array = !store ? new int[size] : nullptr;
        vector = store ? new std::vector<int>(size) : nullptr;
        answer = new int[size];
        left = type ? (generator() % size + size) % size : -1;
        right = type ? (generator() % size + size) % size : -1;
        index = (generator() % size + size) % size;
        if (left > right) std::swap(left, right);
    }

    virtual ~AbstractGenerator() {
        delete[] answer;
        delete[] array;
        if (vector != nullptr) {
            vector->clear();
            delete vector;
        }
    }

    [[nodiscard]] int getSize() const {
        return size;
    }

    [[nodiscard]] int getLeft() const {
        return left;
    }

    [[nodiscard]] int getRight() const {
        return right;
    }

    [[nodiscard]] int getIndex() const {
        return index + 1;
    }

    bool checkAnswer() {
        getAnswer();
        for (int i = 0; array != nullptr && i < size; i++) {
            if (answer[i] != array[i]) return false;
        }
        for (int i = 0; vector != nullptr && i < size; i++) {
            if (answer[i] != vector->at(i)) return false;
        }
        return true;
    }

    bool checkAnswer(int value) {
        getAnswer();
        return value == answer[index];
    }

    void display() {
        printf("left : %d, right : %d\n", left, right);
        printf("out : ");
        if (array != nullptr) for (int i = 0; i < size; i++) printf("%d ", array[i]);
        if (vector != nullptr) for (int i = 0; i < size; i++) printf("%d ", (*vector)[i]);
        putchar('\n');
        printf("std : ");
        for (int i = 0; i < size; i++) printf("%d ", answer[i]);
        putchar('\n');
    }

    virtual const char *name() = 0;

    virtual int *generateArray() = 0;

    virtual std::vector<int>::iterator generateVector() = 0;
};

#endif //SORTALGORITHM_ABSTRACTGENERATOR_H
