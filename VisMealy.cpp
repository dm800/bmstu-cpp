#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int m;
    int q;
    cin >> n;
    cin >> m;
    cin >> q;
    std::vector<std::vector<int>*> d_matrix;
    std::vector<std::vector<std::string>*> f_matrix;
    int t;
    for (int k = 0; k < n; k++) {
        std::vector<int>* row = new std::vector<int>();
        for (int i = 0; i < m; i++) {
            cin >> t;
            row->push_back(t);
        }
        d_matrix.push_back(row);
    }
    std::string st;
    int s = 1;
    int c = 0;
    std::cout << "digraph {\n\trankdir = LR\n";
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < m; i++) {
            cin >> st;
            std::cout << "\t" << k << " -> " << d_matrix[k]->at(i) << " [label = \"" 
            << (char)(97 + i) << "(" << st << ")\"]\n";
        }
    }
    std::cout << "}";
}