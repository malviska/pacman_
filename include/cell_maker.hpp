#include<SFML/Graphics.hpp>
#include"globals.hpp"
#include"coordenada.hpp"
#include"pacman.hpp"
#ifndef CELLMAKER_H
#define CELLMAKER_H

class CellMaker
{
    public:
        CellMaker();
        std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> make(const std::array<std::string, MAP_HEIGHT>&, std::array<Coordenada, 4>&, Pacman&);

};


#endif