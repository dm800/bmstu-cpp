#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class State {
    public:
        int color;
        /*
        0 - unvisited
        1 - visited
        2 - cleared
        */
        int name;
        int ans_name;
        std::vector<int>* d_matrix_row;
        std::vector<std::string>* f_matrix_row;
};

int c = 0;
std::vector<State*> ans;
State* aut[100000];
int q = 0;

void dfs() {
    State* cur = aut[q];
    cur->ans_name = c;
    cur->color = 1;
    ans.push_back(cur);
    c++;
    for (int i = 0; i < cur->d_matrix_row->size(); i++) {
        int t = cur->d_matrix_row->at(i);
        q = t;
        int s = aut[t]->color;
        if (s == 0) {
            dfs();
        }
        cur->d_matrix_row->at(i) = aut[t]->ans_name;
    }
    cur->color = 2;
}


int main() {
//    std::ifstream in("input.txt");
    int n;
    int m;
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
    int delta = 0;
    cin >> st;
    while (isdigit(st.at(0))) {
        std::vector<int>* row = new std::vector<int>();
        while (s < m) {
            s++;
            row->push_back(stoi(st));
            cin >> st;
        }
        row->push_back(stoi(st));
        s = 0;
        delta++;
    }
    int c = 0;
    for (int k = 0; k < n + delta; k++) {
        std::vector<std::string>* row = new std::vector<std::string>();;
        State* q = new State();
        for (int i = 0; i < m; i++) {
            row->push_back(st);
            cin >> st;
        }
        row->push_back(st);
        q->name = k;
        q->ans_name = -1;
        q->color = 0;
        q->f_matrix_row = row;
        q->d_matrix_row = d_matrix[k];
        aut[c] = q;
        c++;
        f_matrix.push_back(row);
    }
    dfs();
//    ofstream out("ans.txt");
    cout << n << "\n";
    cout << m << "\n";
    cout << 0 << "\n";
    for (State* t : ans) {
        for (int k = 0; k < t->d_matrix_row->size(); k++) {
            cout << t->d_matrix_row->at(k) << " ";
        }
        cout << "\n";
    }
    for (State* t : ans) {
        for (int k = 0; k < t->d_matrix_row->size(); k++) {
            cout << t->f_matrix_row->at(k) << " ";
        }
        cout << "\n";
    }
}


/*
Решение не оч, но я не мог победить автопроверку на сервере - пришлось выдумывать.
*/