#ifndef SORTALGORITHM_UTLIS_H
#define SORTALGORITHM_UTLIS_H

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
#include "../test/IncreaseIntGenerator.h"
#include "../test/DecreaseIntGenerator.h"
#include "../test/SameIntGenerator.h"

inline void finalizeSort(AbstractGenerator* generator, const std::string& name, int size, bool& flag) {
    bool result = generator -> checkAnswer();
    flag &= result;
    printf("%s, size %d : %s\n", name.c_str(), size, result ? "true" : "false");
    if (size < 10 && !result) generator -> display();
    delete generator;
}

inline void finalizeKth(int value, AbstractGenerator* generator, const std::string& name, int size, bool& flag) {
    bool result = generator -> checkAnswer(value);
    flag &= result;
    printf("%s, size %d : %s\n", name.c_str(), size, result ? "true" : "false");
    if (size < 10 && !result) generator -> display();
    delete generator;
}

#define testSort(function, generatorType, sortMethod, size, flag) do\
    for (int i : size) {\
        AbstractGenerator* generator;\
        generator = new generatorType(i, AbstractGenerator::ALL, AbstractGenerator::ARRAY);\
        function(generator -> generateArray(), generator -> getSize());\
        finalizeSort(generator, sortMethod + " / array / all / " + generator -> name(), i, flag);\
        generator = new generatorType(i, AbstractGenerator::ALL, AbstractGenerator::VECTOR);\
        function(generator -> generateVector(), generator -> getSize());\
        finalizeSort(generator, sortMethod + " / vector / all / " + generator -> name(), i, flag);\
        generator = new generatorType(i, AbstractGenerator::RANGE, AbstractGenerator::ARRAY);\
        function(generator -> generateArray(), generator -> getLeft(), generator -> getRight());\
        finalizeSort(generator, sortMethod + " / array / range / " + generator -> name(), i, flag);\
        generator = new generatorType(i, AbstractGenerator::RANGE, AbstractGenerator::VECTOR);\
        function(generator -> generateVector(), generator -> getLeft(), generator -> getRight());\
        finalizeSort(generator, sortMethod + " / vector / range / " + generator -> name(), i, flag);\
        putchar('\n');\
    }\
while (0)

#define testKth(function, generatorType, kthMethod, size, flag) do\
    for (int i : size) {\
        AbstractGenerator* generator;\
        generator = new generatorType(i, AbstractGenerator::ALL, AbstractGenerator::ARRAY);\
        finalizeKth(function(generator -> generateArray(), generator -> getSize(), generator -> getIndex()),\
        generator, kthMethod + " / array / all / " + generator -> name(), i, flag);\
        generator = new generatorType(i, AbstractGenerator::ALL, AbstractGenerator::VECTOR);\
        finalizeKth(function(generator -> generateVector(), generator -> getSize(), generator -> getIndex()),\
        generator, kthMethod + " / vector / all / " + generator -> name(), i, flag);\
        generator = new generatorType(i, AbstractGenerator::ALL, AbstractGenerator::ARRAY);\
        finalizeKth(function(generator -> generateArray(), generator -> getSize(), generator -> getIndex()),\
        generator, kthMethod + " / array / all / " + generator -> name(), i, flag);\
        generator = new generatorType(i, AbstractGenerator::ALL, AbstractGenerator::VECTOR);\
        finalizeKth(function(generator -> generateVector(), generator -> getSize(), generator -> getIndex()),\
        generator, kthMethod + " / vector / all / " + generator -> name(), i, flag);\
        putchar('\n');\
    }\
while (0)

inline void bubbleSortTest(const std::string& name, const std::vector<int>& size, bool& flag) {
    testSort(bubbleSort, LargeRandomGenerator, name, size, flag);
    testSort(bubbleSort, MiddleRandomGenerator, name, size, flag);
    testSort(bubbleSort, SmallRandomGenerator, name, size, flag);
    testSort(bubbleSort, IncreaseIntGenerator, name, size, flag);
    testSort(bubbleSort, DecreaseIntGenerator, name, size, flag);
    testSort(bubbleSort, SameIntGenerator, name, size, flag);
}

inline void selectSortTest(const std::string& name, const std::vector<int>& size, bool& flag) {
    testSort(selectSort, LargeRandomGenerator, name, size, flag);
    testSort(selectSort, MiddleRandomGenerator, name, size, flag);
    testSort(selectSort, SmallRandomGenerator, name, size, flag);
    testSort(selectSort, IncreaseIntGenerator, name, size, flag);
    testSort(selectSort, DecreaseIntGenerator, name, size, flag);
    testSort(selectSort, SameIntGenerator, name, size, flag);
}

