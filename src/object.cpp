#include "../include/object.hpp"

Object::Object(){
    this->type = Type::blank;
}

Object::Object(Type tipo){
    this->type = tipo;
}

Object::~Object(){
}

Type Object::get_type(){
    return this->type;
}

int Object::get_type_int(){
    return this->type;
}