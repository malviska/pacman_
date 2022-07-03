#ifndef COORDENADA_H
#define COORDENADA_H

struct coordenada
{
    short x;
    short y;

    bool operator==(const coordenada& _coord)
    {
        return this->x == _coord.x && this->y == _coord.y;
    }
};

#endif
