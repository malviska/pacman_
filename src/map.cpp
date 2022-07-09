#include "../include/map.hpp"

Mapa Map::ler_mapa(std::ifstream& file, Pacman& pac){
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
                    Ob = new Object(Type::blank);
                    output_map[j].push_back(Ob);
                    break;
                case '1':
                    Ob = new Object(Type::wall);
                    output_map[j].push_back(Ob);
                    break;
                case '2':
                    Ob = new Food();
                    output_map[j].push_back(Ob);
                    break;
                case '3':
                    Ob = new Food(Type::drug);
                    output_map[j].push_back(Ob);
                    break;                  
                case '4':
                    Ob = new Object(Type::ghost);
                    output_map[j].push_back(Ob);
                    break;
                case '5':
                    Ob = new Object(Type::pacman);
                    output_map[j].push_back(Ob);
                    pac.set_X(i);
                    pac.set_Y(j);
                    pac.set_X_init(i);
                    pac.set_Y_init(j);
                    break;
                case '6':
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