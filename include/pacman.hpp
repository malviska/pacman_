#ifndef PACMAN_H
#define PACMAN_H

#include "character.hpp"
#include <string>
#include <ctime>

class Pacman : public Character{
    private:
        unsigned score = 0;
        short lifes = 3;
        bool invencibility = false;

        clock_t invencibilityTimer = clock();

    public:
        Pacman();
        //virtual void reviver() override;
        virtual void move(Mapa* map) override;
        virtual void comer(Mapa* map) override;

        void lose_life();
        short get_lifes();

        virtual void setDirection(short dir) override;
        
        void setInvencibility();
        void timeInvencibility();
        bool getInvencibility();
        void unsetInvensibility();

        unsigned get_score();
        void sumScore();
};

#endif