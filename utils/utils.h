#ifndef SORTALGORITHM_UTILS_H
#define SORTALGORITHM_UTILS_H

#include "../sort/RadixSort.h"
#include "../sort/MergeSort.h"
#include "../sort/HeapSort.h"
#include "../sort/QuickSort.h"
#include "../sort/ShellSort.h"
#include "../sort/InsertSort.h"
#include "../sort/SelectSort.h"
#include "../sort/BubbleSort.h"

#include "../other/FindKth.h"
#include "../other/MaintainKth.h"

#include "../test/AbstractGenerator.h"
#include "../test/LargeRandomGenerator.h"
#include "../test/MiddleRandomGenerator.h"
#include "../test/SmallRandomGenerator.h"
#include "../test/IncreaseItemGenerator.h"
#include "../test/DecreaseItemGenerator.h"
#include "../test/SameItemGenerator.h"

#include "src/catch2/catch_test_macros.hpp"

void finalizeSort(AbstractGenerator *generator, const std::string &name, int size, bool &flag) {
    bool result = generator->checkAnswer();
    printf("%s, size %d : %s\n", name.c_str(), size, result ? "true" : "false");
    if (size < 10 && !result) generator->display();
    flag &= result;
    delete generator;
}

void finalizeKth(int value, AbstractGenerator *generator, const std::string &name, int size, bool &flag) {
    bool result = generator->checkAnswer(value);
    printf("%s, size %d : %s\n", name.c_str(), size, result ? "true" : "false");
    if (size < 10 && !result) generator->display();
    flag &= result;
    delete generator;
}

#define testSort(function, generatorType, sortMethod, size, flag) do\
    for (int i : (size)) {\
        AbstractGenerator* generator;\
        generator = new generatorType(i, AbstractGenerator::ALL, AbstractGenerator::ARRAY);\
        function(generator -> generateArray(), generator -> getSize());\
        finalizeSort(generator, (sortMethod) + " / array / all / " + generator -> name(), i, flag);\
        generator = new generatorType(i, AbstractGenerator::ALL, AbstractGenerator::VECTOR);\
        function(generator -> generateVector(), generator -> getSize());\
        finalizeSort(generator, (sortMethod) + " / vector / all / " + generator -> name(), i, flag);\
        generator = new generatorType(i, AbstractGenerator::RANGE, AbstractGenerator::ARRAY);\
        function(generator -> generateArray(), generator -> getLeft(), generator -> getRight());\
        finalizeSort(generator, (sortMethod) + " / array / range / " + generator -> name(), i, flag);\
        generator = new generatorType(i, AbstractGenerator::RANGE, AbstractGenerator::VECTOR);\
        function(generator -> generateVector(), generator -> getLeft(), generator -> getRight());\
        finalizeSort(generator, (sortMethod) + " / vector / range / " + generator -> name(), i, flag);\
        putchar('\n');\
    }\
while (0)

#define testKth(function, generatorType, kthMethod, size, flag) do\
    for (int i : (size)) {\
        AbstractGenerator* generator;\
        generator = new generatorType(i, AbstractGenerator::ALL, AbstractGenerator::ARRAY);\
        finalizeKth(function(generator -> generateArray(), generator -> getSize(), generator -> getIndex()),\
        generator, (kthMethod) + " / array / all / " + generator -> name(), i, flag);\
        generator = new generatorType(i, AbstractGenerator::ALL, AbstractGenerator::VECTOR);\
        finalizeKth(function(generator -> generateVector(), generator -> getSize(), generator -> getIndex()),\
        generator, (kthMethod) + " / vector / all / " + generator -> name(), i, flag);\
        generator = new generatorType(i, AbstractGenerator::ALL, AbstractGenerator::ARRAY);\
        finalizeKth(function(generator -> generateArray(), generator -> getSize(), generator -> getIndex()),\
        generator, (kthMethod) + " / array / all / " + generator -> name(), i, flag);\
        generator = new generatorType(i, AbstractGenerator::ALL, AbstractGenerator::VECTOR);\
        finalizeKth(function(generator -> generateVector(), generator -> getSize(), generator -> getIndex()),\
        generator, (kthMethod) + " / vector / all / " + generator -> name(), i, flag);\
        putchar('\n');\
    }\
while (0)

void bubbleSortTest(const std::string &name, const std::vector<int> &size, bool &flag) {
    testSort(bubbleSort, LargeRandomGenerator, name, size, flag);
    testSort(bubbleSort, MiddleRandomGenerator, name, size, flag);
    testSort(bubbleSort, SmallRandomGenerator, name, size, flag);
    testSort(bubbleSort, IncreaseItemGenerator, name, size, flag);
    testSort(bubbleSort, DecreaseItemGenerator, name, size, flag);
    testSort(bubbleSort, SameItemGenerator, name, size, flag);
}

