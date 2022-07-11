#ifndef COORDENADA_H
#define COORDENADA_H
#include<utility>

class Coordenada{
    private:
        int x;
        int y;

    public:
        std::pair<int,int> getPair();

        Coordenada();

        int get_X();
        int get_Y();
        
        void set_X(int _x);
        void set_Y(int _y);
};

#endif