inline void insertSortTest(const std::string& name, const std::vector<int>& size, bool& flag) {
    testSort(insertSort, LargeRandomGenerator, name, size, flag);
    testSort(insertSort, MiddleRandomGenerator, name, size, flag);
    testSort(insertSort, SmallRandomGenerator, name, size, flag);
    testSort(insertSort, IncreaseIntGenerator, name, size, flag);
    testSort(insertSort, DecreaseIntGenerator, name, size, flag);
    testSort(insertSort, SameIntGenerator, name, size, flag);
}

inline void shellSortTest(const std::string& name, const std::vector<int>& size, bool& flag) {
    testSort(shellSort, LargeRandomGenerator, name, size, flag);
    testSort(shellSort, MiddleRandomGenerator, name, size, flag);
    testSort(shellSort, SmallRandomGenerator, name, size, flag);
    testSort(shellSort, IncreaseIntGenerator, name, size, flag);
    testSort(shellSort, DecreaseIntGenerator, name, size, flag);
    testSort(shellSort, SameIntGenerator, name, size, flag);
}

inline void quickSortTest(const std::string& name, const std::vector<int>& size, bool& flag) {
    testSort(quickSort, LargeRandomGenerator, name, size, flag);
    testSort(quickSort, MiddleRandomGenerator, name, size, flag);
    testSort(quickSort, SmallRandomGenerator, name, size, flag);
    testSort(quickSort, IncreaseIntGenerator, name, size, flag);
    testSort(quickSort, DecreaseIntGenerator, name, size, flag);
    testSort(quickSort, SameIntGenerator, name, size, flag);
}

inline void heapSortTest(const std::string& name, const std::vector<int>& size, bool& flag) {
    testSort(heapSort, LargeRandomGenerator, name, size, flag);
    testSort(heapSort, MiddleRandomGenerator, name, size, flag);
    testSort(heapSort, SmallRandomGenerator, name, size, flag);
    testSort(heapSort, IncreaseIntGenerator, name, size, flag);
    testSort(heapSort, DecreaseIntGenerator, name, size, flag);
    testSort(heapSort, SameIntGenerator, name, size, flag);
}

inline void mergeSortTest(const std::string& name, const std::vector<int>& size, bool& flag) {
    testSort(mergeSort, LargeRandomGenerator, name, size, flag);
    testSort(mergeSort, MiddleRandomGenerator, name, size, flag);
    testSort(mergeSort, SmallRandomGenerator, name, size, flag);
    testSort(mergeSort, IncreaseIntGenerator, name, size, flag);
    testSort(mergeSort, DecreaseIntGenerator, name, size, flag);
    testSort(mergeSort, SameIntGenerator, name, size, flag);
}

inline void radixSortTest(const std::string& name, const std::vector<int>& size, bool& flag) {
    testSort(radixSort, LargeRandomGenerator, name, size, flag);
    testSort(radixSort, MiddleRandomGenerator, name, size, flag);
    testSort(radixSort, SmallRandomGenerator, name, size, flag);
    testSort(radixSort, IncreaseIntGenerator, name, size, flag);
    testSort(radixSort, DecreaseIntGenerator, name, size, flag);
    testSort(radixSort, SameIntGenerator, name, size, flag);
}

inline void findKthTest(const std::string& name, const std::vector<int>& size, bool& flag) {
    testKth(findKth, LargeRandomGenerator, name, size, flag);
    testKth(findKth, MiddleRandomGenerator, name, size, flag);
    testKth(findKth, SmallRandomGenerator, name, size, flag);
    testKth(findKth, IncreaseIntGenerator, name, size, flag);
    testKth(findKth, DecreaseIntGenerator, name, size, flag);
    testKth(findKth, SameIntGenerator, name, size, flag);
}

inline void maintainKthTest(const std::string& name, const std::vector<int>& size, bool& flag) {
    testKth(maintainKth, LargeRandomGenerator, name, size, flag);
    testKth(maintainKth, MiddleRandomGenerator, name, size, flag);
    testKth(maintainKth, SmallRandomGenerator, name, size, flag);
    testKth(maintainKth, IncreaseIntGenerator, name, size, flag);
    testKth(maintainKth, DecreaseIntGenerator, name, size, flag);
    testKth(maintainKth, SameIntGenerator, name, size, flag);
}

#endif //SORTALGORITHM_UTLIS_H
