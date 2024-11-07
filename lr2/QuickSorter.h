#pragma once

#include "Base/ISorter.h"


template <typename T>
class QuickSorter : public ISorter<T> {
private:

    T** array;
    int count;

    int (*comparator)(const T* a, const T* b) = nullptr;

    void swap(int i, int j) {
        T* temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    struct partans {
        int lt;
        int gt;
    };

    partans partition(int low, int high, Sequence<T>* arr) {
        int mid = low + (high - low) / 2;
        if (comparator(array[mid], array[low]) < 0) {
            swap(low, mid);
        }
        count++;
        if (comparator(array[high], array[low]) < 0) {
            swap(low, high);
        }
        count++;
        if (comparator(array[high], array[mid]) < 0) {
            swap(mid, high);
        }
        count++;
        swap(mid, high);
        T* piv = array[high];
        int lt = low;
        int j = low;
        int gt = high;
        while (j <= gt) {
            if (comparator(array[j], piv) < 0) {
                swap(lt, j);
                lt++;
                j++;
            }
            else if (comparator(array[j], piv) > 0) {
                swap(gt, j);
                gt--;
            }
            else {
                j++;
            }
            count++;
        }
        return { lt, gt };
    }

    void QuickSort(int low, int high, Sequence<T>* arr) {
        if (low < high) {
            auto p = partition(low, high, arr);
            QuickSort(low, p.lt - 1, arr);
            QuickSort(p.gt + 1, high, arr);
        }
    }

public:

    QuickSorter(int (*comp)(const T*, const T*)) {
        count = 0;
        array = nullptr;
        comparator = comp;
    }

    Sequence<T>* Sort(Sequence<T>* arr) override {
        count = 0;
        array = new T*[arr->GetLength()];
        for (int i = 0; i < arr->GetLength(); i++) {
            array[i] = arr->GetPtr(i);
        }
        QuickSort(0, arr->GetLength() - 1, arr);

        auto* newarr = new ArraySequence<T>();

        for (int i = 0; i < arr->GetLength(); i++) {
            newarr->Append(*array[i]);
        }

        //std::cout << "Made " << count << " comparisons" << std::endl;

        return newarr;
    }
};
