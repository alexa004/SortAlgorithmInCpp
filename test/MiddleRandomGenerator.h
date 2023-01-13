#ifndef SORTALGORITHM_MIDDLERANDOMGENERATOR_H
#define SORTALGORITHM_MIDDLERANDOMGENERATOR_H

#include "AbstractGenerator.h"

class MiddleRandomGenerator : public AbstractGenerator {
public:
    MiddleRandomGenerator(int size, bool type, bool store) : AbstractGenerator(size, type, store) {}

    const char* name() override {
        return "middle random generator";
    }

    int* generateArray() override {
        if (array != nullptr)
            for (int i = 0; i < size; i++) {
                int value = generator();
                answer[i] = array[i] = value / 0xffff;
            }
        return array;
    }

    std::vector<int>::iterator generateVector() override {
        if (vector != nullptr)
            for (int i = 0; i < size; i++) {
                int value = generator();
                answer[i] = (*vector)[i] = value / 0xffff;
            }
        return vector -> begin();
    }
};

#endif //SORTALGORITHM_MIDDLERANDOMGENERATOR_H
