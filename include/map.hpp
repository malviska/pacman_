#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <fstream>
#include <string>
#include "pacman.hpp"

using Mapa = std::vector<std::vector<Object*>>;

class Map{
    private:
    public:
        Mapa ler_mapa(std::ifstream& file, Pacman& pac);
};


#endif