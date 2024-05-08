#include "declaration.h"

template<typename T>
Elem<T>::Elem(T val) {
    this->elem = val;
    this->next = this;
    this->prev = this;
}


template<typename T>
List<T>::List(T val) {
    Elem<T>* elem = new Elem(val);
    this->start = elem;
}

template<typename T>
void List<T>::add(T val) {
    Elem<T>* newel = new Elem(val);
    Elem<T>* cur = this->start;
    while (cur->next != start) {
        cur = cur->next;
    }
    cur->next = newel;
    newel->prev = cur;
    newel->next = start;
    start->prev = newel;
}

template<typename T>
void List<T>::insert(int index, T val) {
    Elem<T>* newel = new Elem(val);
    if (index == 0) {
        this->start = newel;
    }
    Elem<T>* cur = this->start;
    while (index != 0) {
        index--;
        cur = cur->next;
    }
    Elem<T>* prev = cur->prev;
    prev->next = newel;
    newel->prev = prev;
    newel->next = cur;
    cur->prev = newel;
}

template<typename T>
bool List<T>::findval(T val) {
    Elem<T>* cur = this->start;
    while (cur->elem != val && cur->next != start) {
        cur = cur->next;
    }
    if (cur->elem == val) {
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
void List<T>::del(T val) {
    Elem<T>* cur = this->start;
    int c = 0;
    while (cur->next != start && cur->elem != val) {
        cur = cur->next;
        c++;
    }
    if (c == 0) {
        this->start = start->next;
    }
    Elem<T>* prev = cur->prev;
    prev->next = cur->next;
    cur->next->prev = prev;
    delete cur;
}

List<int>::List(int val) {
    Elem<int>* elem = new Elem(val);
    this->start = elem;
}

void List<int>::add(int val) {
    Elem<int>* newel = new Elem(val);
    Elem<int>* cur = this->start;
    while (cur->next != start) {
        cur = cur->next;
    }
    cur->next = newel;
    newel->prev = cur;
    newel->next = start;
    start->prev = newel;
}

void List<int>::insert(int index, int val) {
    Elem<int>* newel = new Elem(val);
    if (index == 0) {
        this->start = newel;
    }
    Elem<int>* cur = this->start;
    while (index != 0) {
        index--;
        cur = cur->next;
    }
    Elem<int>* prev = cur->prev;
    prev->next = newel;
    newel->prev = prev;
    newel->next = cur;
    cur->prev = newel;
}

bool List<int>::findval(int val) {
    Elem<int>* cur = this->start;
    while (cur->elem != val && cur->next != start) {
        cur = cur->next;
    }
    if (cur->elem == val) {
        return true;
    }
    else {
        return false;
    }
}

void List<int>::del(int val) {
    Elem<int>* cur = this->start;
    int c = 0;
    while (cur->next != start && cur->elem != val) {
        cur = cur->next;
        c++;
    }
    if (c == 0) {
        this->start = start->next;
    }
    Elem<int>* prev = cur->prev;
    prev->next = cur->next;
    cur->next->prev = prev;
    delete cur;
}

int List<int>::sum() {
    int s = 0;
    Elem<int>* cur = this->start;
    while (cur->next != this->start) {
        s += cur->elem;
        cur = cur->next;
    }
    s += cur->elem;
    return s;
}