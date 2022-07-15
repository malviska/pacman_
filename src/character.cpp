#include "../include/character.hpp"

Character::~Character(){}

int Character::get_X(){
    return this->coord_atual.get_X();
}

int Character::get_Y(){
    return this->coord_atual.get_Y();
}

void Character::set_X(int _x){
    this->coord_atual.set_X(_x);
}

void Character::set_Y(int _y){
    this->coord_atual.set_Y(_y);
}

int Character::get_X_init(){
    return this->coord_init.get_X();
}

int Character::get_Y_init(){
    return this->coord_init.get_X();
}

void Character::set_X_init(int _x){
    this->coord_init.set_X(_x);
}

void Character::set_Y_init(int _x){
    this->coord_init.set_Y(_x);
}

int Character::getDirection(){
    return this->direction;
}