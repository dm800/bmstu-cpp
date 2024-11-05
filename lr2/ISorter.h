#pragma once
#include "ArraySequence.h"

template <typename T>
class ISorter {
    private:
        int (*comparator)(const T* a, const T* b) = nullptr;
    public:
        virtual Sequence<T>* Sort(Sequence<T>* arr) = 0;
};