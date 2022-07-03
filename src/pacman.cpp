#include"../include/pacman.hpp"

void Pacman::set_coord(short _x, short _y){
    this->coord.x = _x;
    this->coord.y = _y;
}

int Pacman::getX(){
    return this->coord.x;
}
int Pacman::getY(){
    return this->coord.y;
}