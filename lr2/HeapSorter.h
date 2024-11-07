#pragma once

#include "Base/ISorter.h"


template <typename T>
class HeapSorter : public ISorter<T> {
private:

    size_t size;
    T** array;
    int count;

    void swap(int i, int j) {
        T* temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    int (*comparator)(const T* a, const T* b) = nullptr;

    void heapify(int i, int n) {
        while (true) {
            int l = 2 * i + 1;
            int r = l + 1;
            int j = i;
            if ((l < n) && (comparator(array[i], array[l]) < 0)) {
                i = l;
            }
            if ((r < n) && (comparator(array[i], array[r]) < 0)) {
                i = r;
            }
            if (i == j) {
                break;
            }
            swap(i, j);
        }
    }


    void buildheap() {
        int i = size / 2 - 1;
        while (i >= 0) {
            heapify(i, size);
            i--;
        }
    }

    void hsort()
    {
        buildheap();
        int i = size - 1;
        while (i > 0) {
            swap(0, i);
            heapify(0, i);
            i--;
        }
    }

public:

    HeapSorter(int (*comp)(const T*, const T*)) {
        size = 0;
        count = 0;
        array = nullptr;
        comparator = comp;
    }

    Sequence<T>* Sort(Sequence<T>* arr) override {
        count = 0;
        array = new T*[arr->GetLength()];
        size = arr->GetLength();
        for (int i = 0; i < arr->GetLength(); i++) {
            array[i] = arr->GetPtr(i);
        }
        hsort();

        auto* newarr = new ArraySequence<T>();

        for (int i = 0; i < arr->GetLength(); i++) {
            newarr->Append(*array[i]);
        }

        //std::cout << "Made " << count << " comparisons" << std::endl;

        return newarr;
    }
};
