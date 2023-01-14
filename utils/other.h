#ifndef SORTALGORITHM_OTHER_H
#define SORTALGORITHM_OTHER_H

#include <catch2/catch_all.hpp>

#include "consts.h"

#include "../other/ReverseBrute.h"
#include "../other/ReverseMerge.h"

#include "../test/AbstractGenerator.h"
#include "../test/LargeRandomGenerator.h"
#include "../test/MiddleRandomGenerator.h"
#include "../test/SmallRandomGenerator.h"
#include "../test/IncreaseItemGenerator.h"
#include "../test/DecreaseItemGenerator.h"
#include "../test/SameItemGenerator.h"

TEST_CASE("ReverseMatch", "Mix") {
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

TEST_CASE("ReversePerformance", "Mix") {
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

#endif //SORTALGORITHM_OTHER_H
