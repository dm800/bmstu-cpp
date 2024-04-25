#include <iostream>
#include "implementation.cpp"


int main() {
    InterSet set = *new InterSet();
    InterSet set2 = *new InterSet();
    Inter* a1 = new Inter(1, 5);
    Inter* a2 = new Inter(5, 10);
    set.add(a1);
    set2.add(a2);
    set.concat(&set2);
    InterSet set3 = set.copy();
    std::cout << set3.Internumber() << "\n";
    std::cout << set3.contains(2) << " " <<  set3.contains(7) << "\n";
}