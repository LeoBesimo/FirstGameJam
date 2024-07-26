#include "Game.hpp"

Game::Game()
{
}

Game::~Game()
{
}

void Game::update(float dt)
{
	BaseApplication::update(dt);
	std::cout << "From Derived Class\n";
}

void Game::render()
{
	m_Window->line(900, 100, 300, 800);

	m_Window->rect(100, 100, 100, 100);

	m_Window->line(400, 500, 600, 300);
}
