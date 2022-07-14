#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "pacman.hpp"
#include "ghost.hpp"

using Mapa = std::vector<std::vector<Object*>>;

class Map{
    public:
        Mapa ler_mapa(std::ifstream&, Pacman&, Ghost&, Ghost&, Ghost&, Ghost&);
};

#endif