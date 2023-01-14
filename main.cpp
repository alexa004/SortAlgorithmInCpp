#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

#include "./utils/utlis.h"
#include "./utils/fio.h"
#include "./other/EulerFilter.h"
#include "./other/FindMajority.h"
#include "./other/CountReverse.h"

void sortTest(const std::vector<int> &square, const std::vector<int> &linear, const std::vector<int> &lineLog) {
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

void kthTest(const std::vector<int> &square, const std::vector<int> &linear, const std::vector<int> &lineLog) {
    bool flag = true;
    findKthTest(std::string("find kth"), linear, flag);
    puts("-----------------------------------------------------------------------------------------\n");
    maintainKthTest(std::string("maintain kth"), lineLog, flag);
    puts("-----------------------------------------------------------------------------------------\n");
    puts(flag ? "accepted" : "wrong answer");
}

void eulerTest() {
    std::vector<int> filter(read());
    eulerFilter(filter);
    for (int i = 0; i < filter.size(); i++)
        if (filter[i]) write(i);
}

void reverseTestA() {
    int total = read();
    int *array = (int *) malloc(sizeof(int) * total);
    for (int i = 0; i < total; i++) array[i] = read();
    write(countReverse(array, total));
}

void reverseTestB() {
    std::vector<int> array(read());
    for (int &i: array) i = read();
    write(countReverse(array.begin(), (int) array.size()));
}

void majorityTestA() {
    int total = read();
    int *array = (int *) malloc(sizeof(int) * total);
    int *answer = (int *) malloc(sizeof(int) * total);
    for (int i = 0; i < total; i++) array[i] = answer[i] = read();
    std::sort(answer, answer + total);
    puts(answer[total / 2] == findMajority(array, total) ? "true" : "false");
    free(array), free(answer);
}

void majorityTestB() {
    int total = read();
    std::vector<int> array(total);
    std::vector<int> answer(total);
    for (int i = 0; i < total; i++) array[i] = answer[i] = read();
    std::sort(answer.begin(), answer.end());
    puts(answer[total / 2] == findMajority(array, total) ? "true" : "false");
}

int main() {
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
    sortTest(square, linear, lineLog);
    kthTest(square, linear, lineLog);
    return 0;
}
