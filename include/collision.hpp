#include "globals.hpp"
#include"map.hpp"
#ifndef COLLISION_H
#define COLLISION_H

bool map_collision(bool i_collect_pellets, bool i_use_door, int x, int y, std::vector<std::vector<Object*>>& i_map);

#endif