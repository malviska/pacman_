#include"mapa.hpp"

Mapa::Mapa(){};

void Mapa::make(const std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& _map, sf::RenderWindow& _window)
{
    sf::RectangleShape cell_shape(sf::Vector2f(CELL_SIZE,CELL_SIZE));

	for (short i = 0; i < MAP_WIDTH; i++)
	{
		for (short j = 0; j < MAP_HEIGHT; j++)
		{
			cell_shape.setPosition(static_cast<float>(CELL_SIZE * i), static_cast<float>(CELL_SIZE * j));

			//We just crop out what we need from the texture.
			switch (_map[i][j])
			{
				case Cell::Door:
				{
					cell_shape.setFillColor(sf::Color(36,36,100));
                    _window.draw(cell_shape);

					break;
				}
				case Cell::Energizer:
				{
					sf::CircleShape energizer(3);
					energizer.setFillColor(sf::Color(255,0,0));
                    energizer.setPosition(static_cast<float>((CELL_SIZE * i) + ((CELL_SIZE)/2 -2)), static_cast<float>((CELL_SIZE * j) + (CELL_SIZE/2 - 2)));
					_window.draw(energizer);

					break;
				}
				case Cell::Pellet:
				{
                    sf::CircleShape pellet(2);
					pellet.setFillColor(sf::Color(255,255,255));
                    pellet.setPosition(static_cast<float>((CELL_SIZE * i) + ((CELL_SIZE)/2 -2)), static_cast<float>((CELL_SIZE * j) + (CELL_SIZE/2 -2)));
					_window.draw(pellet);

					break;
				}
				case Cell::Wall:
				{
					bool down = 0;
					bool left = 0;
					bool right = 0;
					bool up = 0;

					if (j < MAP_HEIGHT - 1)
					{
						if (Cell::Wall == _map[i][1 + j])
						{
							down = 1;
						}
					}

					//Since we have warp tunnels, we need to draw them as if they're connected.
					if (0 < i)
					{
						if (Cell::Wall == _map[i - 1][j])
						{
							left = 1;
						}
					}
					else
					{
						left = 1;
					}

					if (i < MAP_WIDTH - 1)
					{
						if (Cell::Wall == _map[1 + i][j])
						{
							right = 1;
						}
					}
					else
					{
						right = 1;
					}

					if (0 < j)
					{
						if (Cell::Wall == _map[i][j - 1])
						{
							up = 1;
						}
					}

					cell_shape.setFillColor(sf::Color(36,36,255));

					_window.draw(cell_shape);
				}
			}
		}
	}
}