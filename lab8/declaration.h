template<typename T>
class Elem 
{
    public:
        Elem(T);
        T elem;
        Elem* prev;
        Elem* next;
};

template<typename T>
class List
{
    public:
        List(T val);
        Elem<T>* start;
        void add(T val);
        bool findval(T val);
        void insert(int index, T val);
        void del(T val);
};

template <>
class List<int>
{
    public:
        List(int val);
        Elem<int>* start;
        void add(int val);
        bool findval(int val);
        void insert(int index, int val);
        void del(int val);
        int sum();
};