void selectSortTest(const std::string &name, const std::vector<int> &size, bool &flag) {
    testSort(selectSort, LargeRandomGenerator, name, size, flag);
    testSort(selectSort, MiddleRandomGenerator, name, size, flag);
    testSort(selectSort, SmallRandomGenerator, name, size, flag);
    testSort(selectSort, IncreaseItemGenerator, name, size, flag);
    testSort(selectSort, DecreaseItemGenerator, name, size, flag);
    testSort(selectSort, SameItemGenerator, name, size, flag);
}

void insertSortTest(const std::string &name, const std::vector<int> &size, bool &flag) {
    testSort(insertSort, LargeRandomGenerator, name, size, flag);
    testSort(insertSort, MiddleRandomGenerator, name, size, flag);
    testSort(insertSort, SmallRandomGenerator, name, size, flag);
    testSort(insertSort, IncreaseItemGenerator, name, size, flag);
    testSort(insertSort, DecreaseItemGenerator, name, size, flag);
    testSort(insertSort, SameItemGenerator, name, size, flag);
}

void shellSortTest(const std::string &name, const std::vector<int> &size, bool &flag) {
    testSort(shellSort, LargeRandomGenerator, name, size, flag);
    testSort(shellSort, MiddleRandomGenerator, name, size, flag);
    testSort(shellSort, SmallRandomGenerator, name, size, flag);
    testSort(shellSort, IncreaseItemGenerator, name, size, flag);
    testSort(shellSort, DecreaseItemGenerator, name, size, flag);
    testSort(shellSort, SameItemGenerator, name, size, flag);
}

void quickSortTest(const std::string &name, const std::vector<int> &size, bool &flag) {
    testSort(quickSort, LargeRandomGenerator, name, size, flag);
    testSort(quickSort, MiddleRandomGenerator, name, size, flag);
    testSort(quickSort, SmallRandomGenerator, name, size, flag);
    testSort(quickSort, IncreaseItemGenerator, name, size, flag);
    testSort(quickSort, DecreaseItemGenerator, name, size, flag);
    testSort(quickSort, SameItemGenerator, name, size, flag);
}

void heapSortTest(const std::string &name, const std::vector<int> &size, bool &flag) {
    testSort(heapSort, LargeRandomGenerator, name, size, flag);
    testSort(heapSort, MiddleRandomGenerator, name, size, flag);
    testSort(heapSort, SmallRandomGenerator, name, size, flag);
    testSort(heapSort, IncreaseItemGenerator, name, size, flag);
    testSort(heapSort, DecreaseItemGenerator, name, size, flag);
    testSort(heapSort, SameItemGenerator, name, size, flag);
}

void mergeSortTest(const std::string &name, const std::vector<int> &size, bool &flag) {
    testSort(mergeSort, LargeRandomGenerator, name, size, flag);
    testSort(mergeSort, MiddleRandomGenerator, name, size, flag);
    testSort(mergeSort, SmallRandomGenerator, name, size, flag);
    testSort(mergeSort, IncreaseItemGenerator, name, size, flag);
    testSort(mergeSort, DecreaseItemGenerator, name, size, flag);
    testSort(mergeSort, SameItemGenerator, name, size, flag);
}

void radixSortTest(const std::string &name, const std::vector<int> &size, bool &flag) {
    testSort(radixSort, LargeRandomGenerator, name, size, flag);
    testSort(radixSort, MiddleRandomGenerator, name, size, flag);
    testSort(radixSort, SmallRandomGenerator, name, size, flag);
    testSort(radixSort, IncreaseItemGenerator, name, size, flag);
    testSort(radixSort, DecreaseItemGenerator, name, size, flag);
    testSort(radixSort, SameItemGenerator, name, size, flag);
}

void findKthTest(const std::string &name, const std::vector<int> &size, bool &flag) {
    testKth(findKth, LargeRandomGenerator, name, size, flag);
    testKth(findKth, MiddleRandomGenerator, name, size, flag);
    testKth(findKth, SmallRandomGenerator, name, size, flag);
    testKth(findKth, IncreaseItemGenerator, name, size, flag);
    testKth(findKth, DecreaseItemGenerator, name, size, flag);
    testKth(findKth, SameItemGenerator, name, size, flag);
}

void maintainKthTest(const std::string &name, const std::vector<int> &size, bool &flag) {
    testKth(maintainKth, LargeRandomGenerator, name, size, flag);
    testKth(maintainKth, MiddleRandomGenerator, name, size, flag);
    testKth(maintainKth, SmallRandomGenerator, name, size, flag);
    testKth(maintainKth, IncreaseItemGenerator, name, size, flag);
    testKth(maintainKth, DecreaseItemGenerator, name, size, flag);
    testKth(maintainKth, SameItemGenerator, name, size, flag);
}

#endif //SORTALGORITHM_UTILS_H
