cmake_minimum_required(VERSION 3.16)
project(SortAlgorithm)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        SortAlgorithm

        main.cpp
        utils/utlis.h
        utils/heap.h
        utils/fastRead.h

        test/AbstractGenerator.h
        test/LargeRandomGenerator.h
        test/MiddleRandomGenerator.h
        test/SmallRandomGenerator.h
        test/IncreaseIntGenerator.h
        test/DecreaseIntGenerator.h
        test/SameIntGenerator.h

        sort/BubbleSort.h
        sort/SelectSort.h
        sort/InsertSort.h
        sort/ShellSort.h
        sort/QuickSort.h
        sort/HeapSort.h
        sort/MergeSort.h
        sort/RadixSort.h

        other/FindKth.h
        other/CountReverse.h
        other/MaintainKth.h
        other/FindMajority.h
        other/EulerFilter.h
)
