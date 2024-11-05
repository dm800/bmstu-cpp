#pragma once
#include "ISorter.h"


template <typename T>
class QuickSorter : public ISorter<T> {
private:

    int* array;

    int (*comparator)(const T* a, const T* b) = nullptr;

    void swap(int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    int partition(int low, int high, Sequence<T>* arr) {
        int mid = (low + high) / 2;
        T* mide = arr->GetPtr(mid);
        T* lowe = arr->GetPtr(low);
        T* highe = arr->GetPtr(high);
        if (comparator(mide, lowe) < 0) {
            swap(low, mid);
        }
        if (comparator(highe, lowe) < 0) {
            swap(low, high);
        }
        if (comparator(highe, mide) < 0) {
            swap(mid, high);
        }
        swap(mid, high);
        T* piv = arr->GetPtr(high);
        int i = low;
        int j = low;
        while (j < high) {
            if (comparator(arr->GetPtr(j), piv) < 0) {
                swap(i, j);
                i++;
            }
            j++;
        }
        swap(i, high);
        return i;
    }

    void QuickSort(int low, int high, Sequence<T>* arr) {
        if (low < high) {
            int pi = partition(low, high, arr);
            QuickSort(low, pi - 1, arr);
            QuickSort(pi + 1, high, arr);
        }
    }

    /* void QuickSort(Sequence<T>* arr, int low, int high) {
    std::stack<std::pair<int, int>> stack;
    stack.push({low, high});

    while (!stack.empty()) {
    auto [low, high] = stack.top();
    stack.pop();

    if (low < high) {
    int pi = partition(low, high, arr);
    stack.push({low, pi - 1});
    stack.push({pi + 1, high});
    }
    }
    } */

public:
    QuickSorter(int (*comp)(const T*, const T*)) {
        comparator = comp;
    }
    Sequence<T>* Sort(Sequence<T>* arr) override {
        array = new int[arr->GetLength()];
        for (int i = 0; i < arr->GetLength(); i++) {
            array[i] = i;
        }

        QuickSort(0, arr->GetLength() - 1, arr);

        auto* newarr = new ArraySequence<T>();

        for (int i = 0; i < arr->GetLength(); i++) {
            newarr->Append(arr->Get(array[i]));
        }

        return newarr;
    }
};
