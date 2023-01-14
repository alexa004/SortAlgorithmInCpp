#ifndef SORTALGORITHM_OTHER_H
#define SORTALGORITHM_OTHER_H

#include <vector>
#include <algorithm>
#include <catch2/catch_all.hpp>

#include "consts.h"

#include "../other/EulerSeive.h"
#include "../other/FindMajority.h"
#include "../other/ReverseBrute.h"
#include "../other/ReverseMerge.h"

#include "../test/AbstractGenerator.h"
#include "../test/LargeRandomGenerator.h"
#include "../test/MiddleRandomGenerator.h"
#include "../test/SmallRandomGenerator.h"
#include "../test/IncreaseItemGenerator.h"
#include "../test/DecreaseItemGenerator.h"
#include "../test/SameItemGenerator.h"

TEST_CASE("ReverseMatch") {
    typedef std::pair<std::pair<bool, bool>, std::function<bool(AbstractGenerator *)>> TesterItem;
    std::vector<TesterItem> testList = {
            {ALL_ARRAY,  [](AbstractGenerator *generator) {
                auto ptr = generator->generateArray();
                long long lhs = reverseBrute(ptr, generator->getSize());
                long long rhs = reverseBrute(ptr, generator->getSize());
                return lhs == rhs;
            }},
            {ALL_VECTOR, [](AbstractGenerator *generator) {
                auto ptr = generator->generateVector();
                long long lhs = reverseBrute(ptr, generator->getSize());
                long long rhs = reverseBrute(ptr, generator->getSize());
                return lhs == rhs;
            }}
    };
    for (int size: SQUARE_SIZE) {
        for (TesterItem &test: testList) {
            for (int count = 0; count < 3; count++) {
                std::vector<AbstractGenerator *> generators = {
                        new LargeRandomGenerator(size, test.first.first, test.first.second),
                        new MiddleRandomGenerator(size, test.first.first, test.first.second),
                        new SmallRandomGenerator(size, test.first.first, test.first.second),
                        new IncreaseItemGenerator(size, test.first.first, test.first.second),
                        new DecreaseItemGenerator(size, test.first.first, test.first.second),
                        new SameItemGenerator(size, test.first.first, test.first.second)
                };
                for (AbstractGenerator *generator: generators) {
                    bool result = test.second(generator);
                    if (size < 0xf && !result) generator->display();
                    CHECK(result);
                    delete generator;
                }
            }
        }
    }
}

TEST_CASE("ReversePerformance") {
    typedef std::pair<std::pair<bool, bool>, std::function<void(AbstractGenerator *)>> TesterItem;
    std::vector<TesterItem> testList = {
            {ALL_ARRAY,  [](AbstractGenerator *generator) {
                reverseMerge(generator->generateArray(), generator->getSize());
            }},
            {ALL_VECTOR, [](AbstractGenerator *generator) {
                reverseMerge(generator->generateVector(), generator->getSize());
            }}
    };
    for (int size: LINE_LOG_SIZE) {
        for (TesterItem &test: testList) {
            std::vector<AbstractGenerator *> generators = {
                    new LargeRandomGenerator(size, test.first.first, test.first.second),
                    new MiddleRandomGenerator(size, test.first.first, test.first.second),
                    new SmallRandomGenerator(size, test.first.first, test.first.second),
                    new IncreaseItemGenerator(size, test.first.first, test.first.second),
                    new DecreaseItemGenerator(size, test.first.first, test.first.second),
                    new SameItemGenerator(size, test.first.first, test.first.second)
            };
            for (AbstractGenerator *generator: generators) {
                test.second(generator);
                CHECK(true);
                delete generator;
            }
        }
    }
}

TEST_CASE("Majority") {
    for (int size: LINE_LOG_SIZE) {
        for (int count = 0; count < 4; count++) {
            int bound = (size >> 1) + 1, distance = size - bound + 1;
            int number = (generator() % distance + distance) % distance + bound;
            int select = generator() & (int) (0xffffffff >> (count << 3));
            int *array = new int[size];
            std::vector<int> vector(size);
            std::mt19937 method(std::chrono::system_clock::now().time_since_epoch().count());
            for (int i = 0; i < size; i++) {
                vector[i] = i < number ? select : generator() & (int) (0xffffffff >> (count << 3));
                array[i] = i < number ? select : generator() & (int) (0xffffffff >> (count << 3));
            }
            std::shuffle(array, array + size, method);
            CHECK(findMajority(array, size) == select);
            std::shuffle(vector.begin(), vector.end(), method);
            CHECK(findMajority(vector.begin(), size) == select);
            delete[] array;
        }
    }
}

TEST_CASE("EulerSeiveMatch") {
    for (int size: LINE_LOG_SIZE) {
        for (int count = 0; count < 4; count++) {
            std::vector<bool> answer(size, false);
            for (int i = 2; i < size; i++) {
                bool flag = true;
                for (int j = 2; flag && j * j <= i; j++)
                    flag &= i % j != 0;
                answer[i] = flag;
            }
            std::vector<bool> result(size);
            eulerSeive(result);
            CHECK(answer == result);
        }
    }
}

TEST_CASE("EulerSeivePerformance") {
    for (int size: LINEAR_SIZE) {
        std::vector<bool> result(size);
        eulerSeive(result);
        CHECK(true);
    }
}

#endif //SORTALGORITHM_OTHER_H
