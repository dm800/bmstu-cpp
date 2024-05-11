#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>

class Node {
    public:
        Node* parent;
        int x;
        int y;
        int depth;
        Node(int, int);
};

class Edge {
    public:
        Node* u;
        Node* v;
        double dist;
        int index;
        Edge() {};
        Edge(Node*, Node*);
};

Edge::Edge(Node* u, Node* v) {
    this->u = u;
    this->v = v;
    this->dist = pow(pow((u->x - v->x), 2) + pow((u->y - v->y), 2), 0.5);
}

Node::Node(int x, int y) {
    this->x = x;
    this->y = y;
    this->parent = this;
    this->depth = 0;
}


Node* Find(Node* x) {
    Node* root;
    if (x->parent == x) {
        root = x;
    }
    else {
        x->parent = Find(x->parent);
        root = x->parent;
    }
    return root;
}

void Union(Node* x, Node* y) {
    Node* root_x = Find(x);
    Node* root_y = Find(y);
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

float compare(float a, float b) {
    return b - a;
}

template<typename T>
void swap(T arr, int a, int b) {
    auto temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}


void Heapify(int i, int n, Edge** edges) {
    while (true) {
        int l = 2 * i + 1;
        int r = l + 1;
        int j = i;
        if (l < n && (compare(edges[i]->dist, edges[l]->dist) > 0)) {
            i = l;
        }
        if (r < n && (compare(edges[i]->dist, edges[r]->dist) > 0)) {
            i = r;
        }
        if (i == j) {
            break;
        }
        swap(edges, i, j);
    }
}

void BuildHeap(Edge** edges, int n) {
    int i = n / 2 - 1;
    while (i >= 0) {
        Heapify(i, n, edges);
        i -= 1;
    }
}

void HeapSort(Edge** edges, int n) {
    BuildHeap(edges, n);
    int i = n - 1;
    while (i > 0) {
        swap(edges, 0, i);
        Heapify(0, i, edges);
        i--;
    }
}

std::vector<Edge*> SpanningTree(std::vector<Node*> graph, Edge** edges, int n) {
    std::vector<Edge*> ans;
    int i = 0;
    while ((i < n) && (ans.size() < graph.size() - 1)) {
        Edge cur = *edges[i];
        if (Find(cur.u) != Find(cur.v)) {
            ans.push_back(edges[i]);
            Union(cur.u, cur.v);
        }
        i++;
    }
    return ans;
}


int main() {
    std::vector<Node*> graph;
    int t;
    std::cin >> t;
    Edge** q = new Edge*[(t - 1) * t / 2];
    for (int i = 0; i < t; i++) {
        int x, y;
        std::cin >> x >> y;
        graph.push_back(new Node(x, y));
    }
    int s = 0;
    for (int i = 0; i < t; i++) {
        for (int k = i + 1; k < t; k++) {
            q[s] = new Edge(graph[i], graph[k]);
            s++;
        }
    }
    HeapSort(q, t * (t - 1) / 2);
    std::vector<Edge*> ans = SpanningTree(graph, q, t * (t - 1) / 2);
    double sum = 0;
    for (int i = 0; i < ans.size(); i++) {
        sum += ans[i]->dist;
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(2) << sum << std::endl;
}