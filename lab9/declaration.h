#include <vector>
#include <concepts>
#include <type_traits>


template<typename T> requires std::equality_comparable<T>
class Seq {
    public:
        std::vector<T> values;
        Seq(std::vector<T> values);
        Seq<T> operator+ (Seq<T> b);
        std::vector<Seq<T>> operator/ (int k);
        Seq<T> operator! ();
        T operator[] (int i);
};