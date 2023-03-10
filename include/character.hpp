#ifndef CHARACTER_H
#define CHARACTER_H

#include "coordinate.hpp"
#include "food.hpp"
#include <vector>

using Mapa = std::vector<std::vector<Object*>>; 

class Character{
    protected:
        Coordinate coord_init; //coordinate aonde o pacman começa, será util quando ele morrer
        Coordinate coord_atual; //coordinate atual, usada no movimento do pacman

        short direction = 0;

    public:
        virtual ~Character();

        int get_X();
        int get_Y();

        void set_X(int _x);
        void set_Y(int _y);

        int get_X_init();
        int get_Y_init();

        void set_X_init(int _x);
        void set_Y_init(int _y);

        //virtual void reviver()=0;
        virtual void move(Mapa* map)=0;

        virtual void setDirection(short dir) = 0;
        int getDirection();
};

#endif