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

Food * food_1 = new Food();
Food * food_2 = new Food();
Food * food_3 = new Food(Type::food);

TEST_CASE("Food test 01 - When create a food, then increment the counter"){
    CHECK(Food::get_count() == 3);
};

TEST_CASE("Food test 02 - When the is eatene, then decrement the counter"){
    food_1->eaten();

    CHECK(Food::get_count() == 2);
};

TEST_CASE("Food test 03 - When the food has a type, then increment the points"){
    CHECK(food_1->get_points() == 10);
};

TEST_CASE("Food test 04 - When the food isn't over, then return false"){
    CHECK(food_1->is_food_over() == false);
};

TEST_CASE("Food test 05 - When the food is over, then return true"){
    food_2->eaten();
    food_3->eaten();

    CHECK(food_1->is_food_over() == true);
};

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



TEST_CASE("Coordinate test 01 - When set the especifics x and y, then you get it"){
    Coordinate coord;

    coord.set_X(1);
    coord.set_Y(2);

    int result_x = coord.get_X();
    int result_y = coord.get_Y();

    CHECK(result_x == 1);
    CHECK(result_y == 2);
};


TEST_CASE("Coordinate test 02 - When set the especific pair value, then you get it"){
    Coordinate coord;

    coord.set_X(1);
    coord.set_Y(2);

    std::pair<int,int> result = coord.get_pair();
    std::pair<int,int> p = {1,2};

    CHECK(result == p);

};

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