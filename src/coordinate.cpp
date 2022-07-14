#include "../include/coordinate.hpp"

Coordinate::Coordinate(){
    this->x = 0;
    this->y = 0;
}

int Coordinate::get_X(){
    return this->x;
}

int Coordinate::get_Y(){
    return this->y;
}

void Coordinate::set_X(int _x){
    this->x = _x;
}

void Coordinate::set_Y(int _y){
    this->y = _y;
}

std::pair<int,int> Coordinate::get_pair(){
    std::pair<int,int> p = {this->x, this->y};
    
    return p;
}