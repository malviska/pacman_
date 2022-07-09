#include "../include/game.hpp"

Game::Game(){
    this->initPacman();
    this->initWindow();
    this->initFonts();
    this->initText();
}

Game::~Game(){
    for(int i = 0; i < (int)this->map_sketch.size(); i++){
        for(int j = 0; j < (int)this->map_sketch[0].size(); j++){
            delete this->map_sketch[i][j];
        }
    }
    delete this->pacman;
    delete this->window;
}

void Game::initPacman(){
    this->window = nullptr;
    this->pacman = new Pacman();
    this->File.open("./data/mapa.txt");
    Map m;
    this->map_sketch = m.ler_mapa(this->File, *this->pacman);
    this->File.close();
}

void Game::initWindow(){
    this->video_mode.height = (FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT) * SCREEN_RESIZE;
    this->video_mode.width = CELL_SIZE * MAP_WIDTH * SCREEN_RESIZE;
    this->window = new sf::RenderWindow(this->video_mode, "PACMAN",  sf::Style::Titlebar | sf::Style::Close);
    this->window->setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * MAP_WIDTH, FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT)));
    this->window->setFramerateLimit(20);
}

void Game::initFonts(){
    this->font.loadFromFile("./data/PixellettersFull.ttf");
}

void Game::initText(){
    this->uiText.setFont(this->font);
    this->uiText.setCharacterSize(15);
    this->uiText.setFillColor(sf::Color::Yellow);
    this->uiText.setString("NONE");
    this->uiText.setPosition(120.f, 0.f);

    this->GOText.setFont(this->font);
    this->GOText.setCharacterSize(150);
    this->GOText.setFillColor(sf::Color::Red);
    this->GOText.setString("GAME OVER!");
    this->GOText.setPosition(
        this->window->getSize().y/2.f - this->GOText.getGlobalBounds().height,
        this->window->getSize().x/2.f - this->GOText.getGlobalBounds().width/2.f
    );
}

bool Game::getEndGame(){
    return this->pacman->get_lifes() == 0;
}

const bool Game::running() const{
    return this->window->isOpen();
}

void Game::pollEvents(){
    while(this->window->pollEvent(this->ev)){
        switch(this->ev.type){
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if(this->ev.key.code == sf::Keyboard::Escape){
                    this->window->close();
                }
                break;
            default:
                break;
        }
    }
}

void Game::update(){
    this->pollEvents();
    if(!this->getEndGame()){
        this->updatePacman();
        this->updateText();
    }
}

void Game::updatePacman(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) this->pacman->mover(1, &this->map_sketch);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) this->pacman->mover(3, &this->map_sketch);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) this->pacman->mover(2, &this->map_sketch);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) this->pacman->mover(0, &this->map_sketch);
}

void Game::updateText(){
    std::stringstream ss;

    ss << "Points: " << this->pacman->get_score() << " Lifes: " << this->pacman->get_lifes();

    this->uiText.setString(ss.str());
}

void Game::renderMap(sf::RenderTarget& target){
{
    sf::RectangleShape cell_shape(sf::Vector2f(CELL_SIZE,CELL_SIZE));
	sf::CircleShape energizer(3);
    sf::CircleShape pellet(2);

	for (short i = 0; i < MAP_HEIGHT; i++){
		for (short j = 0; j < MAP_WIDTH; j++){
			cell_shape.setPosition(static_cast<float>(CELL_SIZE * j), static_cast<float>(CELL_SIZE * i));

			switch (this->map_sketch[i][j]->get_type()){
				case Type::door:
					cell_shape.setFillColor(sf::Color(36,36,100));
                    this->window->draw(cell_shape);
					break;
				case Type::drug:
					energizer.setFillColor(sf::Color(255,0,0));
                    energizer.setPosition(static_cast<float>((CELL_SIZE * j) + ((CELL_SIZE)/2 -2)), static_cast<float>((CELL_SIZE * i) + (CELL_SIZE/2 - 2)));
					this->window->draw(energizer);
					break;
				case Type::food:
					pellet.setFillColor(sf::Color(255,255,255));
                    pellet.setPosition(static_cast<float>((CELL_SIZE * j) + ((CELL_SIZE)/2 -2)), static_cast<float>((CELL_SIZE * i) + (CELL_SIZE/2 -2)));
					this->window->draw(pellet);
					break;
				case Type::wall:
					cell_shape.setFillColor(sf::Color(36,36,255));
					this->window->draw(cell_shape);
                    break;
                case Type::pacman:
                    this->renderPacman(*this->window);
                    break;
                default:
                    break;
                }
			}
		}
	}
}

void Game::renderPacman(sf::RenderTarget& target){
    sf::CircleShape PelletEater(7);
	PelletEater.setFillColor(sf::Color(255,255,0));
    PelletEater.setPosition(static_cast<float>(this->pacman->get_X() * CELL_SIZE), static_cast<float>(this->pacman->get_Y() * CELL_SIZE));
    target.draw(PelletEater);
}

void Game::renderText(sf::RenderTarget& target){
    target.draw(this->uiText);
}

void Game::renderGameOver(sf::RenderTarget& target){
    target.draw(this->GOText);
}

void Game::render(){
    this->window->clear();

    this->renderMap(*this->window);
    this->renderText(*this->window);

    if(this->getEndGame()){
        this->renderGameOver(*this->window);
    }

    this->window->display();
}