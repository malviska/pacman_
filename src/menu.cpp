#include "../include/menu.hpp"

Menu::Menu(){
    window = new sf::RenderWindow();
    font = new sf::Font();
    image = new sf::Texture();
    bg = new sf::Sprite();

    set_values();
}

Menu::~Menu(){
    delete window;
    delete font;
    delete image;
    delete bg;
}

void Menu::set_values(){
    window->create(sf::VideoMode(720, 600), "Pacman", sf::Style::Titlebar | sf::Style::Close);
    window->setPosition(sf::Vector2i(350,90));

    pos = 0;
    pressed = theselect = false;

    font->loadFromFile("./data/ethn.otf");
    image->loadFromFile("./data/background.png");
    bg->setTexture(*image);

    options = {"Jogar", "Opcoes", "Recordes", "Sair"};
    texts.resize(4);
    coords = {{300, 250}, {300, 330}, {280, 410}, {330, 490}};
    sizes = {28, 24, 24, 24};

    for (std::size_t i{}; i < texts.size(); ++i){
        texts[i].setFont(*font);
        texts[i].setString(options[i]);
        texts[i].setCharacterSize(sizes[i]);
        texts[i].setOutlineColor(sf::Color::Blue);
        texts[i].setPosition(coords[i]);
    }

    texts[0].setOutlineThickness(4);
    pos = 0;
}

void Menu::loop_events(){

    sf::Event event;

    while(window->pollEvent(event)){

        if(event.type == sf::Event::Closed){
            window->close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed){
            if(pos < 3){
                ++pos;
                pressed = true;
                texts[pos].setOutlineThickness(4);
                texts[pos - 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed){
            if(pos > 0){
                --pos;
                pressed = true;
                texts[pos].setOutlineThickness(4);
                texts[pos + 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect){
            theselect = true;

            if(pos == 0){

            }

            if(pos == 1){
                
            }

            if(pos == 2){
                
            }

            if(pos == 3){
                window->close();
            }
        }
    }
}

void Menu::draw_all(){

    window->clear();

    window->draw(*bg);

    for(auto t : texts){
        window->draw(t);
    }

    window->display();
}

void Menu::run_menu(){

    while(window->isOpen()){

        loop_events();

        draw_all();
    }
}