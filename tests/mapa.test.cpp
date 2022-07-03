#include<SFML/Graphics.hpp>
#include"cell_maker.hpp"
#include"mapa.hpp"
#include"globals.hpp"

int main ()
{
    CellMaker celulas;
    Mapa mapa;
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

    sf::Event event;

	sf::RenderWindow window(sf::VideoMode(CELL_SIZE * MAP_WIDTH * SCREEN_RESIZE, (FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT) * SCREEN_RESIZE), "PACMAN", sf::Style::Close);

	window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * MAP_WIDTH, FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT)));
    sf::CircleShape PelletEater(7);
	PelletEater.setFillColor(sf::Color(255,255,0));
	map = celulas.make(map_sketch,ghostsPositions, pacman);
    PelletEater.setPosition(static_cast<float>(pacman.getX() +2), static_cast<float>(pacman.getY()+2));
    while(window.isOpen()){
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear();

        mapa.make(map,window);
        window.draw(PelletEater);

        window.display();
    }
}