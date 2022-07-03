#ifndef PERSONAGEM_H
#define PERSONAGEM_H
#include"coordenada.hpp"


class Personagem{
    private:
        short direction;
        short speed = 1;
        Coordenada coord;
    public:
        void move();
        void set_coord(short, short);
        short getX();
        short getY();
        void set_direction(short);

};

#endif