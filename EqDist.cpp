#include <iostream>
#include <vector>
#define INF 2147483647

struct Node {
    public:
        Node(int);
        std::vector<int> edges;
        int dist;
        int index;
        int name;
};

Node::Node(int name) {
    this->name = name;
}

struct Heap {
    public:
        std::vector<Node*> heap;
        int compare(int a, int b) {
            return a - b;
        }
        int count = 0;
        void heapify(int i, int n);
        Heap(std::vector<Node*>);
        void add(Node*);
        Node* remove();
        Node* peek();
        void change_key(Node*, int);
};

void Heap::add(Node* elem) {
    int i = this->count;
    this->count += 1;
    this->heap.push_back(elem);
    while ((i > 0) && (compare(this->heap[(i - 1) / 2]->dist, this->heap[i]->dist) > 0)) {
        std::iter_swap(this->heap.begin() + (i - 1) / 2, this->heap.begin() + i);
        this->heap[i]->index = i;
        i = (i - 1) / 2;
    }
    this->heap[i]->index = i;
}

Heap::Heap(std::vector<Node*> graph) {
    for (Node* cur : graph) {
        this->add(cur);
    }
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
        if (l < n && (compare(this->heap[i]->dist, this->heap[l]->dist) > 0)) {
            i = l;
        }
        if (r < n && (compare(this->heap[i]->dist, this->heap[r]->dist) > 0)) {
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
    node->dist = val;
    while ((i > 0) && (compare(this->heap[(i - 1) / 2]->dist, val) > 0)) {
         std::iter_swap(this->heap.begin() + (i - 1) / 2, this->heap.begin() + i);
         this->heap[i]->index = i;
         i = (i - 1) / 2;
    }
    node->index = i;

}

std::ostream& operator<<(std::ostream& os, const Node& node) {
    os << "Node " << node.index << "\n";
    for (int edge : node.edges) {
        os << edge << " ";
    }
    os << "\n";
    return os;
}

int* calculate(int main, std::vector<Node*> graph) {
    int* answer = new int[graph.size()];
    for (Node* cur : graph) {
        if (cur->name == main) {
            cur->dist = 0;
        }
        else {
            cur->dist = INF;
        }
    }
    Heap queue = *new Heap(graph);
    Node* cur = queue.peek();
    std::vector<int> removed(graph.size(), 0);
    while (queue.count != 0 && cur->dist != INF) {
        for (int node : cur->edges) {
            if ((removed[cur->name] != 1) && (graph[node]->dist > cur->dist + 1)) {
                queue.change_key(graph[node], cur->dist + 1);
            }
        }
        queue.remove();
        removed[cur->name] = 1;
        cur = queue.peek();
    }
    for (Node* node : graph) {
        answer[node->name] = node->dist;
    }
    return answer;
}


int main() {
    int k;
    int m;
    std::cin >> k;
    std::cin >> m;
    std::vector<Node*> graph;
    std::vector<int> available;
    for (int i = 0; i < k; i++) {
        graph.push_back(new Node(i));
        available.push_back(INF);
    }
    for (int t = 0; t < m; t++) {
        int u;
        int v;
        std::cin >> u;
        std::cin >> v;
        graph[u]->edges.push_back(v);
        graph[v]->edges.push_back(u);
    }
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int main;
        std::cin >> main;
        int* sp = calculate(main, graph);
        for (int i = 0; i < k; i++) {
            if (sp[i] == INF) {
                available[i] = -1;
            }
            else if (available[i] == INF) {
                available[i] = sp[i];
            }
            else if (available[i] != sp[i]) {
                available[i] = -1;
            }
        }
    }
    int c = 0;
    for (int i = 0; i < available.size(); i++) {
        if (available[i] != -1 && available[i] != INF) {
            std::cout << i << " ";
            c += 1;
        }
    }
    if (c == 0) {
        std::cout << "-";
    }
    std::cout << std::endl;
}

/*
Предыстория этой задачи:

Изначально эта задача была решена на Java, но она тупо не проходила по времени. Почему? Потому что использовалась не очередь с приоритетами, 
а самая обычная очередь, которая вообще не успевала по времени. В попытках исправить этот недочёт (используя встроенный класс PriorityQueue), 
мною было обнаружено, что в нём просто напросто нет функции Change_Key, вообще ни в каком варианте. Соответственно, мне пришлось писать свою
пирамиду. Но, из-за отсуствия как таковых возможностей работы с указателями на объекты (они в Java работают очень негибко), было принято решение
сменить язык. И вот, в 3 часа ночи, я переписал задачу с Java на C++. Убейте меня кто-нибудь.
*/