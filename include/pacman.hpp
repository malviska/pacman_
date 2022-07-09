#ifndef PACMAN_H
#define PACMAN_H

#include "personagem.hpp"
#include "collision.hpp"
#include <string>

class Pacman : public Personagem{
    private:
        unsigned score = 0;
        short lifes = 3;
    public:
        Pacman();
        //virtual void reviver() override;
        virtual void mover(Mapa* map) override;
        virtual void comer(Mapa* map) override;
        void lose_life();
        short get_lifes();
        unsigned get_score();
        virtual void setDirection(short dir) override;
};

#endif