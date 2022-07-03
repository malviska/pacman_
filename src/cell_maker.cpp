#include"../include/cell_maker.hpp"


CellMaker::CellMaker(){};

std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> CellMaker::make(const std::array<std::string, MAP_HEIGHT>& _map_draw, std::array<coordenada, 4>& _ghosts_coord, Pacman& _pacman)
{
    std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> output_map{};
    for(short i = 0; i<MAP_HEIGHT; i++){
        for(short j = 0; j<MAP_WIDTH; j++){
            output_map[j][i] = Cell::Empty;
            switch(_map_draw[i][j]){
                case '#':
				{
					output_map[j][i] = Cell::Wall;

					break;
				}
				case '=':
				{
					output_map[j][i] = Cell::Door;

					break;
				}
				case '.':
				{
					output_map[j][i] = Cell::Pellet;

					break;
				}
				// Fantasma vermelho
				case '0':
				{
					_ghosts_coord[0].x = CELL_SIZE * j;
					_ghosts_coord[0].y = CELL_SIZE * i;

					break;
				}
				// Fantasma Rosa
				case '1':
				{
					_ghosts_coord[1].x = CELL_SIZE * j;
					_ghosts_coord[1].y = CELL_SIZE * i;

					break;
				}
				// Fantasma Azul
				case '2':
				{
					_ghosts_coord[2].x = CELL_SIZE * j;
					_ghosts_coord[2].y = CELL_SIZE * i;

					break;
				}
				// Fantasma Laranja
				case '3':
				{
					_ghosts_coord[3].x = CELL_SIZE * j;
					_ghosts_coord[3].y = CELL_SIZE * i;

					break;
				}
				// Pacman
				case 'P':
				{
					_pacman.set_coord(CELL_SIZE * j, CELL_SIZE * i);

					break;
				}
                // Energizador
				case 'o':
				{
					output_map[j][i] = Cell::Energizer;
				}
			}
        }
    }
	return output_map;
}
