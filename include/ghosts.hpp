#include"character.hpp"
#include"coordinate.hpp"
#include"collision.hpp"
#include<array>
#ifndef GHOST_H
#define GHOST_H

class Ghost : public Character{
    private:
        bool isFrightened = false;

    public:
        Ghost();

        void update();

        void setIsFrightened();
        bool getIsFrightened();

        virtual void move(Mapa* map) override;
        virtual void comer(Mapa* map) override;
        virtual void setDirection(short dir) override;
};

#endif