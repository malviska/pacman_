#include"cell_maker.hpp"
#include"globals.hpp"
#include"pacman.hpp"
#include<iostream>


int main ()
{
    CellMaker celulas;
    std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> map;
    std::array<coordenada, 4> ghostsPositions;
    Pacman pacman;

    std::array<std::string, MAP_HEIGHT> map_sketch = {
		" ################### ",
		" #........#........# ",
		" #o##.###.#.###.##o# ",
		" #.................# ",
		" #.##.#.#####.#.##.# ",
		" #....#...#...#....# ",
		" ####.### # ###.#### ",
		"    #.#   0   #.#    ",
		"#####.# ##=## #.#####",
		"     .  #123#  .     ",
		"#####.# ##### #.#####",
		"    #.#       #.#    ",
		" ####.# ##### #.#### ",
		" #........#........# ",
		" #.##.###.#.###.##.# ",
		" #o.#.....P.....#.o# ",
		" ##.#.#.#####.#.#.## ",
		" #....#...#...#....# ",
		" #.######.#.######.# ",
		" #.................# ",
		" ################### "
	};
    map = celulas.make(map_sketch,ghostsPositions, pacman);
	for(short i = 0; i<MAP_HEIGHT; i++){
		for(short j = 0; j<MAP_WIDTH; j++){
			std::cout<<(int) map[j][i];
		}
		std::cout<<std::endl;
	}
	// Door = 0,
	// Empty = 1,
	// Energizer = 2,
	// Pellet = 3,
	// Wall = 4
    return 0;

}