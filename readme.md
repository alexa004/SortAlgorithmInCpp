# Sort Algorithm In Cpp

![license](https://img.shields.io/github/license/Chenrt-ggx/SortAlgorithmInCpp)
![test](https://github.com/Chenrt-ggx/SortAlgorithmInCpp/actions/workflows/catch.test.yml/badge.svg)

## Sort Algorithms

- Radix Sort: $O(n)$.
- Merge Sort: $O(nlogn)$.
- Heap Sort: $O(nlogn)$.
- Quick Sort: $O(nlogn)$.
- Shell Sort: $O(n^2)$.
- Insert Sort: $O(n^2)$.
- Select Sort: $O(n^2)$.
- Bubble Sort: $O(n^2)$.

## Unit testing with Catch

### Data Size

- Some small $n$ for boundary situation: $1$, $2$ and $4$.
- For $O(n^2)$ algorithms, use $5e3$ for functional test.
- For $O(nlogn)$ algorithms, use $5e5$ for functional test.
- For $O(n)$ algorithms, use $1e6$ for functional test.

### Data Characteristics

- All same, increasing and decreasing.
- Random in int range, with small amount of duplicate.
- Random in short range, with middle amount of duplicate.
- Random in byte range, with large amount of duplicate.
