#pragma once

#include "stdafx.h"

class Grid
{
public:
	Grid();
	void renderGrid(sf::RenderTarget& target);
	void updateGrid();
private:
	void initGrid();

    // Rand num generator used for 25% chance of cell being alive
    int gen_rnd(int min, int max);
    
    void loadNeighboursAlive();
    std::vector<std::vector<int>> neighboursAlive;
    std::vector<std::vector<int>> checkingMatrix
    {
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, -1},
        {0, 1},
        {1, -1},
        {1, 0},
        {1, 1}
    };

    int checkCell(int x, int y);

    bool isValidX(int x);
    bool isValidY(int y);

    std::vector<std::vector<sf::RectangleShape>> grid;
    sf::RectangleShape createSquare(float posX, float posY, sf::Color c);

    // Colors
    std::vector<sf::Color> colors = { sf::Color::Green, sf::Color::Red, sf::Color(30, 144, 255), sf::Color::Yellow, sf::Color::White };
    int colorIndex;

    // Counting game changes
    int counter;
};