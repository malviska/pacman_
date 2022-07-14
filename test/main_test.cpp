#include "../include/map.hpp"

int main(){
    std::ifstream File;
    File.open("../data/mapa.txt");
    Map map;
    Pacman *pacman = new Pacman();
    Mapa mapinha = map.ler_mapa(File, *pacman);

    for(int i = 0; i < 5; i++){
        pacman->move(0, &mapinha);
    }
    for(int i = 0; i < 4; i++){
        pacman->move(2, &mapinha);
    }



    for(int i = 0; i < (int)mapinha.size(); i++){
        for(int j = 0; j < (int)mapinha.size(); j++){
            std::cout << mapinha[i][j]->get_type() << " ";
        }
        std::cout << std::endl;
    }


    for(int i = 0; i < (int)mapinha.size(); i++){
        for(int j = 0; j < (int)mapinha[0].size(); j++){
            delete mapinha[i][j];
        }
    }

    File.close();
    delete pacman;
    return 0;
}