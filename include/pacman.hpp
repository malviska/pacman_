#ifndef PACMAN_H
#define PACMAN_H

#include "personagem.hpp"
#include <string>
#include <ctime>

class Pacman : public Personagem{
    private:
        unsigned score = 0;
        short lifes = 3;
        bool invencibility = false;
        clock_t invencibilityTimer;
    public:
        Pacman();
        //virtual void reviver() override;
        virtual void mover(Mapa* map) override;
        virtual void comer(Mapa* map) override;
        void lose_life();
        short get_lifes();
        unsigned get_score();
        virtual void setDirection(short dir) override;
        void setInvencibility();
        void timeInvencibility();
        bool getInvencibility();
        void sumScore();
        void unsetInvensibility();
};

#endif