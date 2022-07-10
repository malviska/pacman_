#ifndef GAME_H
#define GAME_H

#include "map.hpp"
#include <chrono>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "ghosts.hpp"
#include"collision.hpp"

class Game{
    private:
        sf::RenderWindow *window;
        sf::VideoMode video_mode;
        sf::Event ev;
    
        sf::Font font;
        
        sf::Text uiText;
        sf::Text GOText;
        Pacman *pacman;
        Ghost *red;
        Ghost *blue;
        Ghost *pink;
        Ghost *orange;
        std::ifstream File;
        Mapa map_sketch;
        bool pacmanSituation = false;

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
        void updateGhost();
        void updateText();
        void update();


        void renderMap(sf::RenderTarget& target);
        void renderPacman(sf::RenderTarget& target);
        void renderGhost(sf::RenderTarget& target, int ghost);
        void renderText(sf::RenderTarget& target);
        void renderGameOver(sf::RenderTarget& target);
        void render();   
        double distance(Pacman&, Ghost&);
        std::array<double, 4> verifyDistances();

};

#endif