#ifndef SORTALGORITHM_SMALLRANDOMGENERATOR_H
#define SORTALGORITHM_SMALLRANDOMGENERATOR_H

#include "AbstractGenerator.h"

class SmallRandomGenerator : public AbstractGenerator {
public:
    SmallRandomGenerator(int size, bool type, bool store) : AbstractGenerator(size, type, store) {}

    const char *name() override {
        return "small random generator";
    }

    int *generateArray() override {
        if (array != nullptr)
            for (int i = 0; i < size; i++) {
                int value = generator();
                answer[i] = array[i] = value >> 24;
            }
        return array;
    }

    std::vector<int>::iterator generateVector() override {
        if (vector != nullptr)
            for (int i = 0; i < size; i++) {
                int value = generator();
                answer[i] = vector->at(i) = value >> 24;
            }
        return vector->begin();
    }
};

#endif //SORTALGORITHM_SMALLRANDOMGENERATOR_H
