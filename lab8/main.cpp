#include <iostream>
#include "implementation.cpp"

int main() {
    List<int>* list = new List(10);
    std::cout << list->start->elem << "\n";
    list->add(20);
    bool k = list->findval(20);
    if (!k) {
        std::cout << "None\n";
    }
    else {
        std::cout << "Find one\n";
    }
    list->del(20);
    bool t = list->findval(20);
    if (!t) {
        std::cout << "None\n";
    }
    else {
        std::cout << "Find one\n";
    }
    list->add(15);
    std::cout << list->sum();
}