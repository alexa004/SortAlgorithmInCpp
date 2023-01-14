#ifndef SORTALGORITHM_LARGERANDOMGENERATOR_H
#define SORTALGORITHM_LARGERANDOMGENERATOR_H

#include "AbstractGenerator.h"

class LargeRandomGenerator : public AbstractGenerator {
public:
    LargeRandomGenerator(int size, bool type, bool store) : AbstractGenerator(size, type, store) {}

    const char *name() override {
        return "large random generator";
    }

    int *generateArray() override {
        if (array != nullptr)
            for (int i = 0; i < size; i++)
                answer[i] = array[i] = generator();
        return array;
    }

    std::vector<int>::iterator generateVector() override {
        if (vector != nullptr)
            for (int i = 0; i < size; i++)
                answer[i] = (*vector)[i] = generator();
        return vector->begin();
    }
};

#endif //SORTALGORITHM_LARGERANDOMGENERATOR_H
