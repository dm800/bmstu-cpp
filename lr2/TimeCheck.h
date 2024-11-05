#pragma once
#include <chrono>
#include <iostream>

#include "ISorter.h"

template<typename ... Args>
bool TimeCheck(bool func(Args...), Args ... args) {
    auto start = std::chrono::steady_clock::now();
    if (!func(args...)) {
        return false;
    }
    std::cout << "completed in: " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start).count() << " μs\n";
    std::cout << std::endl;
    return true;
}

template<typename T>
Sequence<T>* TimeCheckSort(ISorter<T>* sorter, Sequence<T>* arr) {
    auto start = std::chrono::steady_clock::now();
    arr = sorter->Sort(arr);
    std::cout << "completed in: " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start).count() << " μs\n";
    std::cout << std::endl;
    return arr;
}