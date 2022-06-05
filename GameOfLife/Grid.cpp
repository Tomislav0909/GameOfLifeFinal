#include "Grid.h"

Grid::Grid()
{
	srand(time(nullptr));
	this->initGrid();
	this->counter = 0;
}

void Grid::initGrid()
{
	for (float i = 0; i < 80; i++)
	{
		std::vector<sf::RectangleShape> v;
		for (float j = 0; j < 60; j++)
		{
			if (gen_rnd(1, 4) == 4)
			{
				auto square = createSquare(i * 10, j * 10, sf::Color::Green);
				v.push_back(square);
			}
			else
			{
				auto square = createSquare(i * 10, j * 10, sf::Color::Black);
				v.push_back(square);
			}
		}
		this->grid.push_back(v);
	}
}

void Grid::renderGrid(sf::RenderTarget& target)
{
	for (auto& row : grid)
		for (auto& i : row)
			target.draw(i);
}

void Grid::updateGrid()
{
	system("cls");
	std::cout << ++counter << std::endl;
	neighboursAlive.clear();
	loadNeighboursAlive();
	for (int i = 0; i < 80; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			if ((neighboursAlive[i][j] == 2 || neighboursAlive[i][j] == 3) && grid[i][j].getFillColor() != sf::Color::Black)
				grid[i][j].setFillColor(colors[colorIndex]);
			if ((neighboursAlive[i][j] < 2 || neighboursAlive[i][j] > 3) && grid[i][j].getFillColor() != sf::Color::Black)
				grid[i][j].setFillColor(sf::Color::Black);
			if ((neighboursAlive[i][j] == 3) && grid[i][j].getFillColor() == sf::Color::Black)
				grid[i][j].setFillColor(colors[colorIndex]);
		}
	}
}

void Grid::loadNeighboursAlive()
{
	for (int i = 0; i < 80; i++)
	{
		std::vector<int> v;
		for (int j = 0; j < 60; j++)
			v.push_back(checkCell(i, j));
		neighboursAlive.push_back(v);
	}
	if (colorIndex < 4) colorIndex++;
	else colorIndex = 0;
}

int Grid::checkCell(int x, int y)
{
	int counter = 0;
	for (auto& pos : checkingMatrix)
		if (isValidX(pos[0] + x) && isValidY(pos[1] + y) && grid[pos[0] + x][pos[1] + y].getFillColor() == colors[colorIndex])
			counter++;
	return counter;
}

bool Grid::isValidX(int x)
{
	if (x < 0 || x >= 80) return false;
	return true;
}
bool Grid::isValidY(int y)
{
	if (y < 0 || y >= 60) return false;
	return true;
}

sf::RectangleShape Grid::createSquare(float posX, float posY, sf::Color c)
{
	sf::RectangleShape square;
	square.setPosition(sf::Vector2f(posX, posY));
	square.setFillColor(c);
	square.setSize(sf::Vector2f(10.f, 10.f));
	square.setOutlineColor(sf::Color::White);
	square.setOutlineThickness(1.f);
	return square;
}

int Grid::gen_rnd(int min, int max)
{
	return rand() % (max - min + 1) + min;
}