#include "doctest.h"
#include "../include/collision.hpp"

TEST_CASE("collision test 01 - When character collide with an valid object, then the return is true"){
    bool mocked_i_use_door = 1;
    int mocked_i_x = 2;
    int mocked_i_y = 1;

    Pacman mocked_pacman;
    Ghost mocked_red;
    Ghost mocked_blue;
    Ghost mocked_pink;
    Ghost mocked_orange;

    std::ifstream file;
    file.open("./data/mapa.txt");
    Map m;

    std::vector<std::vector<Object*>> mocked_i_map = m.ler_mapa(
        file,
        mocked_pacman,
        mocked_red,
        mocked_blue,
        mocked_pink,
        mocked_orange
    );

    file.close();
    
    bool result = map_collision(mocked_i_use_door,mocked_i_x, mocked_i_y, mocked_i_map);

    CHECK(result == true);
};