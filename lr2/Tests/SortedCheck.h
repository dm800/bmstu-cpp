#pragma once

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
