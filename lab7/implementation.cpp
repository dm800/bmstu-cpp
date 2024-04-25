#include "declaration.h"
#include <iostream>

Inter::Inter(int start, int end) {
    this->a = start;
    this->b = end;
}

Inter* Inter::copy() {
    Inter* val = new Inter(this->a, this->b);
    return val;
}

InterSet::InterSet() {
    this->size = 10;
    this->set = new Inter* [size];
    this->count = 0;

}

void InterSet::add(Inter* obj) {
    if (this->count < this->size) {
        this->set[count] = obj->copy();
        this->count += 1;
    }
    else {
        this->extend();
        this->add(obj);
    }
}

int InterSet::Internumber() {
    return this->count;
}

Inter* InterSet::at(int ind) {
    return this->set[ind];
}

bool InterSet::contains(int x) {
    for (int i = 0; i < this->size;i++) {
        Inter* cur = this->at(i);
        if (cur->a < x && cur->b > x) {
            return true;
        }
    }
    return false;
}

void InterSet::concat(InterSet* obj) {
    for (int i = 0; i < obj->Internumber(); i++) {
        Inter* elem = obj->at(i)->copy();
        this->add(elem);
    }
}

Inter** InterSet::retset() {
    return this->set;
}

void InterSet::extend() {
    Inter** set = new Inter* [this->size * 2];
    for (int i = 0; i < this->size;i++) {
        set[i] = this->set[i];
    }
    this->set = set;
}

InterSet InterSet::copy() {
    InterSet *answer = new InterSet();
    for (int i = 0; i < this->count;i++) {
        answer->add(this->set[i]->copy());
    }
    return *answer;
}

InterSet::~InterSet() {
    delete [] set;
}
