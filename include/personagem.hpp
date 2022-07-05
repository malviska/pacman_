#ifndef PERSONAGEM_H
#define PERSONAGEM_H
#include"coordenada.hpp"


class Personagem{
    private:
        short direction;
        short speed = 1;
        Coordenada coord;
    public:
        void move(short direction);
        void set_coord(short x, short y);
        short getX();
        short getY();
        void set_direction(short);

};

#endif