#ifndef GAME_H
#define GAME_H

#include "map.hpp"
#include <sstream>
#include <SFML/Graphics.hpp>

class Game{
    private:
        sf::RenderWindow *window;
        sf::VideoMode video_mode;
        sf::Event ev;
    
        sf::Font font;
        
        sf::Text uiText;
        sf::Text GOText;

        Pacman *pacman;
        std::ifstream File;
        Mapa map_sketch;

        void initWindow();
        void initPacman();
        void initText();
        void initFonts();
    public:
        Game();
        virtual ~Game();

        const bool running() const;  
        bool getEndGame();

        void pollEvents();
        void updatePacman();
        void updateText();
        void update();


        void renderMap(sf::RenderTarget& target);
        void renderPacman(sf::RenderTarget& target);
        void renderText(sf::RenderTarget& target);
        void renderGameOver(sf::RenderTarget& target);
        void render();   

};

#endif