#include <array>
#include <cmath>

#include "../include/globals.hpp"
#include "../include/collision.hpp"

bool map_collision(bool i_collect_pellets, bool i_use_door, int i_x, int i_y, std::vector<std::vector<Object*>>& i_map)
{
	bool output = 0;

	//Getting the exact position.
	int cell_x = i_x;
	int cell_y = i_y;

	//A ghost/Pacman can intersect 4 Types at most.
	// for (unsigned char a = 0; a < 4; a++)
	// {
	int x = cell_x;
	int y = cell_y;

		// switch (a)
		// {
		// 	case 0: //Top left Type
		// 	{
		// 		x = static_cast<int>(floor(cell_x));
		// 		y = static_cast<int>(floor(cell_y));

		// 		break;
		// 	}
		// 	case 1: //Top right Type
		// 	{
		// 		x = static_cast<int>(ceil(cell_x));
		// 		y = static_cast<int>(floor(cell_y));

		// 		break;
		// 	}
		// 	case 2: //Bottom left Type
		// 	{
		// 		x = static_cast<int>(floor(cell_x));
		// 		y = static_cast<int>(ceil(cell_y));

		// 		break;
		// 	}
		// 	case 3: //Bottom right Type
		// 	{
		// 		x = static_cast<int>(ceil(cell_x));
		// 		y = static_cast<int>(ceil(cell_y));
		// 	}
		// }

		// Making sure that the position is inside the map.
    if (0 <= x && 0 <= y && MAP_HEIGHT > y && MAP_WIDTH > x) {
		//Here we only care about the walls.
        if (0 == i_collect_pellets) {
            if (i_map[y][x]->get_type_int() == 1) {
                output = true;

            } else if (0 == i_use_door && Type::door == i_map[y][x]->get_type()) {
                output = 1;
				
            }
        }
			// else //Here we only care about the collectables.
			// {
			// 	if (Type::drug == i_map[x][y]->get_type())
			// 	{
			// 		output = 1;
            //         delete i_map[x][y];
            //         i_map[x][y] = new Object(Type::blank);
			// 	}
			// 	else if (Type::food == i_map[x][y]->get_type())
			// 	{
            //         delete i_map[x][y];
            //         i_map[x][y] = new Object(Type::blank);
			// 	}
		    // }
	}
	// }
	return output;
}