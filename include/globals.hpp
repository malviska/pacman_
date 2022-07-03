#include<SFML/Graphics.hpp>
#ifndef GLOBALS_H
#define GLOBALS_H

constexpr unsigned char MAP_HEIGHT = 21;
constexpr unsigned char MAP_WIDTH = 21;
constexpr unsigned char CELL_SIZE = 16;
constexpr unsigned char SCREEN_RESIZE = 2;
constexpr unsigned char FONT_HEIGHT = 16;
constexpr unsigned int PACMAN_SPEED = 10;


enum Cell
{
	Door,
	Empty,
	Energizer,
	Pellet,
	Wall
};
// std::ostream& operator<<(std::ostream& out, const Cell value){
//     static std::map<Cell, std::string> strings;
//     if (strings.size() == 0){
// #define INSERT_ELEMENT(p) strings[p] = #p
//         INSERT_ELEMENT(Door);     
//         INSERT_ELEMENT(Empty);     
//         INSERT_ELEMENT(Energizer);
// 		INSERT_ELEMENT(Pellet);
// 		INSERT_ELEMENT(Wall);     
// #undef INSERT_ELEMENT
//     }
// }

#endif

