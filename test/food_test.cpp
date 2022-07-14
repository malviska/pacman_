#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/food.hpp"
#include "../include/globals.hpp"

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
