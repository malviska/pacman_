#include<SFML/Graphics.hpp>
#include"globals.hpp"

#ifndef MAPA_H
#define MAPA_H
class Mapa{
    public:
        Mapa();
        void make(const std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& i_map, sf::RenderWindow& i_window);
};


#endif
