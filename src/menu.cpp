#include "../include/menu.hpp"
#include "../include/game.hpp"

Menu::Menu(){
    this->window = new sf::RenderWindow();

    this->font = new sf::Font();
    this->image = new sf::Texture();
    this->bg = new sf::Sprite();

    set_values();
}

Menu::~Menu(){
    delete this->window;
    delete this->font;
    delete this->image;
    delete this->bg;
}

void Menu::init_screen(){
    this->window->create(sf::VideoMode(720, 550), "Pacman", sf::Style::Titlebar | sf::Style::Close);
    this->window->setPosition(sf::Vector2i(350,90));

    this->font->loadFromFile("./data/ethn.otf");
    this->image->loadFromFile("./data/background.png");
    this->bg->setTexture(*this->image);
}

void Menu::set_values(){
    this->init_screen();

    this->pos = 0;

    this->pressed = this->theselect = false;

    this->options = {"Jogar", "Recordes", "Sair"};
    this->texts.resize(3);
    this->coords = {{300, 250}, {280, 330}, {330, 410}};
    this->sizes = {28, 24, 24};

    for (std::size_t i{}; i < this->texts.size(); ++i){
        this->texts[i].setFont(*this->font);
        this->texts[i].setString(this->options[i]);
        this->texts[i].setCharacterSize(this->sizes[i]);
        this->texts[i].setOutlineColor(sf::Color::Blue);
        this->texts[i].setPosition(this->coords[i]);
    }

    this->texts[0].setOutlineThickness(4);
    this->pos = 0;
}

void Menu::loop_events(){
    sf::Event event;

    while(this->window->pollEvent(event)){

        if(event.type == sf::Event::Closed){
            this->window->close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !this->pressed){
            if(this->pos < 3){
                ++this->pos;
                this->pressed = true;
                this->texts[this->pos].setOutlineThickness(4);
                this->texts[this->pos - 1].setOutlineThickness(0);
                this->pressed = false;
                this->theselect = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !this->pressed){
            if(this->pos > 0){
                --this->pos;
                this->pressed = true;
                this->texts[this->pos].setOutlineThickness(4);
                this->texts[this->pos + 1].setOutlineThickness(0);
                this->pressed = false;
                this->theselect = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !this->theselect){
            this->theselect = true;

            if(pos == 0){
                Game game;
                this->window->close();
                while (game.running())
                {
                    game.update();
                    game.render();
                }
                this->set_values();
            }

            if(this->pos == 1){
                
            }

            if(this->pos == 2){
                this->window->close();
            }
        }
    }
}

void Menu::draw_all(){
    this->window->clear();

    this->window->draw(*this->bg);

    for(auto t : this->texts){
        this->window->draw(t);
    }

    this->window->display();
}

void Menu::run_menu(){
    while(this->window->isOpen()){

        this->loop_events();

        this->draw_all();
    }
}