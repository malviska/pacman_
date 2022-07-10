#include "../include/game.hpp"

std::chrono::microseconds limitPacmanInvencibility = std::chrono::microseconds(100000);
Game::Game(){
    //inicializa o jogo
    this->initPacman();
    this->initWindow();
    this->initFonts();
    this->initText();
}

Game::~Game(){
    //desaloca toda a memoria utilizada
    for(int i = 0; i < (int)this->map_sketch.size(); i++){
        for(int j = 0; j < (int)this->map_sketch[0].size(); j++){
            delete this->map_sketch[i][j];
        }
    }
    delete this->pacman;
    delete this->window;
}

void Game::initPacman(){
    //inicia o pacman e outras variaveis
    this->window = nullptr;

    this->pacman = new Pacman();
    this->red = new Ghost();
    this->blue = new Ghost();
    this->pink = new Ghost();
    this->orange = new Ghost();
    this->File.open("./data/mapa.txt");
    Map m;
    this->map_sketch = m.ler_mapa(this->File, *this->pacman, *this->red, *this->blue, *this->pink, *this->orange);
    this->File.close();
}

void Game::initWindow(){
    //inicialixa a janela
    this->video_mode.height = (FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT) * SCREEN_RESIZE;
    this->video_mode.width = CELL_SIZE * MAP_WIDTH * SCREEN_RESIZE;
    this->window = new sf::RenderWindow(this->video_mode, "PACMAN",  sf::Style::Titlebar | sf::Style::Close);
    this->window->setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * MAP_WIDTH, FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT)));
    this->window->setFramerateLimit(20);
}

void Game::initFonts(){
    //coleta a fonte no arquivo ttf
    this->font.loadFromFile("./data/PixellettersFull.ttf");
}

void Game::initText(){
    //inicializa o score
    this->uiText.setFont(this->font);
    this->uiText.setCharacterSize(15);
    this->uiText.setOutlineColor(sf::Color::Black);
    this->uiText.setFillColor(sf::Color(250, 250, 0));
    this->uiText.setOutlineThickness(2);
    this->uiText.setString("NONE");
    this->uiText.setPosition(120.f, 0.f);
    //inicializa a mensagem de gameover 
    this->GOText.setFont(this->font);
    this->GOText.setCharacterSize(120);
    this->GOText.setFillColor(sf::Color::Red);
    this->GOText.setString("GAME\n OVER!");
    this->GOText.setPosition(25, 0);
}

bool Game::getEndGame(){
    //indica se o jogo chegou a ao fim
    return (this->pacman->get_lifes() == 0 || Food::count == 0);
}

const bool Game::running() const{
    //verifica se a janela ainda está aberta
    return this->window->isOpen();
}

void Game::pollEvents(){
    //verifica se foi apertado ESC ou o botão de sair para fechar o jogo
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
        this->updateGhost();
        this->updateText();
    }
}
double Game::distance(Pacman& pac, Ghost& ghs){
    double dis = sqrt(pow(pac.get_X() - ghs.get_X(), 2) + pow(pac.get_Y() - ghs.get_Y(), 2));
    return dis;
}
std::array<double, 4> Game::verifyDistances(){
    double dis1 = this->distance(*pacman, *red);
    double dis2 = this->distance(*pacman, *blue);
    double dis3 = this->distance(*pacman, *pink);
    double dis4 = this->distance(*pacman, *orange);
    return {dis1, dis2, dis3, dis4};
}



