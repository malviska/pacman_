#include"pacman.hpp"
#include<SFML/Graphics.hpp>

void Pacman::drawPacman(sf::RenderWindow& _window){
    sf::CircleShape PelletEater(7);
	PelletEater.setFillColor(sf::Color(255,255,0));
    PelletEater.setPosition(static_cast<float>(this->getX() +2), static_cast<float>(this->getY() + 2));
    _window.draw(PelletEater);
}

void Pacman::update(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) this->move(3);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) this->move(1);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) this->move(2) ;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) this->move(0);
}


