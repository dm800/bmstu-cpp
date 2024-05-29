#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <math.h>
#define INF 2147483647
#define LINF 18446744073709551615

struct Edge;

struct Node {
    public:
        Node(std::string, int, int);
        std::vector<Node*> neighbors;
        void add(Node*);
        int value;
        int path;
        int state;
        /*
        state = 0 - белый
        state = 1 - серый
        state = 2 - чёрный
        */
        int index;
        std::string name;
        std::string color;
        std::vector<Node*> prev;
};

Node::Node(std::string name, int val, int ind) {
    this->name = name;
    this->value = val;
    this->path = 0;
    this->state = 0;
    this->color = "";
    this->index = ind;
}

void Node::add(Node* neigh) {
    this->neighbors.push_back(neigh);
}

std::vector<bool> cycled;
int counter = 0;

std::string remove_spaces(std::string a) {
    std::string removed;
    for (char ch : a) {
        if ((ch != ' ') && (ch != '\n') && (ch != '\t')) {
            removed.push_back(ch);
        }
    }
    return removed;
}

int find_time(std::string a) {
    int val = -1;
    if (a[a.size() - 1] == ')') {
        int i = 2;
        val++;
        while (isdigit(a[a.size() - i])) {
            val += (a[a.size() - i] - 48) * pow(10, i - 2);
            i++;
        }
    }
    return val;
}

Node* find_node(std::vector<Node*> graph, std::string name) {
    for (Node* node : graph) {
        if (node->name == name) {
            return node;
        }
    }
    return NULL;
}

std::vector<Node*> adjust_graph(std::string a, std::vector<Node*> graph, std::vector<Node*>* queue) {
    std::string ans = remove_spaces(a);
    std::string word;
    Node* prev = NULL;
    int iter = 0;
    int end = ans.find('<');
    while (end != -1) {
        word = ans.substr(0, end);
        ans.erase(ans.begin(), ans.begin() + end + 1);
        iter++;
        int time = find_time(word);
        if (time >= 0) {
            Node* task = new Node(word.substr(0, word.find('(')), time, counter);
            cycled.push_back(false);
            counter++;
            if (iter == 1) {
                queue->push_back(task);
            }
            graph.push_back(task);
            if (prev != NULL) {
                prev->add(task);
            }
            prev = task;
        }
        else {
            Node* task = find_node(graph, word);
            if (iter != 1) {
                int k = -1;
                bool fl = false;
                for (int i = 0; i < queue->size(); i++) {
                    if ((*queue)[i] == task) {
                        k = i;
                        break;
                    }
                }
                if (k != -1) {
                    queue->erase(queue->begin() + k);
                }
            }
            if (prev != NULL) {
                prev->add(task);
            }
            prev = task;
        }
        end = ans.find('<');
    }
    word = ans.substr(0, end);
    ans.erase(ans.begin(), ans.begin() + end + 1);
    iter++;
    int time = find_time(word);
    if (time >= 0) {
        Node* task = new Node(word.substr(0, word.find('(')), time, counter);
        cycled.push_back(false);
        counter++;
        if (iter == 1) {
            queue->push_back(task);
        }
        graph.push_back(task);
        if (prev != NULL) {
            prev->add(task);
        }
        prev = task;
    }
    else {
        Node* task = find_node(graph, word);
        if (prev != NULL) {
            prev->add(task);
        }
        prev = task;
    }
    if (queue->size() == 0) {
        queue->push_back(graph[0]);
    }
    return graph;
}

bool in_cycle(Node* node) {
    return cycled[node->index];
}

void cycle(Node* node) {
    cycled[node->index] = true;
    for (Node* neigh : node->neighbors) {
        if (cycled[neigh->index] == false) {
            cycle(neigh);
        }
    }
}

void dfs(Node* node, int path) {
    node->path = path + node->value;
    node->state = 1;
    for (Node* neigh : node->neighbors) {
        if (in_cycle(neigh)) {
            continue;
        }
        if (neigh->state == 1) {
            cycle(neigh);
        }
        if (neigh->path < node->path + neigh->value) {
            neigh->prev.clear();
            neigh->prev.push_back(node);
            dfs(neigh, node->path);
        }
        else if (neigh->path == node->path + neigh->value) {
            neigh->prev.push_back(node);
        }
    }
    node->state = 2;
}

void paint_red(Node* node) {
    node->color = "red";
    for (Node* neigh : node->prev) {
        paint_red(neigh);
    }
}

void calculate(std::vector<Node*> graph, std::vector<Node*> queue) {
    for (Node* starter : queue) {
        dfs(starter, 0);
        for (Node* node : graph) {
            node->state = 0;
        }
    }
    std::vector<Node*> maxes;
    int cur = 0;
    for (Node* can_be : graph) {
        if (!cycled[can_be->index]) {
            if (cur < can_be->path) {
                cur = can_be->path;
                maxes.clear();
                maxes.push_back(can_be);
            }
            else if (cur == can_be->path) {
                maxes.push_back(can_be);
            }
        }
        else {
            can_be->color = "blue";
        }
    }
    for (Node* node : maxes) {
        paint_red(node);
    }
}

int main() {
    std::string k;
    std::vector<Node*> graph;
    std::vector<Node*> queue;
    while (std::getline(std::cin, k, ';')) {
        graph = adjust_graph(k, graph, &queue);
    }
    calculate(graph, queue);
    std::cout << "digraph {\n";
    for (Node* node : graph) {
        std::cout << "\t" << node->name << " [label = \"" << node->name << "(" << node->value << ")\"";
        if (node->color != "") {
            std::cout << ", color = " << node->color;
        }
        std::cout << "]\n";
    }
    for (Node* node : graph) {
        for (Node* neigh : node->neighbors) {
            std::cout << "\t" << node->name << " -> " << neigh->name;
            if ((neigh->color == node->color) && (node->color != "")) {
                if ((find_node(neigh->prev, node->name) != NULL) && node->color == "red") {
                    std::cout << " [color = red]";
                }
                else if (node->color == "blue") {
                    std::cout << " [color = blue]";
                }
            }
            std::cout << "\n";
        }
    }
    std::cout << "}";
}