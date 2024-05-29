#include <vector>
#include <iterator>

class Point {
    public:
        int x;
        int y;
        bool operator==(Point&);
        Point(int, int);
};

class Rect
{
    public:
        std::vector<Point> nodes;
        std::vector<int> lens;
        Rect(std::vector<Point>);
        std::vector<int>::const_iterator begin();
        std::vector<int>::const_iterator end();
};