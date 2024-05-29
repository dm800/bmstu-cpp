#include "implementation.cpp"


int main() {
    std::vector<Point> k;
    k.push_back(*new Point(1, 3));
    k.push_back(*new Point(2, 3));
    k.push_back(*new Point(2, 0));
    k.push_back(*new Point(1, 0));
    Rect a = *new Rect(k);
    auto f = a.begin();
    for (int len : a) {
        std::cout << len << '\n';
    }
}