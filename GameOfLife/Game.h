#pragma once

#include "Grid.h"
#include "TitleGrid.h"

class Game
{
public:
    Game();
    ~Game();
    void run();
private:
    // Window
    void initVariables();
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;
    void initWindow();

    void update();
    void render();
    void updatePollEvents();

    // Grid
    Grid* grid;
    TitleGrid* titleGrid;
    bool goToGrid;

    // Clock
    sf::Clock clock;
    sf::Clock titleClock;

};