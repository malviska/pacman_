#include<SFML/Graphics.hpp>
#include"cell_maker.hpp"
#include"mapa.hpp"
#include"globals.hpp"

int main ()
{
    CellMaker celulas;
    Mapa mapa;
    std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> map;
    std::array<Coordenada, 4> ghostsPositions;
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
	map = celulas.make(map_sketch,ghostsPositions, pacman);
    while(window.isOpen()){
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear();

        mapa.make(map,window);
        pacman.drawPacman(window);
        pacman.update();
        window.display();
    }
}