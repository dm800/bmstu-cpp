#include "declaration.h"
#include <iostream>
#include <math.h>

Point::Point(int a, int b) {
    this->x = a;
    this->y = b;
}

bool Point::operator==(Point& other) {
    return (x == other.x && y == other.y);
}

Rect::Rect(std::vector<Point> a) {
    this->nodes = a;
    std::vector<int> lens;
    for (int i = 1; i < a.size(); i++) {
        Point p1 = nodes[i - 1];
        Point p2 = nodes[i];
        int dist = std::pow((std::pow((p2.x - p1.x), 2) + std::pow((p2.y - p1.y), 2)), 0.5);
        lens.push_back(dist);
    }
    int dist = std::pow((std::pow((nodes[a.size() - 1].x - nodes[0].x), 2) + std::pow((nodes[a.size() - 1].y - nodes[0].y), 2)), 0.5);
    lens.push_back(dist);
    this->lens = lens;
}

std::vector<int>::const_iterator Rect::begin() {
    return this->lens.begin();
}

std::vector<int>::const_iterator Rect::end() {
    return this->lens.end();
}