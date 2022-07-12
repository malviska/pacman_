#include "../include/pacman.hpp"
#include <iostream>

Pacman::Pacman(){
    this->lifes = 3;
    this->score = 0;
}

void Pacman::setDirection(short dir){
    this->direction = dir;
}

void Pacman::mover(Mapa* map){
    switch (direction)
    {
        case 0: {
            this->set_X(this->get_X() + PACMAN_SPEED);

            break;
        }

        case 1: {
            this->set_Y(this->get_Y() - PACMAN_SPEED);

            break;
        }

        case 2: {
            this->set_X(this->get_X() - PACMAN_SPEED);

            break;
        }

        case 3: {
            this->set_Y(this->get_Y() + PACMAN_SPEED);
        }
    }

	if (this->get_X()<0) {
		this->set_X(MAP_WIDTH - 1);

	} else if (MAP_WIDTH <= this->get_X()) {
		this->set_X(0);

	}
}

void Pacman::comer(Mapa* map){
    //verifica se a atual posição do pacman é ocupada por peças comestiveis(Food ou Drug)
    if((*map)[this->get_Y()][this->get_X()]->get_type() == Type::food ||
    (*map)[this->get_Y()][this->get_X()]->get_type() == Type::drug){
        //dinamic cast de Object para Food para termos acesso a pontuação dessa celula
        Food *Eat = dynamic_cast<Food*>((*map)[this->get_Y()][this->get_X()]);
        this->score += Eat->get_points();

        if(Eat->get_type() == Type::drug){
            if(!(this->invencibility)) this->setInvencibility();
        }

        Eat->eaten();
        //apos o pacman comer a celula ela deve sumir e o espaço será ocupado pelo pacman
        delete (*map)[this->get_Y()][this->get_X()];
        (*map)[this->get_Y()][this->get_X()] = new Object(Type::pacman);

    } else {
        //caso não haja nada para comer o pacman simplesmente assume o espaço
        delete (*map)[this->get_Y()][this->get_X()];
        (*map)[this->get_Y()][this->get_X()] = new Object(Type::pacman);
    }
}

void Pacman::setInvencibility(){
    this->invencibility = !(this->invencibility);
    this->timeInvencibility();
}

void Pacman::unsetInvensibility(){
    clock_t timer = clock();
    if((float)(timer - this->invencibilityTimer)/CLOCKS_PER_SEC >  0.25) this->invencibility = false;
}

void Pacman::timeInvencibility(){
    this->invencibilityTimer = clock();
}

bool Pacman::getInvencibility(){
    return this->invencibility;
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

void Pacman::sumScore(){
    this->score += 1000;
}