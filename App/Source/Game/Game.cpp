#include "Game.hpp"

Game::Game()
{
	m_TextureLoader.loadSpritesheet("test", "Textures/testcharacter.png");
	m_TextureLoader.getSprite(m_testSprite, "test", 0, 0, 16, 32);
	//m_testSprite = m_TextureLoader.getSprite("test", 0, 0, 16, 32);

	m_AudioManager.loadSound("test", "Audio/testsound.wav");
	//m_AudioManager.playSound(m_testSound, "test");

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
			m_AudioManager.playSound("test");
		});

	m_EventHandler.addMouseCallback(Core::Mouse::RIGHT, [&]()
		{
			std::cout << "On Hold Right\n";
			m_AudioManager.playSound("test");
		}, true);

	m_EventHandler.addKeyCallback(Core::Keyboard::SPACE, [&]()
		{
			std::cout << m_MousePosition.x << " " << m_MousePosition.y << "\n";
		}, false);

	//m_PhysicsRect = m_PhysicsWorld.addBody(Core::Math::Vector2(300, 300), Core::Physics::ColliderType::RECT);


	m_PhysicsRect = std::dynamic_pointer_cast<Core::Physics::RectangleShape>(m_PhysicsWorld.addBody(Core::Math::Vector2(300,300), Core::Physics::ColliderType::RECT));

	std::dynamic_pointer_cast<Core::Physics::RectangleShape>(m_PhysicsWorld.addBody(Core::Math::Vector2(500, 500), Core::Physics::ColliderType::RECT))->setSize(Core::Math::Vector2(100,100));

	m_PhysicsRect->setMass(1);
	m_PhysicsRect->setPosition(Core::Math::Vector2(300,300));
	m_PhysicsRect->setSize(Core::Math::Vector2(40, 80));
	m_PhysicsRect->setVelocity(Core::Math::Vector2(50, 0));
	m_PhysicsRect->setGravity(Core::Math::Vector2(0, 100));
	m_PhysicsRect->setOnCollisionFunction([&]()
		{
			m_Window->stroke(255, 0, 0, 255);
		});

}

Game::~Game()
{
}

void Game::update(float dt)
{
	BaseApplication::update(dt);
	m_PhysicsRect->setPosition(m_MousePosition);
	//std::cout << "From Derived Class\n";$
}

void Game::render()
{
	m_Window->line(900, 100, 300, 800);	

	m_Window->loadSpritesheet("Textures/testcharacter.png");
	m_Window->loadTexture(0, 0, 16, 32);
	m_testSprite.setColor(sf::Color(255, 0, 255, 128));
	m_Window->drawSprite(m_testSprite, 300, 300, 10);

	//m_Window->rect(100, 100, 160, 320);

	m_Window->line(400, 500, 600, 300);

	m_Window->text(150, 200, "Hello World!", 24);
}
