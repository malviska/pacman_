#include"coordenada.hpp"
#ifndef PACMAN_H
#define PACMAN_H

class Pacman{
    private:
        coordenada coord;
    public:
        void set_coord(short, short);
        int getX();
        int getY();
};

#endif