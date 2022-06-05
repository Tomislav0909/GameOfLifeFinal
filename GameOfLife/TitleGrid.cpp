#include "TitleGrid.h"

TitleGrid::TitleGrid()
{
	this->initTitleGrid();
}

void TitleGrid::renderTitleGrid(sf::RenderTarget& target)
{
	for (auto& row : this->titleGrid)
		for (auto& i : row)
			target.draw(i);
}

void TitleGrid::updateTitleGrid()
{
	if (this->colorIndex < 4)
		this->colorIndex++;
	else
		this->colorIndex = 0;
	drawTitle(30, 8, this->colors[colorIndex]);
}

void TitleGrid::initTitleGrid()
{
	for (float i = 0; i < 80; i++)
	{
		std::vector<sf::RectangleShape> v;
		for (float j = 0; j < 60; j++)
		{
			auto square = createSquare(10 * i, 10 * j, sf::Color::Black);
			v.push_back(square);
		}
		this->titleGrid.push_back(v);
	}
	drawTitle(30, 8, sf::Color::Green);
}

sf::RectangleShape TitleGrid::createSquare(float posX, float posY, sf::Color c)
{
	sf::RectangleShape square;
	square.setPosition(sf::Vector2f(posX, posY));
	square.setFillColor(c);
	square.setSize(sf::Vector2f(10.f, 10.f));
	square.setOutlineColor(sf::Color::White);
	square.setOutlineThickness(1.f);
	return square;
}

int TitleGrid::drawLetterG(int x, int y, sf::Color c)
{
	titleGrid[x][y].setFillColor(c);
	titleGrid[x + 1][y].setFillColor(c);
	titleGrid[x + 2][y].setFillColor(c);

	y++;
	titleGrid[x - 1][y].setFillColor(c);

	y++;
	titleGrid[x - 1][y].setFillColor(c);
	titleGrid[x + 1][y].setFillColor(c);
	titleGrid[x + 2][y].setFillColor(c);

	y++;
	titleGrid[x - 1][y].setFillColor(c);
	titleGrid[x + 2][y].setFillColor(c);

	y++;
	titleGrid[x][y].setFillColor(c);
	titleGrid[x + 1][y].setFillColor(c);
	titleGrid[x + 2][y].setFillColor(c);

	return x + 3;
}

int TitleGrid::drawLetterA(int x, int y, sf::Color c)
{
	titleGrid[x][y].setFillColor(c);
	titleGrid[x + 1][y].setFillColor(c);

	y++;
	titleGrid[x - 1][y].setFillColor(c);
	titleGrid[x + 2][y].setFillColor(c);

	y++;
	titleGrid[x - 1][y].setFillColor(c);
	titleGrid[x][y].setFillColor(c);
	titleGrid[x + 1][y].setFillColor(c);
	titleGrid[x + 2][y].setFillColor(c);

	y++;
	titleGrid[x - 1][y].setFillColor(c);
	titleGrid[x + 2][y].setFillColor(c);

	y++;
	titleGrid[x - 1][y].setFillColor(c);
	titleGrid[x + 2][y].setFillColor(c);

	return x + 3;
}

int TitleGrid::drawLetterM(int x, int y, sf::Color c)
{
	titleGrid[x][y].setFillColor(c);
	titleGrid[x + 4][y].setFillColor(c);

	y++;
	titleGrid[x][y].setFillColor(c);
	titleGrid[x + 1][y].setFillColor(c);
	titleGrid[x + 3][y].setFillColor(c);
	titleGrid[x + 4][y].setFillColor(c);

	y++;
	titleGrid[x][y].setFillColor(c);
	titleGrid[x + 2][y].setFillColor(c);
	titleGrid[x + 4][y].setFillColor(c);

	y++;
	titleGrid[x][y].setFillColor(c);
	titleGrid[x + 4][y].setFillColor(c);

	y++;
	titleGrid[x][y].setFillColor(c);
	titleGrid[x + 4][y].setFillColor(c);

	return x + 5;
}

