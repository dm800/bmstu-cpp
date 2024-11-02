#include <iostream>
#include "implementation.cpp"

int main() {
    std::vector<std::vector<int>> mat;
    std::vector<int> row1;
    row1.push_back(1);
    row1.push_back(2);
    std::vector<int> row2;
    row2.push_back(3);
    row2.push_back(4);
    mat.push_back(row1);
    mat.push_back(row2);
    Matrix m = *new Matrix(mat);
    for (int elem : m) {
        std::cout << elem << "\n";
    }
    for (int elem : m[1]) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
    m.change(1, 20);
    for (int elem : m) {
        std::cout << elem << "\n";
    }
    for (int elem : m[1]) {
        std::cout << elem << " ";
    }
}