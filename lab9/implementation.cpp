#include "declaration.h"
#include <algorithm>
#include <iostream>

template<typename T>
Seq<T>::Seq(std::vector<T> vals) {
    this->values = vals;
}

template<typename T> requires std::equality_comparable<T>
Seq<T> Seq<T>::operator+(Seq<T> b) {
    std::vector<T> temp;
    for (T a : this->values) {
        temp.push_back(a);
    }
    for (T a : b.values) {
        temp.push_back(a);
    }
    Seq<T> ans = *new Seq<T>(temp);
    return ans;
}

template<typename T> requires std::equality_comparable<T>
T Seq<T>::operator[](int i) {
    return this->values[i];
}

template<typename T> requires std::equality_comparable<T>
Seq<T> Seq<T>::operator!() {
    std::vector<T> temp;
    for (T a : this->values) {
        int c = 0;
        for (T b : temp) {
            if (a == b) {
                c = 1;
                break;
            }
        }
        if (!c) {
            temp.push_back(a);
        }
    }
    Seq<T> ans = *new Seq<T>(temp);
    return ans;
}

template<typename T> requires std::equality_comparable<T>
std::vector<Seq<T>> Seq<T>::operator/(int k) {
    int size = this->values.size();
    int step = 0;
    int offset = 0;
    std::vector<Seq<T>> ans;
    while (k != 0) {
        std::vector<T> cur;
        if ((size - offset) % k == 0) {
            step = (size - offset) / k;
        }
        else {
            step = (size - offset) / k + 1;
        }
        for (int i = offset; i < offset + step; i++) {
            cur.push_back(this->values[i]);
        }
        offset += step;
        k--;
        ans.push_back(cur);
    }
    return ans;
}