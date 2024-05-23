#include "declaration.h"
#include <iostream>

pair::pair(int a, int b) {
    this->a = a;
    this->b = b;
}

bool pair::operator==(pair& other) {
    return (a == other.a && b == other.b);
}

posl::posl(std::vector<int> a) {
    this->numbers = a;
}

posl& posl::operator++() {
    if ((i + 1 == j) && (j == numbers.size() - 1)) {
        i = numbers.size() - 1;
        j = numbers.size() - 1;
        return *this;
    }
    else if (i + 1 == j) {
        j++;
        i = 0;
    }
    else {
        i++;
    }
    return *this;
}

pair* posl::operator*() {
    return new pair(numbers[i], numbers[j]);
}

posl& posl::begin() {
    posl* temp = new posl(numbers);
    temp->i = 0;
    temp->j = 1;
    return *temp;
}

posl& posl::end() {
    posl* temp = new posl(numbers);
    temp->i = numbers.size() - 1;
    temp->j = temp->i;
    return *temp;
}

bool posl::operator!=(posl& other) {
    return ***this != **other;
}

bool posl::operator==(posl& other) {
    return ***this == **other;
}