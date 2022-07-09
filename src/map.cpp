#include "../include/map.hpp"

//Mapa é std::vector<std::vector<Object*>>
//Map é a classe
Mapa Map::ler_mapa(std::ifstream& file, Pacman& pac){
    /*
        função responsável por ler o arquivo txt
        que contem o mapa e montar 
        um racunho do mapa utilizando alocação dinâmica
    */
    std::string line;
    Mapa output_map;
    Object *Ob;
    int j=0;
    while(getline(file, line)){
        std::vector<Object*> L;
        output_map.push_back(L);
        for(int i = 0; i < MAP_WIDTH; i++){
            switch(line[i]){
                case '0':
                //0 representa um espaço vazio
                    Ob = new Object(Type::blank);
                    output_map[j].push_back(Ob);
                    break;
                case '1':
                //1 representa uma parede
                    Ob = new Object(Type::wall);
                    output_map[j].push_back(Ob);
                    break;
                case '2':
                //2 representa uma comida
                    Ob = new Food();
                    output_map[j].push_back(Ob);
                    break;
                case '3':
                //3 representa uma droga
                    Ob = new Food(Type::drug);
                    output_map[j].push_back(Ob);
                    break;                  
                case '4':
                //4 representa um fantasma
                    Ob = new Object(Type::ghost);
                    output_map[j].push_back(Ob);
                    break;
                case '5':
                //5 representa o pacman
                    Ob = new Object(Type::pacman);
                    output_map[j].push_back(Ob);
                    pac.set_X(i);
                    pac.set_Y(j);
                    pac.set_X_init(i);
                    pac.set_Y_init(j);
                    break;
                case '6':
                //6 representa a porta
                    Ob = new Object(Type::door);
                    output_map[j].push_back(Ob);
                    break;
                default:
                    break;
            }
        }
        j++;
    }
    return output_map;
}