#ifndef SORTALGORITHM_DECREASEINTGENERATOR_H
#define SORTALGORITHM_DECREASEINTGENERATOR_H

#include "AbstractGenerator.h"

class DecreaseIntGenerator : public AbstractGenerator {
private:
    int base;

public:
    DecreaseIntGenerator(int size, bool type, bool store) : AbstractGenerator(size, type, store) {
        int value = (int) generator() / 2;
        this->base = value;
    }

    const char *name() override {
        return "decrease int generator";
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
                answer[i] = (*vector)[i] = base - i;
        return vector->begin();
    }
};

#endif //SORTALGORITHM_DECREASEINTGENERATOR_H
