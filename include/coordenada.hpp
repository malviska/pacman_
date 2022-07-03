#ifndef COORDENADA_H
#define COORDENADA_H

struct Coordenada
{
    short x;
    short y;

    bool operator==(const Coordenada& _coord)
    {
        return this->x == _coord.x && this->y == _coord.y;
    }
};

#endif
