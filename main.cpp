#include<chrono>
#include <ctime>
#include "./include/game.hpp"
#include <thread>

int main(){

    Game game;
    while (game.running())
	{
        std::this_thread::sleep_for(std::chrono::milliseconds(70));
        game.update();
        game.render();
    }

    return 0;
}