#include "Game.h"

Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
	delete this->grid;
	delete this->titleGrid;
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

void Game::initVariables()
{
	this->window = nullptr;
	this->grid = new Grid;
	this->titleGrid = new TitleGrid;
	this->goToGrid = false;
}

void Game::initWindow()
{
	this->videoMode.width = 800;
	this->videoMode.height = 600;
	this->window = new sf::RenderWindow(this->videoMode, "Game of life", sf::Style::Close | sf::Style::Titlebar);
}

void Game::update()
{
	this->updatePollEvents();
	if (this->titleClock.getElapsedTime().asSeconds() < 12)
	{
		if (this->clock.getElapsedTime().asSeconds() > 2)
		{
			this->titleGrid->updateTitleGrid();
			this->clock.restart();
		}
	}
	else
	{
		if (this->clock.getElapsedTime().asSeconds() > 2)
		{
			this->grid->updateGrid();
			this->clock.restart();
		}
	}
}

void Game::updatePollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::render()
{
	this->window->clear();
	if (this->titleClock.getElapsedTime().asSeconds() < 10)
		this->titleGrid->renderTitleGrid(*this->window);
	else
	{
		this->grid->renderGrid(*this->window);
	}
	this->window->display();
}