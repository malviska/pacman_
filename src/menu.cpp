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
    window->create(sf::VideoMode(1360, 768), "Menu SFML", sf::Style::Titlebar | sf::Style::Close);
    window->setPosition(sf::Vector2i(0,0));

    pos = 0;
    pressed = theselect = false;

    font -> loadFromFile("../assets/ethn.otf");

    image -> loadFromFile("../assets/background.png");

    bg->setTexture(*image);

    pos_mouse = {0,0};
    mouse_coord = {0,0};

    options = {"Pacman", "Jogar", "Opções", "Recordes", "Sair"};
    texts.resize(5);
    coords = {{590, 40}, {610, 191}, {590, 282}, {600, 370}, {623, 457}};
    sizes = {38, 28, 24, 24, 24};

    for (std::size_t i{}; i < texts.size(); i++){
        texts[i].setPosition(coords[i]);
        texts[i].setFont(*font);
        texts[i].setString(options[i]);
        texts[i].setCharacterSize(sizes[i]);
        texts[i].setOutlineColor(sf::Color::Black);
    }

    texts[1].setOutlineThickness(4);
    pos = 1;
}

void Menu::loop_events(){
    sf::Event event;
    while(window->pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window->close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed){
            if(pos < 4){
                ++pos;
                pressed = true;
                texts[pos].setOutlineThickness(4);
                texts[pos - 1].setOutlineThickness(0);
                pressed = false;
                theselect = false;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed){
            if(pos > 1){
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

            if(pos == 4){
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