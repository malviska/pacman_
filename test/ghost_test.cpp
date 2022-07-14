#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
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

TEST_CASE("Ghost test 01 - When set direction, than the direction change"){
    Ghost ghost;

    ghost.setDirection(1);

    CHECK(ghost.getDirection() == 1);
};

TEST_CASE("Ghost test 02 - When set direction 0, than the direction change"){
    Ghost ghost;
    std::vector<std::vector<Object*>> mocked_i_map;

    // here the ghost can move
    ghost.set_X(10);
    ghost.set_Y(7);

    int last_position = ghost.get_X();
    
    mock_map(&mocked_i_map);

   ghost.setDirection(0);
   ghost.move(&mocked_i_map);

    CHECK(ghost.get_X() > last_position);
};

TEST_CASE("Ghost test 03 - When set direction 1, than the direction change"){
    Ghost ghost;
    std::vector<std::vector<Object*>> mocked_i_map;

    int last_position =ghost.get_Y();
    
    mock_map(&mocked_i_map);

   ghost.setDirection(1);
   ghost.move(&mocked_i_map);
    

    CHECK(ghost.get_Y() < last_position);
};

TEST_CASE("Ghost test 04 - When set direction 2, than the direction change"){
    Ghost ghost;
    std::vector<std::vector<Object*>> mocked_i_map;

    ghost.set_X(10);
    ghost.set_Y(7);

    int last_position = ghost.get_X();
    
    mock_map(&mocked_i_map);

   ghost.setDirection(2);
   ghost.move(&mocked_i_map);

    CHECK(ghost.get_X() < last_position);
};

TEST_CASE("Ghost test 05 - When set direction 3, than the direction change"){
    Ghost ghost;

    std::vector<std::vector<Object*>> mocked_i_map;

    int last_position =ghost.get_Y();
    
    mock_map(&mocked_i_map);

   ghost.setDirection(3);
   ghost.move(&mocked_i_map);

    CHECK(ghost.get_Y() > last_position);
};

TEST_CASE("Ghost test 06 - When ghost position x is less than zero whit direction 2, then teleportghost to MAP_WIDTH"){
    Ghost ghost; //INICIAL POSITION (0,0)

    std::vector<std::vector<Object*>> mocked_i_map;
    
    mock_map(&mocked_i_map);

   ghost.setDirection(2);
   ghost.move(&mocked_i_map);

    CHECK(ghost.get_X() == MAP_WIDTH - 1);
};

