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
