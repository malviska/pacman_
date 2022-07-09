#include "../include/pacman.hpp"

Pacman::Pacman(){
    this->lifes = 3;
    this->score = 0;
}

void Pacman::setDirection(short dir){
    this->direction = dir;
}

void Pacman::mover(Mapa* map){
    /*
        função responsável pela movimentação do pacman
        recebe a direção e o rascunho do mapa do jogo
    */
    switch(direction){
        case 0:
            //testa se a proxima posição é valida e diferente de uma parede
            if(this->get_X() + 1 < MAP_WIDTH && (*map)[this->get_Y()][this->get_X() + 1]->get_type() != Type::wall){
                //desaloca o espaço de memória no qual o pacman se encontrava e o substitui por um espaço em branco
                delete (*map)[this->get_Y()][this->get_X()];
                (*map)[this->get_Y()][this->get_X()] = new Object(Type::blank);
                //move o pacman para o próximo bloco de acordo com a cordenada
                this->set_X(this->get_X() + 1);
                //caso tenha uma peça na nova posição o pacman deve come-la
                this->comer(map);
            } else if(this->get_X()+1 == MAP_WIDTH && this->get_Y() == TUNEL_HEIGHT){ 
                //caso o pacman esteja adentrando o tunel ele sairá do outro lado do mapa
                delete (*map)[this->get_Y()][this->get_X()];
                (*map)[this->get_Y()][this->get_X()] = new Object(Type::blank);
                //move o pacman para o próximo bloco de acordo com a cordenada
                this->set_X(0);
                //caso tenha uma peça na nova posição o pacman deve come-la
                this->comer(map);
            }
            break;
        case 1:
            if(this->get_X() - 1 >= 0 && (*map)[this->get_Y()][this->get_X() - 1]->get_type() != Type::wall){
                //desaloca o espaço de memória no qual o pacman se encontrava e o substitui por um espaço em branco
                delete (*map)[this->get_Y()][this->get_X()];
                (*map)[this->get_Y()][this->get_X()] = new Object(Type::blank);
                //move o pacman para o próximo bloco de acordo com a cordenada                
                this->set_X(this->get_X() - 1);
                //caso tenha uma peça na nova posição o pacman deve come-la                
                this->comer(map);
            }else if(this->get_X()-1 < 0 && this->get_Y() == TUNEL_HEIGHT){
                //caso o pacman esteja adentrando o tunel ele sairá do outro lado do mapa
                delete (*map)[this->get_Y()][this->get_X()];
                (*map)[this->get_Y()][this->get_X()] = new Object(Type::blank);
                //move o pacman para o próximo bloco de acordo com a cordenada                
                this->set_X(MAP_WIDTH - 1);
                //caso tenha uma peça na nova posição o pacman deve come-la
                this->comer(map);
            }
            break;
        case 2:
            if((*map)[this->get_Y() + 1][this->get_X()]->get_type() != Type::wall){
                //desaloca o espaço de memória no qual o pacman se encontrava e o substitui por um espaço em branco  
                delete (*map)[this->get_Y()][this->get_X()];
                (*map)[this->get_Y()][this->get_X()] = new Object(Type::blank);
                //move o pacman para o próximo bloco de acordo com a cordenada
                this->set_Y(this->get_Y() + 1);
                //caso tenha uma peça na nova posição o pacman deve come-la
                this->comer(map);

            }
            break;
        case 3:
            if((*map)[this->get_Y() - 1][this->get_X()]->get_type() != Type::wall){
                //desaloca o espaço de memória no qual o pacman se encontrava e o substitui por um espaço em branco
                delete (*map)[this->get_Y()][this->get_X()];
                (*map)[this->get_Y()][this->get_X()] = new Object(Type::blank);
                //move o pacman para o próximo bloco de acordo com a cordenada
                this->set_Y(this->get_Y() - 1);
                //caso tenha uma peça na nova posição o pacman deve come-la
                this->comer(map);

            }
            break;
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
            
        }
        Eat->eaten();
        //apos o pacman comer a celula ela deve sumir e o espaço será ocupado pelo pacman
        delete (*map)[this->get_Y()][this->get_X()];
        (*map)[this->get_Y()][this->get_X()] = new Object(Type::pacman);
    }else{
        //caso não haja nada para comer o pacman simplesmente assume o espaço
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