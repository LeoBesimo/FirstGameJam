#include "Game.hpp"

Game::Game()
{
	m_EventHandler.addKeyCallback(Core::Keyboard::A, [&]()
		{
			std::cout << "A key Pressed\n";
		});

	m_EventHandler.addKeyCallback(Core::Keyboard::B, [&]()
		{
			std::cout << "B key Pressed\n";
		});
}

Game::~Game()
{
}

void Game::update(float dt)
{
	BaseApplication::update(dt);
	//std::cout << "From Derived Class\n";
}

void Game::render()
{
	m_Window->line(900, 100, 300, 800);

	m_Window->rect(100, 100, 100, 100);

	m_Window->line(400, 500, 600, 300);

	m_Window->text(150, 200, "Hello World!", 24);
}
