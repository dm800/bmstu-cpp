#include <iostream>
#include <vector>

class State {
    public:
        bool is_end;
        int name;
        std::vector<int>* edges;
        State(int);
        State();
};

State::State(int n) {
    name = n;
}

int main() {
    int m;
    std::cin >> m;
    int n;
    std::cin >> n;
    int q1;
    std::cin >> q1;
    std::vector<State*> aut1;
    for (int i = 0; i < n; i++) {
        State* state = new State(i);
        state->edges = new std::vector<int>();
        char sign;
        std::cin >> sign;
        if (sign == '+') {
            state->is_end = 1;
        }
        else {
            state->is_end = 0;
        }
        for (int k = 0; k < m; k++) {
            int p;
            std::cin >> p;
            state->edges->push_back(p);
        }
        aut1.push_back(state);
    }
    int n2;
    std::cin >> n2;
    int q2;
    std::cin >> q2;
    std::vector<State*> aut2;
    for (int i = 0; i < n2; i++) {
        State* state = new State(i);
        state->edges = new std::vector<int>();
        char sign;
        std::cin >> sign;
        if (sign == '+') {
            state->is_end = 1;
        }
        else {
            state->is_end = 0;
        }
        for (int k = 0; k < m; k++) {
            int p;
            std::cin >> p;
            state->edges->push_back(p);
        }
        aut2.push_back(state);
    }
    std::vector<std::vector<bool>> used = *new std::vector<std::vector<bool>>();
    for (int i = 0; i < n; i++) {
        std::vector<bool> row = *new std::vector<bool>(n2, false);
        used.push_back(row);
    }
    bool found = false;
    std::vector<int*> queue;
    std::vector<int*> temp_queue;
    int* pair = new int[2];
    pair[0] = q1;
    pair[1] = q2;
    queue.push_back(pair);
    used.at(q1).at(q2) = true;
    int c = 0;
    while (true) {
        int* cur = queue.front();
        queue.erase(queue.begin());
        if (aut1[cur[0]]->is_end != aut2[cur[1]]->is_end) {
            std::cout << c;
            found = true;
            break;
        }
        else {
            for (int i = 0; i < m; i++) {
                int s1 = aut1[cur[0]]->edges->at(i);
                int s2 = aut2[cur[1]]->edges->at(i);
                if (!used[s1][s2]) {
                    used[s1][s2] = true;
                    int* pair = new int[2];
                    pair[0] = s1;
                    pair[1] = s2;
                    temp_queue.push_back(pair);
                }
            }
        }
        if (queue.empty() && temp_queue.empty()) {
            break;
        }
        else if (queue.empty()) {
            c++;
            for (auto elem : temp_queue) {
                queue.push_back(elem);
            }
            temp_queue.clear();
        }
    }
    if (!found) {
        std::cout << "=";
    }
}