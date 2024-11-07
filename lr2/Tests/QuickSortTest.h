#pragma once

#include "../SeqGen.h"
#include "../QuickSorter.h"
#include "PersonComparators.h"

template<typename T>
bool SortedCheck(int (*compare)(const T* val1, const T* val2), Sequence<T>* seq) {
    std::cout << "Checking if seq is sorted" << std::endl;
    for (int i = 0; i < seq->GetLength() - 1; i++) {
        if (compare(seq->GetPtr(i), seq->GetPtr(i + 1)) > 0) {
            std::cout << "Seq is not sorted (indexes " << i << " " << i + 1 << ")" << std::endl;
            return false;
        }
    }
    std::cout << "Seq is sorted" << std::endl;
    return true;
}


inline bool QuickSortCheck(int n, int (*func)(const Person* val1, const Person* val2)) {
    std::cout << "Started quick sort check for " << n << std::endl;
    Sequence<Person>* seq = SeqGen<Person>(n);
    auto* sorter = new QuickSorter(func);
    std::cout << "Started sorting" << std::endl;
    seq = TimeCheckSort(sorter, seq);
    if (!SortedCheck(func, seq)) {
        return false;
    }
    std::cout << "Finished quick sort check for " << n << std::endl;
    std::cout << std::endl;
    return true;
}

inline void QuickSortLowCheck() {
    auto* func = CompareHeight;
    QuickSortCheck(10, func);
    QuickSortCheck(100, func);
    QuickSortCheck(1000, func);
}

inline void QuickSortHighCheck() {
    auto* func = CompareHeight;
    QuickSortCheck(10000, func);
    QuickSortCheck(100000, func);
    QuickSortCheck(1000000, func);
}

inline void QuickSortGeneralCheck() {
    QuickSortLowCheck();
    QuickSortHighCheck();
}

inline void QuickSortDiffCheck(int n = 10000) {
    QuickSortCheck(n, CompareAge);
    QuickSortCheck(n, CompareSN);
    QuickSortCheck(n, CompareHeight);
}