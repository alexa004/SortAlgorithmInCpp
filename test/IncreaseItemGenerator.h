#ifndef SORTALGORITHM_INCREASEITEMGENERATOR_H
#define SORTALGORITHM_INCREASEITEMGENERATOR_H

#include "AbstractGenerator.h"

class IncreaseItemGenerator : public AbstractGenerator {
private:
    int base;

public:
    IncreaseItemGenerator(int size, bool type, bool store) : AbstractGenerator(size, type, store) {
        this->base = (int) generator() / 2;
    }

    const char *name() override {
        return "increase item generator";
    }

    int *generateArray() override {
        if (array != nullptr)
            for (int i = 0; i < size; i++)
                answer[i] = array[i] = base + i;
        return array;
    }

    std::vector<int>::iterator generateVector() override {
        if (vector != nullptr)
            for (int i = 0; i < size; i++)
                answer[i] = vector->at(i) = base + i;
        return vector->begin();
    }
};

#endif //SORTALGORITHM_INCREASEITEMGENERATOR_H
