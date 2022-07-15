#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/collision.hpp"

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

TEST_CASE("collision test 01 - When character collide with an wall, then the return is true, so it can't move"){
    bool mocked_i_use_door = 0;
    int mocked_wall_position_x = 2;
    int mocked_wall_position_y = 0;

    std::vector<std::vector<Object*>> mocked_i_map;
    
    mock_map(&mocked_i_map);

    
    bool result = map_collision(mocked_i_use_door,mocked_wall_position_x, mocked_wall_position_y, mocked_i_map);

    CHECK(result == true);
};

TEST_CASE("collision test 02 - When character collide with an blank space, then the return is false, so it can move"){
    bool mocked_i_use_door = 0;
    int mocked_space_position_x = 0;
    int mocked_space_position_y = 0;

    std::vector<std::vector<Object*>> mocked_i_map;
    
    mock_map(&mocked_i_map);

    
    bool result = map_collision(mocked_i_use_door,mocked_space_position_x, mocked_space_position_y, mocked_i_map);

    CHECK(result == false);
};

TEST_CASE("collision test 03 - When character collide with an fruit, then the return is false so it can move"){
    bool mocked_i_use_door = 0;
    int mocked_fruit_position_x = 2;
    int mocked_fruit__position_y = 1;

    std::vector<std::vector<Object*>> mocked_i_map;
    
    mock_map(&mocked_i_map);

    
    bool result = map_collision(mocked_i_use_door,mocked_fruit_position_x, mocked_fruit__position_y, mocked_i_map);

    CHECK(result == false);
};

TEST_CASE("collision test 04 - When character collide with an enegirze, then the return is false so it can move"){
    bool mocked_i_use_door = 0;
    int mocked_energize_position_x = 2;
    int mocked_energize_position_y = 2;

    std::vector<std::vector<Object*>> mocked_i_map;
    
    mock_map(&mocked_i_map);

    
    bool result = map_collision(mocked_i_use_door,mocked_energize_position_x, mocked_energize_position_y, mocked_i_map);

    CHECK(result == false);
};

TEST_CASE("collision test 05 - When character collide with anghost, then the return is true so it can move"){
    bool mocked_i_use_door = 0;

    int mocked_ghost_position_x = 10;
    int mocked_ghost_position_y = 7;

    std::vector<std::vector<Object*>> mocked_i_map;
    
    mock_map(&mocked_i_map);
    
    bool result = map_collision(mocked_i_use_door,mocked_ghost_position_x, mocked_ghost_position_y, mocked_i_map);

    CHECK(result == false);
};

TEST_CASE("collision test 05 - When character collide with an object out of map, then the return is false so it can move"){
    bool mocked_i_use_door = 0;

    int mocked_ghost_position_x = -1;
    int mocked_ghost_position_y = -1;

    std::vector<std::vector<Object*>> mocked_i_map;
    
    mock_map(&mocked_i_map);
    
    bool result = map_collision(mocked_i_use_door,mocked_ghost_position_x, mocked_ghost_position_y, mocked_i_map);
    
    CHECK(result == false);

    mocked_ghost_position_x = MAP_HEIGHT + 1;
    mocked_ghost_position_y = MAP_WIDTH + 1;

    result = map_collision(mocked_i_use_door,mocked_ghost_position_x, mocked_ghost_position_y, mocked_i_map);

    CHECK(result == false);

    mocked_ghost_position_x =  -1;
    mocked_ghost_position_y = MAP_WIDTH + 1;

    result = map_collision(mocked_i_use_door,mocked_ghost_position_x, mocked_ghost_position_y, mocked_i_map);

    CHECK(result == false);

    mocked_ghost_position_x = MAP_HEIGHT + 1;
    mocked_ghost_position_y = -1;

    result = map_collision(mocked_i_use_door,mocked_ghost_position_x, mocked_ghost_position_y, mocked_i_map);

    CHECK(result == false);
};