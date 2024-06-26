#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
#include <fstream>

class State {
    public:
        State* parent;
        int index;
        int name;
        int depth;
        int ans_name;
        int color = 0;
        /*
        0 - unvisited
        1 - visited
        2 - cleared
        */
        bool is_starting = false;
        State(int);
};

class Aut {
    public:
        std::vector<State*> states;
        std::vector<std::vector<State*>> delta;
        std::vector<std::vector<std::string>> f;
        bool contains(int);
};

bool Aut::contains(int name) {
    for (State* q : states) {
        if (q->name == name) {
            return true;
        }
    }
    return false;
}

State::State(int x) {
    this->name = x;
    this->parent = this;
    this->depth = 0;
    this->ans_name = 0;
}


State* Find(State* x) {
    State* root;
    if (x->parent == x) {
        root = x;
    }
    else {
        x->parent = Find(x->parent);
        root = x->parent;
    }
    return root;
}

void Union(State* x, State* y) {
    State* root_x = Find(x);
    State* root_y = Find(y);
    if (root_x->depth < root_y->depth) {
        root_x->parent = root_y;
    }
    else {
        root_y->parent = root_x;
        if ((root_x->depth == root_y->depth) && (root_x != root_y)) {
            root_x->depth = root_x->depth + 1;
        }
    }
}

std::vector<State*> aut;
std::vector<std::vector<State*>> delta;
std::vector<std::vector<std::string>> f;
int m = 0;
int m1 = 0;

std::vector<State*> Split1() {
    m = aut.size();
    for (int i = 0; i < aut.size(); i++) {
        State* q1 = aut[i];
        for (int k = i + 1; k < aut.size(); k++) {
            State* q2 = aut[k];
            if (Find(q1) != Find(q2)) {
                bool eq = true;
                for (int s = 0; s < f[0].size(); s++) {
                    if (f[q1->name][s] != f[q2->name][s]) {
                        eq = false;
                        break;
                    }
                }
                if (eq) {
                    Union(q1, q2);
                    m -= 1;
                }
            }
        }
    }
    std::vector<State*> pi;
    for (State* q : aut) {
        pi.push_back(Find(q));
    }
    return pi;
}

std::vector<State*> Split(std::vector<State*> pi) {
    for (State* q : aut) {
        q->parent = q;
        q->depth = 0;
    }
    m = aut.size();
    for (int i = 0; i < aut.size(); i++) {
        State* q1 = aut[i];
        for (int k = i + 1; k < aut.size(); k++) {
            State* q2 = aut[k];
            if (pi[q1->name] == pi[q2->name] && Find(q1) != Find(q2)) {
                bool eq = true;
                for (int s = 0; s < f[0].size(); s++) {
                    int w1 = delta[q1->name][s]->name;
                    int w2 = delta[q2->name][s]->name;
                    if (pi[w1] != pi[w2]) {
                        eq = false;
                        break;
                    }
                }
                if (eq) {
                    Union(q1, q2);
                    m -= 1;
                }
            }
        }
    }
    std::vector<State*> ans;
    for (State* q : aut) {
        ans.push_back(Find(q));
    }
    return ans;
}

int q;

Aut Minimize() {
    std::vector<State*> pi = Split1();
    while (true) {
        m1 = m;
        pi = Split(pi);
        if (m == m1) {
            break;
        }
    }
    Aut new_aut;
    int ind = 0;
    for (State* q1 : aut) {
        State* q2 = pi[q1->name];
        if (!new_aut.contains(q2->name)) {
            q2->index = ind;
            ind++;
            new_aut.states.push_back(q2);
            std::vector<State*> d_row;
            for (int s = 0; s < f[0].size(); s++) {
                d_row.push_back(pi[delta[q1->name][s]->name]);
            }
            new_aut.delta.push_back(d_row);
            new_aut.f.push_back(f[q1->name]);
        }
        else {
            if (q1->is_starting) {
                q2->is_starting = true;
            }
        }
    }
    return new_aut;
}

int c = 0;
Aut ans;

void dfs(State* cur) {
    cur->ans_name = c;
    cur->color = 1;
    c++;
    for (int i = 0; i < ans.delta[0].size(); i++) {
        if (ans.delta[cur->index][i]->color == 0) {
            dfs(ans.delta[cur->index][i]);
        }
    }
    cur->color = 2;
}


int main() {
    int t;
    std::cin >> t;
    int n;
    std::cin >> n;
    for (int i = 0; i < t; i++) {
        State* st = new State(i);
        aut.push_back(st);
    }
    std::cin >> q;
    aut[q]->is_starting = true;
    for (int i = 0; i < t; i++) {
        std::vector<State*> row;
        for (int k = 0; k < n; k++) {
            int s;
            std::cin >> s;
            row.push_back(aut[s]);
        }
        delta.push_back(row);
    }
    for (int i = 0; i < t; i++) {
        std::vector<std::string> row;
        for (int k = 0; k < n; k++) {
            std::string s;
            std::cin >> s;
            row.push_back(s);
        }
        f.push_back(row);
    }
    ans = Minimize();
    for (State* st : ans.states) {
        if (st->is_starting) {
            dfs(st);
            break;
        }
    }
    std::cout << "digraph {\n\trankdir = LR\n";
    for (int k = 0; k < ans.states.size(); k++) {
        for (int i = 0; i < n; i++) {
            std::string st = ans.f[k][i];
            std::cout << "\t" << ans.states[k]->ans_name << " -> " << 
            ans.delta[k][i]->ans_name << " [label = \"" 
            << (char)(97 + i) << "(" << st << ")\"]\n";
        }
    }
    std::cout << "}";
}