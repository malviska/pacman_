#include "../include/pacman.hpp"

Pacman::Pacman(){
    this->lifes = 3;
    this->score = 0;
}

void Pacman::mover(short move, Mapa* map){
    switch(std::to_string(move)[0]){
        case '0':
            if(this->get_X() + 1 < MAP_WIDTH && (*map)[this->get_Y()][this->get_X() + 1]->get_type_int() != Type::wall){
                
                delete (*map)[this->get_Y()][this->get_X()];
                (*map)[this->get_Y()][this->get_X()] = new Object(Type::blank);
                
                this->set_X(this->get_X() + 1);
                
                this->comer(map);
            } else if(this->get_X()+1 == MAP_WIDTH && this->get_Y() == 9){
                delete (*map)[this->get_Y()][this->get_X()];
                (*map)[this->get_Y()][this->get_X()] = new Object(Type::blank);
                
                this->set_X(0);

                this->comer(map);
            }
            break;
        case '1':
            if(this->get_X() - 1 >= 0 && (*map)[this->get_Y()][this->get_X() - 1]->get_type_int() != Type::wall){
                
                delete (*map)[this->get_Y()][this->get_X()];
                (*map)[this->get_Y()][this->get_X()] = new Object(Type::blank);

                this->set_X(this->get_X() - 1);
                
                this->comer(map);
            }else if(this->get_X()-1 < 0 && this->get_Y() == 9){
                delete (*map)[this->get_Y()][this->get_X()];
                (*map)[this->get_Y()][this->get_X()] = new Object(Type::blank);
                
                this->set_X(MAP_WIDTH - 1);

                this->comer(map);
            }
            break;
        case '2':
            if((*map)[this->get_Y() + 1][this->get_X()]->get_type_int() != Type::wall){
                
                delete (*map)[this->get_Y()][this->get_X()];
                (*map)[this->get_Y()][this->get_X()] = new Object(Type::blank);

                this->set_Y(this->get_Y() + 1);

                this->comer(map);

            }
            break;
        case '3':
            if((*map)[this->get_Y() - 1][this->get_X()]->get_type_int() != Type::wall){

                delete (*map)[this->get_Y()][this->get_X()];
                (*map)[this->get_Y()][this->get_X()] = new Object(Type::blank);

                this->set_Y(this->get_Y() - 1);

                this->comer(map);

            }
            break;
    }
}

void Pacman::comer(Mapa* map){
    if((*map)[this->get_Y()][this->get_X()]->get_type_int() == Type::food ||
    (*map)[this->get_Y()][this->get_X()]->get_type_int() == Type::drug){
        Food *Eat = dynamic_cast<Food*>((*map)[this->get_Y()][this->get_X()]);
        this->score += Eat->get_points(); 
        if(Eat->get_type_int() == Type::drug){
            
        }
        Eat->eaten();
        delete (*map)[this->get_Y()][this->get_X()];
        (*map)[this->get_Y()][this->get_X()] = new Object(Type::pacman);
    }else{
        delete (*map)[this->get_Y()][this->get_X()];
        (*map)[this->get_Y()][this->get_X()] = new Object(Type::pacman);
    }
}

void Pacman::lose_life(){
    this->lifes--;
}

short Pacman::get_lifes(){
    return this->lifes;
}

unsigned Pacman::get_score(){
    return this->score;
}