int TitleGrid::drawLetterE(int x, int y, sf::Color c)
{
	titleGrid[x][y].setFillColor(c);
	titleGrid[x + 1][y].setFillColor(c);
	titleGrid[x + 2][y].setFillColor(c);
	titleGrid[x + 3][y].setFillColor(c);

	y++;
	titleGrid[x][y].setFillColor(c);

	y++;
	titleGrid[x][y].setFillColor(c);
	titleGrid[x + 1][y].setFillColor(c);
	titleGrid[x + 2][y].setFillColor(c);

	y++;
	titleGrid[x][y].setFillColor(c);

	y++;
	titleGrid[x][y].setFillColor(c);
	titleGrid[x + 1][y].setFillColor(c);
	titleGrid[x + 2][y].setFillColor(c);
	titleGrid[x + 2][y].setFillColor(c);
	titleGrid[x + 3][y].setFillColor(c);

	return x + 4;
}

int TitleGrid::drawLetterO(int x, int y, sf::Color c)
{
	titleGrid[x][y].setFillColor(c);
	titleGrid[x + 1][y].setFillColor(c);

	y++;
	titleGrid[x - 1][y].setFillColor(c);
	titleGrid[x + 2][y].setFillColor(c);

	y++;
	titleGrid[x - 1][y].setFillColor(c);
	titleGrid[x + 2][y].setFillColor(c);

	y++;
	titleGrid[x - 1][y].setFillColor(c);
	titleGrid[x + 2][y].setFillColor(c);

	y++;
	titleGrid[x][y].setFillColor(c);
	titleGrid[x + 1][y].setFillColor(c);

	return x + 3;
}

int TitleGrid::drawLetterF(int x, int y, sf::Color c)
{
	titleGrid[x][y].setFillColor(c);
	titleGrid[x + 1][y].setFillColor(c);
	titleGrid[x + 2][y].setFillColor(c);
	titleGrid[x + 3][y].setFillColor(c);

	y++;
	titleGrid[x][y].setFillColor(c);

	y++;
	titleGrid[x][y].setFillColor(c);
	titleGrid[x + 1][y].setFillColor(c);
	titleGrid[x + 2][y].setFillColor(c);

	y++;
	titleGrid[x][y].setFillColor(c);

	y++;
	titleGrid[x][y].setFillColor(c);

	return x + 4;
}

int TitleGrid::drawLetterL(int x, int y, sf::Color c)
{
	titleGrid[x][y].setFillColor(c);

	y++;
	titleGrid[x][y].setFillColor(c);

	y++;
	titleGrid[x][y].setFillColor(c);

	y++;
	titleGrid[x][y].setFillColor(c);

	y++;
	titleGrid[x][y].setFillColor(c);
	titleGrid[x + 1][y].setFillColor(c);
	titleGrid[x + 2][y].setFillColor(c);

	return x + 3;
}

int TitleGrid::drawLetterI(int x, int y, sf::Color c)
{
	titleGrid[x][y].setFillColor(c);

	y++;
	titleGrid[x][y].setFillColor(c);

	y++;
	titleGrid[x][y].setFillColor(c);

	y++;
	titleGrid[x][y].setFillColor(c);

	y++;
	titleGrid[x][y].setFillColor(c);

	return x + 1;
}

void TitleGrid::drawTitle(int x, int y, sf::Color c)
{
	int g = drawLetterG(x, y, c);
	int a = drawLetterA(g + 2, y, c);
	int m = drawLetterM(a + 1, y, c);
	int e = drawLetterE(m + 1, y, c);
	int o = drawLetterO(x + 6, y + 20, c);
	int f = drawLetterF(o + 1, y + 20, c);
	int l = drawLetterL(x + 2, y + 40, c);
	int i = drawLetterI(l + 1, y + 40, c);
	int _f = drawLetterF(i + 1, y + 40, c);
	int _e = drawLetterE(_f + 1, y + 40, c);
}