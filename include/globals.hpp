#ifndef GLOBALS_H
#define GLOBALS_H

constexpr int MAP_HEIGHT = 21;
constexpr int MAP_WIDTH = 21;
constexpr int CELL_SIZE = 16;
constexpr int FOOD_POINTS = 10;
constexpr int DRUG_POINTS = 100;
constexpr int SCREEN_RESIZE = 2;
constexpr int FONT_HEIGHT = 16;
constexpr int TUNEL_HEIGHT = 9;
constexpr int PACMAN_SPEED = 1;
constexpr int GHOST_SPEED = 1;

enum Type{
    blank,
    wall,
    food,
    drug,
    red,
	blue,
	pink,
	orange,
    pacman,
    door,
};

#endif