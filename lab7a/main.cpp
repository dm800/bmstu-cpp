#include <iostream>
#include "implementation.cpp"


int main() {
    Line line1 = *new Line();
    Line line2 = *new Line();
    Point* p1 = new Point(1, 2);
    Point* p2 = new Point(3, 4);
    Point* p3 = new Point(5, 6);
    Point* p4 = new Point(7, 8);
    line1.add(p1);
    line1.add(p2);
    line2.add(p3);
    line2.add(p4);
    Line line3 = line1.concat(&line2);
    std::cout << line3.at(0)->get_x() << "\n";
    std::cout << line3.at(1)->get_x() << "\n";
    std::cout << line3.at(2)->get_x() << "\n";
    std::cout << line3.at(3)->get_x() << "\n";
    Line line4 = line3.form(1, 3);
    std::cout << line4.at(0)->get_x() << "\n";
    std::cout << line4.at(1)->get_x() << "\n";
}