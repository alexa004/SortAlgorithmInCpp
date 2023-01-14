#ifndef SORTALGORITHM_CONSTS_H
#define SORTALGORITHM_CONSTS_H

#include <vector>
#include "../test/AbstractGenerator.h"

std::pair<bool, bool> ALL_ARRAY = {AbstractGenerator::ALL, AbstractGenerator::ARRAY};

std::pair<bool, bool> ALL_VECTOR = {AbstractGenerator::ALL, AbstractGenerator::VECTOR};

std::pair<bool, bool> RANGE_ARRAY = {AbstractGenerator::RANGE, AbstractGenerator::ARRAY};

std::pair<bool, bool> RANGE_VECTOR = {AbstractGenerator::RANGE, AbstractGenerator::VECTOR};

std::vector<int> SQUARE_SIZE = {
        AbstractGenerator::ONE, AbstractGenerator::TWO,
        AbstractGenerator::FOUR, AbstractGenerator::SQUARE
};

std::vector<int> LINEAR_SIZE = {
        AbstractGenerator::ONE, AbstractGenerator::TWO,
        AbstractGenerator::FOUR, AbstractGenerator::LINEAR
};

std::vector<int> LINE_LOG_SIZE = {
        AbstractGenerator::ONE, AbstractGenerator::TWO,
        AbstractGenerator::FOUR, AbstractGenerator::LINE_LOG
};

#endif //SORTALGORITHM_CONSTS_H
