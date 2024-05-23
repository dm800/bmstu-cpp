#include <iostream>
#include <vector>
#define INF 2147483647

class Edge;

class Node {
    public:
        Node(int);
        std::vector<Edge*> edges;
        int key;
        Node* value;
        int index;
        int name;
};

class Edge {
    public:
        Edge(Node*, int);
        Node* dest;
        int val;
};

Node::Node(int name) {
    this->name = name;
    this->key = 0;
}

Edge::Edge(Node* dest, int val) {
    this->dest = dest;
    this->val = val;
}

struct Heap {
    public:
        std::vector<Node*> heap;
        int compare(Node* a, Node* b) {
            return a->key - b->key;
        }
        int count = 0;
        void heapify(int i, int n);
        Heap();
        void add(Node*);
        void change_key(Node*, int);
        Node* remove();
        Node* peek();
};

void Heap::add(Node* elem) {
    int i = this->count;
    this->count += 1;
    this->heap.push_back(elem);
    while ((i > 0) && (compare(this->heap[(i - 1) / 2], this->heap[i]) > 0)) {
        std::iter_swap(this->heap.begin() + (i - 1) / 2, this->heap.begin() + i);
        this->heap[i]->index = i;
        i = (i - 1) / 2;
    }
    this->heap[i]->index = i;
}

Heap::Heap() {
    this->count = 0;
}

Node* Heap::peek() {
    return this->heap[0];
}

Node* Heap::remove() {
    Node* ans = this->heap[0];
    this->count -= 1;
    this->heap.pop_back();
    if (this->count > 0) {
        this->heap[0] = this->heap[this->count];
        this->heap[0]->index = 0;
        heapify(0, this->count);
    }
    return ans;
}

void Heap::heapify(int i, int n) {
    while (true) {
        int l = 2 * i + 1;
        int r = l + 1;
        int j = i;
        if (l < n && (compare(this->heap[i], this->heap[l]) > 0)) {
            i = l;
        }
        if (r < n && (compare(this->heap[i], this->heap[r]) > 0)) {
            i = r;
        }
        if (i == j) {
            break;
        }
        std::iter_swap(this->heap.begin() + i, this->heap.begin() + j);
        this->heap[i]->index = i;
        this->heap[j]->index = j;
    }
}

void Heap::change_key(Node* node, int val) {
    int i = node->index;
    node->key = val;
    Node* temp = new Node(-1);
    temp->key = val;
    while ((i > 0) && (compare(this->heap[(i - 1) / 2], temp) > 0)) {
         std::iter_swap(this->heap.begin() + (i - 1) / 2, this->heap.begin() + i);
         this->heap[i]->index = i;
         i = (i - 1) / 2;
    }
    node->index = i;
}

int Prim(std::vector<Node*> graph) {
    int s = 0;
    for (Node* node : graph) {
        node->index = -1;
    }
    std::vector<Node*> ans;
    Heap* q = new Heap();
    q->add(graph[0]);
    Node* v = q->remove();
    while (true) {
        v->index = -2;
        for (Edge* edge : v->edges) {
            Node* u = edge->dest;
            if (u->index == -1) {
                u->key = edge->val;
                u->value = v;
                q->add(u);
            }
            else if (u->index != -2 && edge->val < u->key) {
                u->value = v;
                q->change_key(u, edge->val);
            }
        }
        if (q->count == 0) {
            break;
        }
        v = q->remove();
        Node* k = new Node(-1);
        k->key = v->key;
        k->value = v->value;
        ans.push_back(k);
    }
    for (Node* node : ans) {
        s += node->key;
    }
    return s;
}

int main() {
    int k;
    int m;
    std::cin >> k;
    std::cin >> m;
    std::vector<Node*> graph;
    for (int i = 0; i < k; i++) {
        graph.push_back(new Node(i));
    }
    int u, v, dist;
    for (int t = 0; t < m; t++) {
        std::cin >> u;
        std::cin >> v;
        std::cin >> dist;
        Edge* roadtov = new Edge(graph[v], dist);
        graph[u]->edges.push_back(roadtov);
        Edge* roadtou = new Edge(graph[u], dist);
        graph[v]->edges.push_back(roadtou);
    }
    int ans = Prim(graph);
    std::cout << ans;
}