#pragma once
#include <chrono>
#include <iostream>

#include "../Base/ISorter.h"

template<typename ... Args>
int TimeCheck(bool func(Args...), Args ... args) {
    auto start = std::chrono::steady_clock::now();
    if (!func(args...)) {
        return false;
    }
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count();
    std::cout << "Completed in: " << duration << " ms\n";
    return duration;
}

template<typename T>
Sequence<T>* TimeCheckSort(ISorter<T>* sorter, Sequence<T>* arr) {
    auto start = std::chrono::steady_clock::now();
    arr = sorter->Sort(arr);
    std::cout << "Completed in: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() << " ms\n";
    return arr;
}