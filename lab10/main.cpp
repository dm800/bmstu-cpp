#include "implementation.cpp"


int main() {
    std::vector<int> k;
    k.push_back(0);
    k.push_back(1);
    k.push_back(2);
    posl a = *new posl(k);
    auto f = a.begin();
    for (auto n = a.begin(); n != a.end(); ++n) {
        std::cout << "(" << (*n)->a << ", " << (*n)->b << ")" << "\n";
    }
    for (pair* n : a) {
        std::cout << "(" << n->a << ", " << n->b << ")" << "\n";
    }
}