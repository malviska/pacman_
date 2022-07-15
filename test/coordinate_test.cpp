#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/coordinate.hpp"

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