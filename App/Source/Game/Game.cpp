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

	m_PhysicsRect.setMass(1);
	m_PhysicsRect.setPosition(Core::Math::Vector2(300,300));
	m_PhysicsRect.setSize(Core::Math::Vector2(40, 80));
	m_PhysicsRect.setVelocity(Core::Math::Vector2(50, 0));
	m_PhysicsRect.setGravity(Core::Math::Vector2(0, 100));

}

Game::~Game()
{
}

void Game::update(float dt)
{
	BaseApplication::update(dt);
	//std::cout << "From Derived Class\n";$
	m_PhysicsRect.update(dt);
}

void Game::render()
{
	m_Window->line(900, 100, 300, 800);

	std::vector<Core::Math::Vector2> corners = m_PhysicsRect.getCorners();

	for (unsigned int i = 0; i < corners.size(); i++)
	{
		m_Window->line(corners[i].x, corners[i].y, corners[(i + 1) % corners.size()].x, corners[(i + 1) % corners.size()].y);
	}

	m_Window->loadSpritesheet("Textures/testcharacter.png");
	m_Window->loadTexture(0, 0, 16, 32);
	m_testSprite.setColor(sf::Color(255, 0, 255, 128));
	m_Window->drawSprite(m_testSprite, 300, 300, 10);

	//m_Window->rect(100, 100, 160, 320);

	m_Window->line(400, 500, 600, 300);

	m_Window->text(150, 200, "Hello World!", 24);
}
