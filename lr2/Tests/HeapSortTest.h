#pragma once

#include "../SeqGen.h"
#include "../HeapSorter.h"
#include "PersonComparators.h"
#include "SortedCheck.h"

inline bool HeapSortCheck(int n, int (*func)(const Person* val1, const Person* val2)) {
    std::cout << "Started Heap sort check for " << n << std::endl;
    Sequence<Person>* seq = SeqGen<Person>(n);
    auto* sorter = new HeapSorter(func);
    std::cout << "Started sorting" << std::endl;
    seq = TimeCheckSort(sorter, seq);
    if (!SortedCheck(func, seq)) {
        return false;
    }
    std::cout << "Finished Heap sort check for " << n << std::endl;
    std::cout << std::endl;
    return true;
}

inline void HeapSortLowCheck() {
    auto* func = CompareHeight;
    HeapSortCheck(10, func);
    HeapSortCheck(100, func);
    HeapSortCheck(1000, func);
}

inline void HeapSortHighCheck() {
    auto* func = CompareHeight;
    HeapSortCheck(10000, func);
    HeapSortCheck(100000, func);
    HeapSortCheck(1000000, func);
}

inline void HeapSortGeneralCheck() {
    HeapSortLowCheck();
    HeapSortHighCheck();
}

inline void HeapSortDiffCheck(int n = 10000) {
    HeapSortCheck(n, CompareAge);
    HeapSortCheck(n, CompareSN);
    HeapSortCheck(n, CompareHeight);
}