#ifndef SORTALGORITHM_RANK_H
#define SORTALGORITHM_RANK_H

#include <vector>
#include <functional>
#include <catch2/catch_all.hpp>

#include "consts.h"

#include "../other/FindKth.h"
#include "../other/MaintainKth.h"

#include "../test/AbstractGenerator.h"
#include "../test/LargeRandomGenerator.h"
#include "../test/MiddleRandomGenerator.h"
#include "../test/SmallRandomGenerator.h"
#include "../test/IncreaseItemGenerator.h"
#include "../test/DecreaseItemGenerator.h"
#include "../test/SameItemGenerator.h"

#define RankTester(method) {\
        {ALL_ARRAY,  [](AbstractGenerator *generator) {\
            return maintainKth(generator->generateArray(), generator->getSize(), generator->getIndex());\
        }},\
        {ALL_VECTOR, [](AbstractGenerator *generator) {\
            return maintainKth(generator->generateVector(), generator->getSize(), generator->getIndex());\
        }}\
}

typedef std::pair<std::pair<bool, bool>, std::function<int(AbstractGenerator *)>> RankTesterItem;

static void testAndVerify(std::vector<RankTesterItem> &testList, std::vector<int> &sizeList) {
    for (int size: sizeList) {
        for (RankTesterItem &test: testList) {
            std::vector<AbstractGenerator *> generators = {
                    new LargeRandomGenerator(size, test.first.first, test.first.second),
                    new MiddleRandomGenerator(size, test.first.first, test.first.second),
                    new SmallRandomGenerator(size, test.first.first, test.first.second),
                    new IncreaseItemGenerator(size, test.first.first, test.first.second),
                    new DecreaseItemGenerator(size, test.first.first, test.first.second),
                    new SameItemGenerator(size, test.first.first, test.first.second)
            };
            for (AbstractGenerator *generator: generators) {
                bool result = generator->checkAnswer(test.second(generator));
                if (size < 0xf && !result) generator->display();
                CHECK(result);
                delete generator;
            }
        }
    }
}

TEST_CASE("FindKth", "Mix") {
    std::vector<RankTesterItem> testList = RankTester(findKth);
    testAndVerify(testList, LINEAR_SIZE);
}

TEST_CASE("MaintainKth", "Mix") {
    std::vector<RankTesterItem> testList = RankTester(maintainKth);
    testAndVerify(testList, LINE_LOG_SIZE);
}

#endif //SORTALGORITHM_RANK_H
