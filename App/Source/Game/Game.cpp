#include "Game.hpp"

Game::Game()
{
	m_TextureLoader.loadSpritesheet("test", "Textures/testcharacter.png");
	m_TextureLoader.getSprite(m_testSprite, "test", 0, 0, 16, 32);
	//m_testSprite = m_TextureLoader.getSprite("test", 0, 0, 16, 32);

	m_EventHandler.addKeyCallback(Core::Keyboard::W, [&]()
		{
			std::cout << "W key Pressed\n";
			m_Window->moveView(0, -0.1f);
		});

	m_EventHandler.addKeyCallback(Core::Keyboard::A, [&]()
		{
			std::cout << "A key Pressed\n";
			m_Window->moveView(-0.1f, 0);
		});

	m_EventHandler.addKeyCallback(Core::Keyboard::S, [&]()
		{
			std::cout << "S key Pressed\n";
			m_Window->moveView(0, 0.1f);
		});

	m_EventHandler.addKeyCallback(Core::Keyboard::D, [&]()
		{
			std::cout << "D key Pressed\n";
			m_Window->moveView(0.1f, 0);
		});

	m_EventHandler.addMouseCallback(Core::Mouse::LEFT, [&]()
		{
			std::cout << "On Press Left\n";
		});

	m_EventHandler.addMouseCallback(Core::Mouse::RIGHT, [&]()
		{
			std::cout << "On Hold Right\n";
		}, true);

	m_EventHandler.addKeyCallback(Core::Keyboard::SPACE, [&]()
		{
			std::cout << m_MousePosition.x << " " << m_MousePosition.y << "\n";
		}, false);
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

	m_Window->loadSpritesheet("Textures/testcharacter.png");
	m_Window->loadTexture(0, 0, 16, 32);
	m_Window->drawSprite(m_testSprite, 300, 300, 10);

	//m_Window->rect(100, 100, 160, 320);

	m_Window->line(400, 500, 600, 300);

	m_Window->text(150, 200, "Hello World!", 24);
}
