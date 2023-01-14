#ifndef SORTALGORITHM_DECREASEITEMGENERATOR_H
#define SORTALGORITHM_DECREASEITEMGENERATOR_H

#include "AbstractGenerator.h"

class DecreaseItemGenerator : public AbstractGenerator {
private:
    int base;

public:
    DecreaseItemGenerator(int size, bool type, bool store) : AbstractGenerator(size, type, store) {
        this->base = (int) generator() / 2;
    }

    const char *name() override {
        return "decrease item generator";
    }

    int *generateArray() override {
        if (array != nullptr)
            for (int i = 0; i < size; i++)
                answer[i] = array[i] = base - i;
        return array;
    }

    std::vector<int>::iterator generateVector() override {
        if (vector != nullptr)
            for (int i = 0; i < size; i++)
                answer[i] = vector->at(i) = base - i;
        return vector->begin();
    }
};

#endif //SORTALGORITHM_DECREASEITEMGENERATOR_H
