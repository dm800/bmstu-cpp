#include "declaration.h"

Matrix::Matrix(std::vector<std::vector<int>> mat) {
    for (std::vector<int> row : mat) {
        int s = 1;
        for (int k : row) {
            s *= k;
        }
        this->dels.push_back(s);
    }
    this->mat = mat;
}

std::vector<int> Matrix::operator[] (int index) {
    return this->mat[index];
}

std::vector<int>::const_iterator Matrix::begin() {
    return (this->dels).begin();
}

std::vector<int>::const_iterator Matrix::end() {
    return (this->dels).end();
}

void Matrix::change(int x, int val) {
    int old = dels.at(x);
    dels.at(x) = val;
    int s = 1;
    for (int i = 0; i < mat.at(x).size(); i++) {
        mat.at(x).at(i) = mat.at(x).at(i) * val / old;
    }
}