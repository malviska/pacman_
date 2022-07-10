#include"ghosts.hpp"
#include <cstdlib>
Ghost::Ghost(){
    this->isFrightened = false;
    this->direction = 0;
}

void Ghost::mover(Mapa* map){
    /*
        função responsável pela movimentação do pacman
        recebe a direção e o rascunho do mapa do jogo
    */
    switch(direction){
        case 0:
           if(this->get_X() + 1 < MAP_WIDTH && (*map)[this->get_Y()][this->get_X() +1]->get_type() != Type::wall){
                Object ob = (*map)[this->get_Y()][this->get_X() +1]->get_type();
                //desaloca o espaço de memória no qual o pacman se encontrava e o substitui por um espaço em branco
                // delete (*map)[this->get_Y()][this->get_X()];
                // (*map)[this->get_Y()][this->get_X()] = &ob;
                //move o pacman para o próximo bloco de acordo com a cordenada    
                // delete (*map)[this->get_Y()][this->get_X()+1];
                // (*map)[this->get_Y()][this->get_X()+1] = new Object(Type::ghost);            
                this->set_X(this->get_X() + 1);
                //caso tenha uma peça na nova posição o pacman deve come-la
           }else {
                this->setDirection(rand()%4);
            }
            break;
        case 1:
            if(this->get_X() - 1 >= 0 && (*map)[this->get_Y()][this->get_X() - 1]->get_type() != Type::wall){
                Object ob = (*map)[this->get_Y()][this->get_X() -1]->get_type();
                //desaloca o espaço de memória no qual o pacman se encontrava e o substitui por um espaço em branco
                // delete (*map)[this->get_Y()][this->get_X()];
                // (*map)[this->get_Y()][this->get_X()] = &ob;
                // delete (*map)[this->get_Y()][this->get_X() - 1];
                // (*map)[this->get_Y()][this->get_X()-1] = new Object(Type::ghost);
                //move o pacman para o próximo bloco de acordo com a cordenada                
                this->set_X(this->get_X() - 1);
                //caso tenha uma peça na nova posição o pacman deve come-la
            }
            else{
                this->setDirection(rand()%4);
            }
            break;
        case 2:
            if((*map)[this->get_Y() + 1][this->get_X()]->get_type() != Type::wall){
                Object ob = (*map)[this->get_Y()+1][this->get_X()]->get_type();
                //desaloca o espaço de memória no qual o pacman se encontrava e o substitui por um espaço em branco
                // delete (*map)[this->get_Y()][this->get_X()];
                // (*map)[this->get_Y()][this->get_X()] = &ob;
                // delete (*map)[this->get_Y() + 1][this->get_X()];
                // (*map)[this->get_Y()+ 1][this->get_X()] = new Object(Type::ghost);
                this->set_Y(this->get_Y() + 1);
                //caso tenha uma peça na nova posição o pacman deve come-la
                this->comer(map);
            }
            else{
                this->setDirection(rand()%4);
            }
            break;
        case 3:
            if((*map)[this->get_Y() - 1][this->get_X()]->get_type() != Type::wall){
                Object ob = (*map)[this->get_Y() - 1][this->get_X()]->get_type();
                //desaloca o espaço de memória no qual o pacman se encontrava e o substitui por um espaço em branco
                // delete (*map)[this->get_Y()][this->get_X()];
                // (*map)[this->get_Y()][this->get_X()] = &ob;
                // delete (*map)[this->get_Y() -1][this->get_X()];
                // (*map)[this->get_Y()- 1][this->get_X()] = new Object(Type::ghost);
                //move o pacman para o próximo bloco de acordo com a cordenada
                this->set_Y(this->get_Y() - 1);
                //caso tenha uma peça na nova posição o pacman deve come-la
                this->comer(map);

            }
             else {
                this->setDirection(rand()%4);
            }
            break;
    }
}


void Ghost::setDirection(short dir){
    this->direction = dir;
}
void Ghost::comer(Mapa *map){}

bool Ghost::getIsFrightened(){
    return this->isFrightened;
}

void Ghost::setIsFrightened(){
    this->isFrightened = !(this->isFrightened);
}