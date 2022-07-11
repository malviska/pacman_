#include "../include/personagem.hpp"

Personagem::~Personagem(){}

int Personagem::get_X(){
    return this->coord_atual.get_X();
}

int Personagem::get_Y(){
    return this->coord_atual.get_Y();
}

void Personagem::set_X(int _x){
    this->coord_atual.set_X(_x);
}

void Personagem::set_Y(int _y){
    this->coord_atual.set_Y(_y);
}

int Personagem::get_X_init(){
    return this->coord_init.get_X();
}

int Personagem::get_Y_init(){
    return this->coord_init.get_X();
}

void Personagem::set_X_init(int _x){
    this->coord_init.set_X(_x);
}

void Personagem::set_Y_init(int _x){
    this->coord_init.set_Y(_x);
}

int Personagem::getDirection(){
    return this->direction;
}