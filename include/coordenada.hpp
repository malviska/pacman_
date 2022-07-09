#ifndef COORDENADA_H
#define COORDENADA_H

class Coordenada{
    private:
        int x;
        int y;
    public:
        Coordenada();
        int get_X();
        int get_Y();
        void set_X(int _x);
        void set_Y(int _y);
};


#endif