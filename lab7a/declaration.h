class Point {
    private:
        int x, y;
    public:
        Point() {
            this->x = 0;
            this->y = 0;
        };
        Point(int, int);
        Point* copy();
        int get_x();
        //virtual ~Point();
};

class Line {
    private:
        Point** set;
        int count = 0;
        int size = 10;
    public:
        int getcount();
        Point** getset();
        Point* at(int);
        void add(Point*);
        Line concat(Line*);
        Line form(int, int);
        void extend();
        Line();
        virtual ~Line();
};