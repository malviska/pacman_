#include "../include/map.hpp"

//Mapa é std::vector<std::vector<Object*>>
//Map é a classe
Mapa Map::ler_mapa(std::ifstream& file, Pacman& pac, Ghost& red, Ghost& blue, Ghost& pink, Ghost& orange){
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
                    Ob = new Object(Type::red);
                    output_map[j].push_back(Ob);
                    red.set_X(i);
                    red.set_Y(j);
                    red.set_X_init(i);
                    red.set_Y_init(j);
                    break;
                case '7':
                //4 representa um fantasma
                    Ob = new Object(Type::blue);
                    output_map[j].push_back(Ob);
                    blue.set_X(i);
                    blue.set_Y(j);
                    blue.set_X_init(i);
                    blue.set_Y_init(j);
                    break;
                case '8':
                //4 representa um fantasma
                    Ob = new Object(Type::pink);
                    output_map[j].push_back(Ob);
                    pink.set_X(i);
                    pink.set_Y(j);
                    pink.set_X_init(i);
                    pink.set_Y_init(j);
                    break;
                case '9':
                //4 representa um fantasma
                    Ob = new Object(Type::orange);
                    output_map[j].push_back(Ob);
                    orange.set_X(i);
                    orange.set_Y(j);
                    orange.set_X_init(i);
                    orange.set_Y_init(j);
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