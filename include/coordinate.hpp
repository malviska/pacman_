#ifndef COORDINATE_H
#define COORDINATE_H
#include<utility>

class Coordinate{
    private:
        int x;
        int y;

    public:
        std::pair<int,int> getPair();

        Coordinate();

        int get_X();
        int get_Y();
        
        void set_X(int _x);
        void set_Y(int _y);
};

#endif