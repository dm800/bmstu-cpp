#include "implementation.cpp"
#include <vector>
#include <iostream>

int main() {
    std::vector<int> a1;
    a1.push_back(1);
    a1.push_back(2);
    a1.push_back(10);
    a1.push_back(12);
    std::vector<int> a2;
    a2.push_back(2);
    a2.push_back(3);
    Seq<int> seq1 = Seq<int>(a1);
    Seq<int> seq2 = Seq<int>(a2);
    Seq<int> seq3 = seq1 + seq2;
    for (int k : seq3.values) {
        std::cout << k;
    }
    std::cout << "\n";
    Seq<int> seq4 = !seq3;
    for (int k : seq4.values) {
        std::cout << k;
    }
    std::cout << "\n";
    std::vector<Seq<int>> seq5 = seq4 / 3;
    for (Seq<int> k : seq5) {
        for (int t : k.values) {
            std::cout << t;
        }
        std::cout << "\n";
    }
    std::cout << seq4[0] << std::endl;
}