void Game::updatePacman(){
    this->pacman->unsetInvensibility();
    std::array<bool,4> walls{};
    std::array<double, 4> distances; 
    distances = this->verifyDistances();
    for(int i = 0; i<4; i++){
        if(distances[i]<=1){
            if(!this->pacman->getInvencibility()){
                this->pacman->lose_life();
                this->pacman->set_X(this->pacman->get_X_init() +1);
                this->pacman->set_Y(this->pacman->get_Y_init() +1);
                this->pacman->setDirection(0);
            }else{
                this->pacman->sumScore();
                switch(i){
                    case 0:
                        this->red->set_X(this->red->get_X_init());
                        this->red->set_Y(this->red->get_Y_init());
                        this->red->setIsFrightened();
                    break;
                    case 1:
                        this->blue->set_X(this->blue->get_X_init());
                        this->blue->set_Y(this->blue->get_Y_init());
                        this->blue->setIsFrightened();
                    break;
                    case 2:
                        this->pink->set_X(this->pink->get_X_init());
                        this->pink->set_Y(this->pink->get_Y_init());
                        this->pink->setIsFrightened();
                    break;
                    case 3:
                        this->orange->set_X(this->orange->get_X_init());
                        this->orange->set_Y(this->orange->get_Y_init());
                        this->orange->setIsFrightened();
                }
            }
        }
    }
    //verifica qual direção o jogador está pressionando
    walls[0] = map_collision(0, 0, PACMAN_SPEED + this->pacman->get_X(), this->pacman->get_Y(), this->map_sketch);
	walls[1] = map_collision(0, 0, this->pacman->get_X(), this->pacman->get_Y() - PACMAN_SPEED, this->map_sketch);
	walls[2] = map_collision(0, 0, this->pacman->get_X() - PACMAN_SPEED, this->pacman->get_Y(), this->map_sketch);
	walls[3] = map_collision(0, 0, this->pacman->get_X(), PACMAN_SPEED + this->pacman->get_Y(), this->map_sketch);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (!walls[2])
		{
			this->pacman->setDirection(2);
		}
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        if (!walls[1])
		{
			this->pacman->setDirection(1);
		}
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		if (!walls[3])
		{
			 this->pacman->setDirection(3);
		}
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        if (!walls[0]) //You can't turn in this direction if there's a wall there.
		{
			this->pacman->setDirection(0);
		}
	}
    if(0 == walls[this->pacman->getDirection()]) {
        this->pacman->mover(&this->map_sketch);
        this->pacman->comer(&this->map_sketch);
    }
    distances = this->verifyDistances();
    for(int i = 0; i<4; i++){
        if(distances[i]<=1){
            if(!this->pacman->getInvencibility()){
                this->pacman->lose_life();
                this->pacman->set_X(this->pacman->get_X_init() +1);
                this->pacman->set_Y(this->pacman->get_Y_init() +1);
                this->pacman->setDirection(0);
            }else{
                this->pacman->sumScore();
                switch(i){
                    case 0:
                        this->red->set_X(this->red->get_X_init());
                        this->red->set_Y(this->red->get_Y_init());
                        this->red->setIsFrightened();
                    break;
                    case 1:
                        this->blue->set_X(this->blue->get_X_init());
                        this->blue->set_Y(this->blue->get_Y_init());
                        this->blue->setIsFrightened();
                    break;
                    case 2:
                        this->pink->set_X(this->pink->get_X_init());
                        this->pink->set_Y(this->pink->get_Y_init());
                        this->pink->setIsFrightened();
                    break;
                    case 3:
                        this->orange->set_X(this->orange->get_X_init());
                        this->orange->set_Y(this->orange->get_Y_init());
                        this->orange->setIsFrightened();
                }
            }
        }
    }
}


void Game::updateGhost(){
    if(this->pacman->getInvencibility() != this->pacmanSituation){
        this->pacmanSituation = !(this->pacmanSituation);
        if(this->pacman->getInvencibility()){
            this->red->setIsFrightened();
            this->blue->setIsFrightened();
            this->pink->setIsFrightened();
            this->orange->setIsFrightened();
        }
    }
    this->red->mover(&this->map_sketch);
    this->blue->mover(&this->map_sketch);
    this->pink->mover(&this->map_sketch);
    this->orange->mover(&this->map_sketch);
}

void Game::updateText(){
    //atualiza o placar com a pontuação e vida atual
    std::stringstream ss;

    ss << "Points: " << this->pacman->get_score() << " Lifes: " << this->pacman->get_lifes();

    this->uiText.setString(ss.str());
}

