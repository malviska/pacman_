#include <array>
#include <cmath>

#include "../include/globals.hpp"
#include "../include/collision.hpp"

bool map_collision(bool i_use_door, int i_x, int i_y, std::vector<std::vector<Object*>>& i_map)
{
	bool output = 0;
	int cell_x = i_x;
	int cell_y = i_y;
	int x = cell_x;
	int y = cell_y;

    if (0 <= x && 0 <= y && MAP_HEIGHT > y && MAP_WIDTH > x) {
        
        if (i_map[y][x]->get_type_int() == 1) {
            output = true;

        } else if (0 == i_use_door && Type::door == i_map[y][x]->get_type()) {
            output = true;
        }
	}

	return output;
}