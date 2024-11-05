#pragma once
#include "Person.h"

inline int CompareHeight(const Person* a, const Person* b) {
    return static_cast<int>(a->height - b->height);
}


inline int CompareAge(const Person a, const Person b) {
    return 2050 - a.year - 2050 + b.year; // not simplified for clarity
}

inline int CompareSN(const Person a, const Person b) {
    return (a.surname + a.name).compare(b.surname + b.name);
}