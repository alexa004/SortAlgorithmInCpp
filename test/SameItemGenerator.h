#ifndef SORTALGORITHM_SAMEITEMGENERATOR_H
#define SORTALGORITHM_SAMEITEMGENERATOR_H

#include "AbstractGenerator.h"

class SameItemGenerator : public AbstractGenerator {
private:
    int base;

public:
    SameItemGenerator(int size, bool type, bool store) : AbstractGenerator(size, type, store) {
        this->base = (int) generator() / 2;
    }

    const char *name() override {
        return "same item generator";
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
                answer[i] = vector->at(i) = base;
        return vector->begin();
    }
};

#endif //SORTALGORITHM_SAMEITEMGENERATOR_H
