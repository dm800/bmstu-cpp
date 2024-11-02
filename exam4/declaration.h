#include <vector>

class Matrix {
    public:
        std::vector<int> dels;
        std::vector<std::vector<int>> mat;
        Matrix(std::vector<std::vector<int>>);
        std::vector<int> operator[] (int index);
        std::vector<int>::const_iterator begin();
        std::vector<int>::const_iterator end();
        void change(int, int);
};