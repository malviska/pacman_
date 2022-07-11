#include "../include/coordenada.hpp"

Coordenada::Coordenada(){
    this->x = 0;
    this->y = 0;
}

int Coordenada::get_X(){
    return this->x;
}

int Coordenada::get_Y(){
    return this->y;
}

void Coordenada::set_X(int _x){
    this->x = _x;
}

void Coordenada::set_Y(int _y){
    this->y = _y;
}

std::pair<int,int> Coordenada::getPair(){
    std::pair<int,int> p = {this->x, this->y};
    
    return p;
}