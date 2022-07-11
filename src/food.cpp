#include "../include/food.hpp"

int Food::count = 0;

Food::Food() : Object(Type::food){
    Food::count++;
}

Food::Food(Type tipo) : Object(tipo){
    Food::count++;
    
    this->points = DRUG_POINTS;
}

int Food::get_points(){
    return this->points;
}

void Food::eaten(){
    Food::count--;
}

bool Food::is_food_over(){
    return Food::count == 0;
}