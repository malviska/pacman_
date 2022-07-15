#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/pacman.hpp"
#include "../include/ghost.hpp"

static void mock_map(std::vector<std::vector<Object*>> * mocked_i_map){
    Pacman mocked_pacman;
    Ghost mocked_red;
    Ghost mocked_blue;
    Ghost mocked_pink;
    Ghost mocked_orange;

    std::ifstream file;

    file.open("./data/mapa.txt");
    Map m;

    *mocked_i_map = m.ler_mapa(
        file,
        mocked_pacman,
        mocked_red,
        mocked_blue,
        mocked_pink,
        mocked_orange
    );
    
    file.close();
}

TEST_CASE("Pacman test 01 - When set direction, than the direction change"){
    Pacman pacman;

    pacman.setDirection(1);

    CHECK(pacman.getDirection() == 1);
};

TEST_CASE("Pacman test 02 - When set direction 0, than the direction change"){
    Pacman pacman;

    std::vector<std::vector<Object*>> mocked_i_map;

    int last_position = pacman.get_X();
    
    mock_map(&mocked_i_map);

    pacman.setDirection(0);
    pacman.move(&mocked_i_map);

    CHECK(pacman.get_X() > last_position);
};

TEST_CASE("Pacman test 03 - When set direction 1, than the direction change"){
    Pacman pacman;

    std::vector<std::vector<Object*>> mocked_i_map;

    int last_position = pacman.get_Y();
    
    mock_map(&mocked_i_map);

    pacman.setDirection(1);
    pacman.move(&mocked_i_map);
    

    CHECK(pacman.get_Y() < last_position);
};

TEST_CASE("Pacman test 04 - When set direction 2, than the direction change"){
    Pacman pacman;

    std::vector<std::vector<Object*>> mocked_i_map;

    pacman.set_X(2);

    int last_position = pacman.get_X();
    
    mock_map(&mocked_i_map);

    pacman.setDirection(2);
    pacman.move(&mocked_i_map);

    CHECK(pacman.get_X() < last_position);
};

TEST_CASE("Pacman test 05 - When set direction 3, than the direction change"){
    Pacman pacman;

    std::vector<std::vector<Object*>> mocked_i_map;

    int last_position = pacman.get_Y();
    
    mock_map(&mocked_i_map);

    pacman.setDirection(3);
    pacman.move(&mocked_i_map);

    CHECK(pacman.get_Y() > last_position);
};

TEST_CASE("Pacman test 06 - When pacman position x is less than zero whit direction 2, then teleport pacman to MAP_WIDTH"){
    Pacman pacman; //INICIAL POSITION (0,0)

    std::vector<std::vector<Object*>> mocked_i_map;
    
    mock_map(&mocked_i_map);

    pacman.setDirection(2);
    pacman.move(&mocked_i_map);

    CHECK(pacman.get_X() == MAP_WIDTH - 1);
};


TEST_CASE("Pacman test 07 - When pacman eat a normal food, then te food gone and increment pacman score"){
    Pacman pacman; 
    //there is a fruit in coordinate (2,1)
    pacman.set_X(2);
    pacman.set_Y(1);

    std::vector<std::vector<Object*>> mocked_i_map;
    
    mock_map(&mocked_i_map);
    pacman.comer(&mocked_i_map);

    CHECK(pacman.get_score() == 10);
};


TEST_CASE("Pacman test 08 - When pacman eat a special food, then increment score and set invencible pacman "){
    Pacman pacman; 
    //there is a drug fruit in coordinate (2,2)
    pacman.set_X(2);
    pacman.set_Y(2);

    std::vector<std::vector<Object*>> mocked_i_map;
    
    mock_map(&mocked_i_map);
    pacman.comer(&mocked_i_map);

    CHECK(pacman.get_score() == 100);
    CHECK(pacman.getInvencibility() == true);
};

TEST_CASE("Pacman test 09 - When pacman lose lifes, then it dencrement its lifes"){
    Pacman pacman; 
    pacman.lose_life();
    CHECK(pacman.get_lifes()==2);
    
};