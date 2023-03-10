#include "../include/ghost.hpp"
#include <cstdlib>

Ghost::Ghost(){
    this->isFrightened = false;
    this->direction = 0;
}

void Ghost::move(Mapa* map){
    /*
        função responsável pela movimentação do pacman
        recebe a direção e o rascunho do mapa do jogo
    */
    std::pair<int,int> useDoor = {10,10};

    if(this->coord_atual.get_pair() == useDoor){
        this->direction = 1;
    }

    std::array<bool,4> walls{};

    walls[0] = map_collision(1, GHOST_SPEED + this->get_X(), this->get_Y(), *map);
	walls[1] = map_collision(1, this->get_X(), this->get_Y() - GHOST_SPEED, *map);
	walls[2] = map_collision(1, this->get_X() - GHOST_SPEED, this->get_Y(), *map);
	walls[3] = map_collision(1, this->get_X(), GHOST_SPEED + this->get_Y(), *map);

    if (0 == walls[direction]) {
        switch (direction) {
            case 0: {
                this->set_X(GHOST_SPEED + this->get_X());
                break;
            }

            case 1: {
                this->set_Y(this->get_Y() - GHOST_SPEED);
                break;
            }

            case 2: {
                this->set_X(this->get_X() - GHOST_SPEED);
                break;
            }

            case 3: {
                this->set_Y(this->get_Y() + GHOST_SPEED);
                break;
            }
        }

        if (this->get_X()<0) {
            this->set_X(MAP_WIDTH - 1);

        } else if (MAP_WIDTH <= this->get_X()){
            this->set_X(0);

        }
    } else {
        this->direction = rand() %4;
        
    }
}


void Ghost::setDirection(short dir){
    this->direction = dir;
}

bool Ghost::getIsFrightened(){
    return this->isFrightened;
}

void Ghost::setIsFrightened(){
    this->isFrightened = !(this->isFrightened);
}