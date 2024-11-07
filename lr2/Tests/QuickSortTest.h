#pragma once

#include "../SeqGen.h"
#include "../QuickSorter.h"
#include "PersonComparators.h"
#include "SortedCheck.h"

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