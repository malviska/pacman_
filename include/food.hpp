#ifndef FOOD_H
#define FOOD_H

#include "object.hpp"

class Food : public Object{
    friend class Game;

    private:
        static int count;
        int points = FOOD_POINTS;

    public:
        Food();
        Food(Type tipo);

        static int get_count();
        
        int get_points();
        void eaten();
        bool is_food_over();
};


#endif