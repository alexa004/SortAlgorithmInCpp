#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#include "./utils/utlis.h"
#include "./utils/fastRead.h"
#include "./other/EulerFilter.h"
#include "./other/FindMajority.h"
#include "./other/CountReverse.h"

inline void localTest(const std::vector<int>& square
        , const std::vector<int>& linear, const std::vector<int>& lineLog) {
    bool flag = true;
    bubbleSortTest(std::string("bubble sort"), square, flag);
    puts("-----------------------------------------------------------------------------------------\n");
    selectSortTest(std::string("select sort"), square, flag);
    puts("-----------------------------------------------------------------------------------------\n");
    insertSortTest(std::string("insert sort"), square, flag);
    puts("-----------------------------------------------------------------------------------------\n");
    shellSortTest(std::string("shell sort"), lineLog, flag);
    puts("-----------------------------------------------------------------------------------------\n");
    quickSortTest(std::string("quick sort"), lineLog, flag);
    puts("-----------------------------------------------------------------------------------------\n");
    heapSortTest(std::string("heap sort"), lineLog, flag);
    puts("-----------------------------------------------------------------------------------------\n");
    mergeSortTest(std::string("merge sort"), lineLog, flag);
    puts("-----------------------------------------------------------------------------------------\n");
    radixSortTest(std::string("radix sort"), linear, flag);
    puts("-----------------------------------------------------------------------------------------\n");
    puts(flag ? "accepted" : "wrong answer");
}

inline void kthTest(const std::vector<int>& square
        , const std::vector<int>& linear, const std::vector<int>& lineLog) {
    bool flag = true;
    findKthTest(std::string("find kth"), linear, flag);
    puts("-----------------------------------------------------------------------------------------\n");
    maintainKthTest(std::string("maintain kth"), lineLog, flag);
    puts("-----------------------------------------------------------------------------------------\n");
    puts(flag ? "accepted" : "wrong answer");
}

inline void eulerTest() {
    std::vector<int> filter(readInt());
    eulerFilter(filter);
    for (int i = 0; i < filter.size(); i++)
        if (filter[i]) writeInt(i);
}

inline void reverseTestA() {
    int total = readInt();
    int* array = (int*)malloc(sizeof(int) * total);
    for (int i = 0; i < total; i++) array[i] = readInt();
    writeLongLong(countReverse(array, total));
}

inline void reverseTestB() {
    std::vector<int> array(readInt());
    for (int& i : array) i = readInt();
    writeLongLong(countReverse(array.begin(), array.size()));
}

inline void majorityTestA() {
    int total = readInt();
    int* array = (int*)malloc(sizeof(int) * total);
    int* answer = (int*)malloc(sizeof(int) * total);
    for (int i = 0; i < total; i++) array[i] = answer[i] = readInt();
    std::sort(answer, answer + total);
    puts(answer[total / 2] == findMajority(array, total) ? "true" : "false");
    free(array), free(answer);
}

inline void majorityTestB() {
    int total = readInt();
    std::vector<int> array(total);
    std::vector<int> answer(total);
    for (int i = 0; i < total; i++) array[i] = answer[i] = readInt();
    std::sort(answer.begin(), answer.end());
    puts(answer[total / 2] == findMajority(array, total) ? "true" : "false");
}

int main(int argc, char const *argv[]) {
    const std::vector<int> square = {
            AbstractGenerator::ONE,
            AbstractGenerator::TWO,
            AbstractGenerator::FOUR,
            AbstractGenerator::SQUARE
    };
    const std::vector<int> linear = {
            AbstractGenerator::ONE,
            AbstractGenerator::TWO,
            AbstractGenerator::FOUR,
            AbstractGenerator::LINEAR
    };
    const std::vector<int> lineLog = {
            AbstractGenerator::ONE,
            AbstractGenerator::TWO,
            AbstractGenerator::FOUR,
            AbstractGenerator::LINE_LOG
    };
    if (argc == 2 && strcmp(argv[1], "-LocalTest") == 0) localTest(square, linear, lineLog);
    else if (argc == 2 && strcmp(argv[1], "-KthTest") == 0) kthTest(square, linear, lineLog);
    else if (argc == 2 && strcmp(argv[1], "-EulerTest") == 0) eulerTest();
    else if (argc == 2 && strcmp(argv[1], "-ReverseTestA") == 0) reverseTestA();
    else if (argc == 2 && strcmp(argv[1], "-ReverseTestB") == 0) reverseTestB();
    else if (argc == 2 && strcmp(argv[1], "-MajorityTestA") == 0) majorityTestA();
    else if (argc == 2 && strcmp(argv[1], "-MajorityTestB") == 0) majorityTestB();
    else if (argc == 3 && strcmp(argv[1], "-cancel") == 0 && strcmp(argv[2], "-generator") == 0) {
        new LargeRandomGenerator(AbstractGenerator::ONE, AbstractGenerator::ALL, AbstractGenerator::ARRAY);
        new MiddleRandomGenerator(AbstractGenerator::ONE, AbstractGenerator::ALL, AbstractGenerator::ARRAY);
        new SmallRandomGenerator(AbstractGenerator::ONE, AbstractGenerator::ALL, AbstractGenerator::ARRAY);
        new IncreaseItemGenerator(AbstractGenerator::ONE, AbstractGenerator::ALL, AbstractGenerator::ARRAY);
        new DecreaseItemGenerator(AbstractGenerator::ONE, AbstractGenerator::ALL, AbstractGenerator::ARRAY);
        new SameItemGenerator(AbstractGenerator::ONE, AbstractGenerator::ALL, AbstractGenerator::ARRAY);
    }
    else if (argc == 3 && strcmp(argv[1], "-cancel") == 0 && strcmp(argv[2], "-sort") == 0) {
        int array[6] = {1, 1, 4, 5, 1, 4};
        bubbleSort(array, 0), bubbleSort(array, 0, 0);
        selectSort(array, 0), selectSort(array, 0, 0);
        insertSort(array, 0), insertSort(array, 0, 0);
        shellSort(array, 0), shellSort(array, 0, 0);
        quickSort(array, 0), quickSort(array, 0, 0);
        heapSort(array, 0), heapSort(array, 0, 0);
        mergeSort(array, 0), mergeSort(array, 0, 0);
        radixSort(array, 0), radixSort(array, 0, 0);
        std::vector<int> vector;
        mergeSort(vector.begin(), 0), mergeSort(vector.begin(), 0, 0);
        radixSort(vector.begin(), 0), radixSort(vector.begin(), 0, 0);
    }
    return 0;
}
