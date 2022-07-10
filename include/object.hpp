#ifndef OBJETO_H
#define OBJETO_H

#include "coordenada.hpp"
#include "globals.hpp"

class Object{
    private:
    protected:    
        Type type;
    public:
        Object();
        Object(Type tipo);
        virtual ~Object();
        int get_type_int();
        Type get_type();

};

#endif