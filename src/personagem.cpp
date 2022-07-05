#include"personagem.hpp"

#include <iostream>

void Personagem::move(short direction){
    switch (direction)
    {
    case 1:
        this->coord.y -= speed;
        break;
    case 3:
        this->coord.y += speed;
        break;
    case 0:
        this->coord.x -= speed;
        break;
    case 2:
        this->coord.x += speed;
        break;
    default:
        break;
    }
}

void Personagem::set_coord(short _x, short _y){
    this->coord.x = _x;
    this->coord.y = _y;
}

short Personagem::getX(){
    return this->coord.x;
}
short Personagem::getY(){
    return this->coord.y;
}
void Personagem::set_direction(short dir){
    this->direction = dir;
}
