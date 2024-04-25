#include "declaration.h"
#include <iostream>

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

Point* Point::copy() {
    Point* val = new Point(this->x, this->y);
    return val;
}

Line::Line() {
    this->set = new Point* [this->size];
}

void Line::add(Point* obj) {
    if (this->count < this->size) {
        this->set[this->count] = obj->copy();
        this->count += 1;
    }
    else {
        this->extend();
        this->add(obj);
    }
}

void Line::extend() {
    Point** temp = new Point* [this->size * 2];
    for (int i = 0; i < this->size; i++) {
        temp[i] = this->set[i];
    }
    this->set = temp;
}

int Line::getcount() {
    return this->count;
}

Point** Line::getset() {
    return this->set;
}

Point* Line::at(int i) {
    return this->set[i];
}

int Point::get_x() {
    return this->x;
}

Line Line::concat(Line* obj) {
    Line answer = *new Line();
    for (int i = 0; i < this->count; i++) {
        answer.add((*(this->at(i))).copy());
    }
    for (int i = 0; i < obj->getcount(); i++) {
        answer.add((*(obj->at(i))).copy());
    }
    return answer;
}

Line Line::form(int st, int en) {
    Line answer = *new Line();
    for (int i = st; i < en; i++) {
        answer.add(this->at(i)->copy());
    }
    return answer;
}

Line::~Line() {
    delete [] set;
}

/*Point::~Point() {
    std::cout << "deleted point " << this->get_x() << "\n";
}*/