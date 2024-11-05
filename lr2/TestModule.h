#pragma once

#include "Person.cpp"
#include "SeqGen.h"
#include "TimeCheck.h"
#include "QuickSorter.h"

inline bool SinglePersonGenTest(const Person* person) {
    if (person->height > 210 || person->height < 150) {
        return false;
    }
    if (person->weight > 150 || person->weight < 50) {
        return false;
    }
    if (person->year < 1950 || person->year > 2050) {
        return false;
    }
    if (person->surname.empty() || person->name.empty()) {
        return false;
    }
    return true;
}

inline bool RandomPersonGenCheck() {
    std::cout << "Started test for random person" << std::endl;
    Person* person = Person::getRandom();
    if (!SinglePersonGenTest(person)) {
        return false;
    }
    std::cout << "Finished test for random person" << std::endl;
    std::cout << std::endl;
    return true;
}

inline bool SeqGenCheck(int n) {
    ArraySequence<Person>* seq = SeqGen<Person>(n);
    std::cout << "Started test for " << n << std::endl;
    for (int i = 0; i < seq->GetLength();i++) {
        auto elem = seq->Get(i);
        if (!SinglePersonGenTest(&elem)) {
            std::cout << "Problem with index " << i << std::endl;
            return false;
        }
    }
    std::cout << "Finished test for " << n << std::endl;
    return true;
}

inline bool SeqGenLowCheck() {
    return TimeCheck(SeqGenCheck, 10) && TimeCheck(SeqGenCheck, 100) && TimeCheck(SeqGenCheck, 1000);
}

inline bool SeqGenHighCheck() {
    return TimeCheck(SeqGenCheck, 10000) && TimeCheck(SeqGenCheck, 100000) && TimeCheck(SeqGenCheck, 1000000);
}

inline bool SwapCheck() {
    std::cout << "Performing swap check" << std::endl;
    ArraySequence<Person>* seq = SeqGen<Person>(10);
    Person first = seq->Get(0);
    Person last = seq->Get(9);
    seq->Swap(0, 9);
    if (seq->Get(0) != last || seq->Get(9) != first) {
        std::cout << "Swap check failed" << std::endl;
        return false;
    }
    std::cout << "Swap check passed" << std::endl;
    std::cout << std::endl;
    return true;
}

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


inline bool QuickSortCheck(int n) {
    std::cout << "Started quick sort check for " << n << std::endl;
    Sequence<Person>* seq = SeqGen<Person>(n);
    auto* sorter = new QuickSorter(CompareHeight);
    std::cout << "Started sorting" << std::endl;
    seq = TimeCheckSort(sorter, seq);
    if (SortedCheck(CompareHeight, seq)) {
        return false;
    }
    std::cout << "Finished quick sort check for " << n << std::endl;
    std::cout << std::endl;
    return true;
}

inline bool QuickSortLowCheck() {
    return QuickSortCheck(10) && QuickSortCheck(100) && QuickSortCheck(1000);
}

inline bool QuickSortHighCheck() {
    return QuickSortCheck(10000) && QuickSortCheck(100000) && QuickSortCheck(1000000);
}

inline bool QuickSortGeneralCheck() {
    return QuickSortLowCheck() && QuickSortHighCheck();
}