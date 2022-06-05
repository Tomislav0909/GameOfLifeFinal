#pragma once

#include "stdafx.h"

class TitleGrid
{
public:
    TitleGrid();
    void renderTitleGrid(sf::RenderTarget& target);
    void updateTitleGrid();
private:
    void initTitleGrid();

    std::vector<std::vector<sf::RectangleShape>> titleGrid;

    sf::RectangleShape createSquare(float posX, float posY, sf::Color c);

    std::vector<sf::Color> colors = { sf::Color::Green, sf::Color::Red, sf::Color(30, 144, 255), sf::Color::Yellow, sf::Color::White};
    int colorIndex;   

	int drawLetterG(int x, int y, sf::Color c);
	int drawLetterA(int x, int y, sf::Color c);
	int drawLetterM(int x, int y, sf::Color c);
	int drawLetterE(int x, int y, sf::Color c);
	int drawLetterO(int x, int y, sf::Color c);
	int drawLetterF(int x, int y, sf::Color c);
	int drawLetterL(int x, int y, sf::Color c);
	int drawLetterI(int x, int y, sf::Color c);

	void drawTitle(int x, int y, sf::Color c);
};