#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "pacman.hpp"
#include "ghosts.hpp"

using Mapa = std::vector<std::vector<Object*>>;

class Map{
    private:

    public:
        Mapa ler_mapa(std::ifstream&, Pacman&, Ghost&, Ghost&, Ghost&, Ghost&);
};

#endif