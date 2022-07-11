#include "./include/game.hpp"
#include "./include/menu.hpp"

int main(){

    /*
    Game game;

    while(game.running()){

        game.update();

        game.render();
    }

    */
    Menu * menu = new Menu();
    menu->run_menu();
    delete menu;
    menu = nullptr;

    return EXIT_SUCCESS;
}