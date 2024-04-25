class Inter {
    public:
        int a, b;
        Inter() {
            this->a = 0;
            this->b = 0;
        };
        Inter(int, int);
        Inter* copy();
        //virtual ~Inter();
};

class InterSet {
    private:
        int size;
        int count;
        Inter** set;
    public:
        InterSet();
        Inter** retset();
        void add(Inter*);
        InterSet copy();
        void extend();
        InterSet operator = (InterSet);
        int Internumber();
        Inter* at(int);
        void concat(InterSet*);
        bool contains(int x);
        virtual ~InterSet();
};