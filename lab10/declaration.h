#include <vector>
#include <iterator>

class pair {
    public:
        int a;
        int b;
        pair(int, int);
        bool operator==(pair&);
};

class posl: public std::iterator<std::forward_iterator_tag, int>
{
    public:
        std::vector<int> numbers;
        posl(std::vector<int>);
        posl& operator++();
        pair* operator*();
        posl& begin();
        posl& end();
        bool operator!=(posl&);
        bool operator==(posl&);
        int i = 0;
        int j = 1;
};