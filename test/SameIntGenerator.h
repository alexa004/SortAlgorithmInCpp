#ifndef SORTALGORITHM_SAMEINTGENERATOR_H
#define SORTALGORITHM_SAMEINTGENERATOR_H

#include "AbstractGenerator.h"

class SameIntGenerator : public AbstractGenerator {
private:
    int base;

public:
    SameIntGenerator(int size, bool type, bool store) : AbstractGenerator(size, type, store) {
        int value = (int) generator() / 2;
        this->base = value;
    }

    const char *name() override {
        return "same int generator";
    }

    int *generateArray() override {
        if (array != nullptr)
            for (int i = 0; i < size; i++)
                answer[i] = array[i] = base;
        return array;
    }

    std::vector<int>::iterator generateVector() override {
        if (vector != nullptr)
            for (int i = 0; i < size; i++)
                answer[i] = (*vector)[i] = base;
        return vector->begin();
    }
};

#endif //SORTALGORITHM_SAMEINTGENERATOR_H
