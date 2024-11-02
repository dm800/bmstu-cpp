#pragma once
#include "ArraySequence.h"

template <class T>
ArraySequence<T>* SeqGen(int n)
{
    T* temp = new T[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = *T::getRandom();
    }
    return new ArraySequence<T>(temp, n);
}

