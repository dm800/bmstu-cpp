#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Tree {
    Tree* parent;
    char own;
    std::vector<Tree*> next;
    void add(string);
    bool check(string);
    int is_presented = 0;
    /*
    1 - presented
    0 - not presented
    */
};

struct State {
    string last = "";
    int name;
    int d_x;
    int d_y;
    char f_x;
    char f_y;
    Tree* own_tree = NULL;
};

vector<State*> aut = *new vector<State*>;
Tree* tree = new Tree();

void Tree::add(string st) {
    if (st.size() == 0) {
        this->is_presented = 1;
        return;
    }
    char cur = st.at(0);
    for (Tree* tree : next) {
        if (tree->own == cur) {
                st.erase(st.begin());
                tree->add(st);
            return;
        }
    }
    Tree* n_tree = new Tree();
    n_tree->parent = this;
    n_tree->own = cur;
    this->next.push_back(n_tree);
    st.erase(st.begin());
    n_tree->add(st);
}

bool Tree::check(string st) {
    if (st.size() == 0 && is_presented == 1) {
        return true;
    }
    else if (st.size() == 0) {
        return false;
    }
    char cur = st.at(0);
    for (Tree* tree : next) {
        if (tree->own == cur) {
            st.erase(st.begin());
            return tree->check(st);
        }
    }
    return false;
}

void printer(Tree* tree, string cur) {
    if (tree->is_presented == 1) {
        std::cout << cur << " ";
    }
    for (Tree* nex : tree->next) {
        printer(nex, cur + nex->own);
    }
}

void dfs(State* state, int depth, string str, int m) {
    if (str.size() > m || (state->own_tree->check(str))) {
        return;
    }
    state->own_tree->add(str);
    if (str.size() != 0) {
        tree->add(str);
    }
    // Для сигнала x
    State* new_x = aut[state->d_x];
    char n_char = state->f_x;
    if (n_char == '-') {
        dfs(new_x, depth + 1, str, m);
    }
    else {
        dfs(new_x, depth + 1, str + n_char, m);
    }
    // Для сигнала y
    State* new_y = aut[state->d_y];
    n_char = state->f_y;
    if (n_char == '-') {
        dfs(new_y, depth + 1, str, m);
    }
    else {
        dfs(new_y, depth + 1, str + n_char, m);
    }
}

int main() {
    tree->parent = NULL;
    tree->own = ' ';
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        State* state = new State();
        state->own_tree = new Tree();
        state->own_tree->own = ' ';
        state->own_tree->parent = NULL;
        state->name = i;
        int x;
        int y;
        std::cin >> x;
        std::cin >> y;
        state->d_x = x;
        state->d_y = y;
        aut.push_back(state);
    }
    for (int i = 0; i < t; i++) {
        char x;
        char y;
        std::cin >> x;
        std::cin >> y;
        aut[i]->f_x = x;
        aut[i]->f_y = y;
    }
    int q;
    int m;
    std::cin >> q;
    std::cin >> m;
    dfs(aut[q], 0, "", m);
    printer(tree, "");
}