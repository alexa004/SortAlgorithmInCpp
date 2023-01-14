#ifndef SORTALGORITHM_SORT_H
#define SORTALGORITHM_SORT_H

#include <vector>
#include <functional>
#include <catch2/catch_all.hpp>

#include "consts.h"

#include "../sort/RadixSort.h"
#include "../sort/MergeSort.h"
#include "../sort/HeapSort.h"
#include "../sort/QuickSort.h"
#include "../sort/ShellSort.h"
#include "../sort/InsertSort.h"
#include "../sort/SelectSort.h"
#include "../sort/BubbleSort.h"

#include "../test/AbstractGenerator.h"
#include "../test/LargeRandomGenerator.h"
#include "../test/MiddleRandomGenerator.h"
#include "../test/SmallRandomGenerator.h"
#include "../test/IncreaseItemGenerator.h"
#include "../test/DecreaseItemGenerator.h"
#include "../test/SameItemGenerator.h"

#define SortTester(method) {\
        {ALL_ARRAY,    [](AbstractGenerator *generator) {\
            method(generator->generateArray(), generator->getSize());\
        }},\
        {ALL_VECTOR,   [](AbstractGenerator *generator) {\
            method(generator->generateVector(), generator->getSize());\
        }},\
        {RANGE_ARRAY,  [](AbstractGenerator *generator) {\
            method(generator->generateArray(), generator->getLeft(), generator->getRight());\
        }},\
        {RANGE_VECTOR, [](AbstractGenerator *generator) {\
            method(generator->generateVector(), generator->getLeft(), generator->getRight());\
        }}\
}

typedef std::pair<std::pair<bool, bool>, std::function<void(AbstractGenerator *)>> SortTesterItem;

static void testAndVerify(std::vector<SortTesterItem> &testList, std::vector<int> &sizeList) {
    for (int size: sizeList) {
        for (SortTesterItem &test: testList) {
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
                bool result = generator->checkAnswer();
                if (size < 0xf && !result) generator->display();
                REQUIRE(result);
                delete generator;
            }
        }
    }
}

TEST_CASE("RadixSort", "Mix") {
    std::vector<SortTesterItem> testList = SortTester(radixSort);
    testAndVerify(testList, LINEAR_SIZE);
}

TEST_CASE("MergeSort", "Mix") {
    std::vector<SortTesterItem> testList = SortTester(mergeSort);
    testAndVerify(testList, LINE_LOG_SIZE);
}

TEST_CASE("HeapSort", "Mix") {
    std::vector<SortTesterItem> testList = SortTester(heapSort);
    testAndVerify(testList, LINE_LOG_SIZE);
}

TEST_CASE("QuickSort", "Mix") {
    std::vector<SortTesterItem> testList = SortTester(quickSort);
    testAndVerify(testList, LINE_LOG_SIZE);
}

TEST_CASE("ShellSort", "Mix") {
    std::vector<SortTesterItem> testList = SortTester(shellSort);
    testAndVerify(testList, LINE_LOG_SIZE);
}

TEST_CASE("InsertSort", "Mix") {
    std::vector<SortTesterItem> testList = SortTester(insertSort);
    testAndVerify(testList, SQUARE_SIZE);
}

TEST_CASE("SelectSort", "Mix") {
    std::vector<SortTesterItem> testList = SortTester(selectSort);
    testAndVerify(testList, SQUARE_SIZE);
}

TEST_CASE("BubbleSort", "Mix") {
    std::vector<SortTesterItem> testList = SortTester(bubbleSort);
    testAndVerify(testList, SQUARE_SIZE);
}

#endif //SORTALGORITHM_SORT_H
