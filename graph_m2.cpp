#include <iostream>
#include <vector>


class Node {
    public:
        int name;
        Node(int);
        std::vector<int>* edges;
        int visited = 0;
};

Node::Node(int name) {
    this->name = name;
    this->edges = new std::vector<int>();
}

int ans = 0;
int is_cycled = 0;

void dfs(Node* cur, std::vector<Node*>* graph, std::vector<int>* weights, std::vector<int>* visited, int weight) {
    if (is_cycled || weight < weights->at(cur->name)) {
        return;
    }
    cur->visited = 1;
    visited->at(cur->name) = 1;
    weights->at(cur->name) = weight;
    if (ans < weight) {
        ans = weight;
    }
    for (int edge : *cur->edges) {
        Node* next = graph->at(edge);
        if (visited->at(next->name) == 1) {
            is_cycled = 1;
            return;
        }
        else {
            dfs(next, graph, weights, visited, weight + 1);
        }
    }
    visited->at(cur->name) = 2;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Node*>* graph = new std::vector<Node*>();
    for (int i = 0; i < n; i++) {
        Node* node = new Node(i);
        graph->push_back(node);
    }
    for (int i = 0; i < n; i++) {
        int t;
        std::cin >> t;
        for (int k = 0; k < t; k++) {
            int p;
            std::cin >> p;
            graph->at(p - 1)->edges->push_back(i);
        }
    }
    std::vector<int> weights = *new std::vector<int>(n, -1);
    std::vector<int> visited = *new std::vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        Node* cur = graph->at(i);
        if (cur->visited == 0) {
            weights = *new std::vector<int>(n, -1);
            visited = *new std::vector<int>(n, 0);
            dfs(cur, graph, &weights, &visited, 0);
        }
    }
    if (is_cycled) {
        std::cout << "cycle";
    }
    else {
        std::cout << ans + 1;
    }
}