#include"coordenada.hpp"
#include<SFML/Graphics.hpp>
#ifndef PACMAN_H
#define PACMAN_H
#include"personagem.hpp"
class Pacman: public Personagem{
    public:
        void drawPacman(sf::RenderWindow&);
        void update();
};

#endif