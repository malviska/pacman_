#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "coordenada.hpp"
#include "food.hpp"
#include <vector>

using Mapa = std::vector<std::vector<Object*>>;

class Personagem{
    protected:
        Coordenada coord_init;
        Coordenada coord_atual;

    public:
        virtual ~Personagem();
        int get_X();
        int get_Y();
        void set_X(int _x);
        void set_Y(int _y);
        int get_X_init();
        int get_Y_init();
        void set_X_init(int _x);
        void set_Y_init(int _y);
        //virtual void reviver()=0;
        virtual void mover(short move, Mapa* map)=0;
        virtual void comer(Mapa* map)=0;
};


#endif