void Game::renderMap(sf::RenderTarget& target){
{
    //desenha o mapa na janela a partir do racunho
    //cria blocos retangulares - paredes
    sf::RectangleShape cell_shape(sf::Vector2f(CELL_SIZE,CELL_SIZE));
	//cria blocos redondos grandes - drogas
    sf::CircleShape drug(3);
    //cria blocos redondos pequenos - food
    sf::CircleShape food(2);

	for (short i = 0; i < MAP_HEIGHT; i++){
		for (short j = 0; j < MAP_WIDTH; j++){
			cell_shape.setPosition(static_cast<float>(CELL_SIZE * j), static_cast<float>(CELL_SIZE * i));

			switch (this->map_sketch[i][j]->get_type()){
				case Type::door:
					cell_shape.setFillColor(sf::Color(36,36,100));
                    this->window->draw(cell_shape);
					break;
				case Type::drug:
					drug.setFillColor(sf::Color(255,0,0));
                    drug.setPosition(static_cast<float>((CELL_SIZE * j) + ((CELL_SIZE)/2 -2)), static_cast<float>((CELL_SIZE * i) + (CELL_SIZE/2 - 2)));
					this->window->draw(drug);
					break;
				case Type::food:
					food.setFillColor(sf::Color(255,255,255));
                    food.setPosition(static_cast<float>((CELL_SIZE * j) + ((CELL_SIZE)/2 -2)), static_cast<float>((CELL_SIZE * i) + (CELL_SIZE/2 -2)));
					this->window->draw(food);
					break;
				case Type::wall:
					cell_shape.setFillColor(sf::Color(36,36,255));
					this->window->draw(cell_shape);
                    break;
                case Type::pacman:
                    this->renderPacman(*this->window);
                    break;
                case Type::red:
                    this->renderGhost(*this->window,0);
                    break;
                case Type::blue:
                    this->renderGhost(*this->window,1);
                    break;
                case Type::pink:
                    this->renderGhost(*this->window,2);
                    break;
                case Type::orange:
                    this->renderGhost(*this->window,3);
                    break;
                default:
                    break;
                }
			}
		}
	}
}

void Game::renderPacman(sf::RenderTarget& target){
    //desenha o pacman
    sf::CircleShape PelletEater(7);
	PelletEater.setFillColor(sf::Color(255,255,0));
    PelletEater.setPosition(static_cast<float>(this->pacman->get_X() * CELL_SIZE), static_cast<float>(this->pacman->get_Y() * CELL_SIZE));
    target.draw(PelletEater);
}

void Game::renderGhost(sf::RenderTarget& target, int id){
    sf::RectangleShape rectangle(sf::Vector2f(15.f, 15.f));
    if(this->pacmanSituation) rectangle.setFillColor(sf::Color(0,100,0));
    switch (id){
        case 0:
            if(!this->pacmanSituation) rectangle.setFillColor(sf::Color(255,1,1));
            rectangle.setPosition(static_cast<float>(this->red->get_X() * CELL_SIZE), static_cast<float>(this->red->get_Y() * CELL_SIZE));
            break;
        case 1:
            if(!this->pacmanSituation) rectangle.setFillColor(sf::Color(100,100,255));
            rectangle.setPosition(static_cast<float>(this->blue->get_X() * CELL_SIZE), static_cast<float>(this->blue->get_Y() * CELL_SIZE));
            break;
        case 2:
            if(!this->pacmanSituation) rectangle.setFillColor(sf::Color(255,192,202));
            rectangle.setPosition(static_cast<float>(this->pink->get_X() * CELL_SIZE), static_cast<float>(this->pink->get_Y() * CELL_SIZE));
            break;
        case 3:
            if(!this->pacmanSituation) rectangle.setFillColor(sf::Color(255,140,0));
            rectangle.setPosition(static_cast<float>(this->orange->get_X() * CELL_SIZE), static_cast<float>(this->orange->get_Y() * CELL_SIZE));
            break;
    }
    target.draw(rectangle);
}

void Game::renderText(sf::RenderTarget& target){
    //desenha o placar
    target.draw(this->uiText);
}

void Game::renderGameOver(sf::RenderTarget& target){
    //desenha a tela de game over
    target.draw(this->GOText);
}

void Game::render(){
    //desenha o jogo
    this->window->clear();

    this->renderMap(*this->window);
    this->renderText(*this->window);

    if(this->getEndGame()){
        this->window->clear();
        //ainda mudarei o que está em baixo para uma função específica
        this->renderGameOver(*this->window);
        this->uiText.setFillColor(sf::Color::Green);
        this->uiText.setOutlineColor(sf::Color::White);
        this->uiText.setOutlineThickness(1);
        this->uiText.setPosition(35, 250);
        this->uiText.setScale(2,2);
        this->renderText(*this->window);
    }

    this->window->display();
}