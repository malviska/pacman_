#ifndef FOOD_H
#define FOOD_H

#include "object.hpp"

class Food : public Object{
    private:
        static int count;
        int points = FOOD_POINTS;
    public:
        Food();
        Food(Type tipo);
        int get_points();
        void eaten();
};


#endif