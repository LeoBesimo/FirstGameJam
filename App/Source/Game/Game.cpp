#include "Game.hpp"

Game::Game()
{
	m_TextureLoader.loadSpritesheet("character_1", "Textures/testcharacter.png");
	m_TextureLoader.defineTexture("character_1", "facing_east", 0, 0, 16, 32);
	m_TextureLoader.defineTexture("character_1", "facing_west", 32, 0, 16, 32);
	m_TextureLoader.defineTexture("character_1", "facing_up", 16, 0, 16, 32);
	m_TextureLoader.defineTexture("character_1", "facing_down", 48, 0, 16, 32);

	m_TextureLoader.setTexture(m_testSprite, "character_1", "facing_west");

	m_AnimationManager.loadAnimationsheet("testanimation", "Textures/Animations/testanimation.png");

	sf::Vector2i sheetSize(4, 1);
	sf::Vector2i frameSize(16, 16);
	sf::Vector2i currentFrame(0, 0);
	m_AnimationManager.addAnimation("walking_animation", "testanimation", sheetSize, frameSize, currentFrame, 0);
	
	m_SoundManager.addSound("testSound", "Audio/testsound.wav", 10);
	m_SoundManager.loadMusic("testMusic", "Audio/Music/testmusic.mp3");
	m_SoundManager.setMusicVolume(10);
	//m_SoundManager.playMusic("testMusic");

	m_EventHandler.addKeyCallback(Core::Keyboard::W, [&]()
		{
			m_Player->addForce(Core::Math::Vector2(0, -1000));
			m_TextureLoader.setTexture(m_testSprite, "character_1", "facing_up");
		});

	m_EventHandler.addKeyCallback(Core::Keyboard::A, [&]()
		{
			m_Player->addForce(Core::Math::Vector2(-1000, 0));
			m_TextureLoader.setTexture(m_testSprite, "character_1", "facing_west");
		});

	m_EventHandler.addKeyCallback(Core::Keyboard::S, [&]()
		{
			m_Player->addForce(Core::Math::Vector2(0, 1000));
			m_TextureLoader.setTexture(m_testSprite, "character_1", "facing_down");
		});

	m_EventHandler.addKeyCallback(Core::Keyboard::D, [&]()
		{
			m_Player->addForce(Core::Math::Vector2(1000, 0));
			m_TextureLoader.setTexture(m_testSprite, "character_1", "facing_east");
		});

	m_EventHandler.addMouseCallback(Core::Mouse::LEFT, [&]()
		{
			//m_SoundManager.playSound("testSound");
			m_AnimationManager.update("walking_animation", m_testAnimation);
		});

	m_EventHandler.addMouseCallback(Core::Mouse::RIGHT, [&]()
		{
		}, true);

	m_EventHandler.addKeyCallback(Core::Keyboard::SPACE, [&]()
		{
			std::cout << m_MousePosition.x << " " << m_MousePosition.y << "\n";
		}, false);

	//m_PhysicsRect = m_PhysicsWorld.addBody(Core::Math::Vector2(300, 300), Core::Physics::ColliderType::RECT);


	m_PhysicsRect = std::dynamic_pointer_cast<Core::Physics::RectangleShape>(m_PhysicsWorld.addBody(Core::Math::Vector2(300,300), Core::Physics::ColliderType::RECT));

	std::dynamic_pointer_cast<Core::Physics::RectangleShape>(m_PhysicsWorld.addBody(Core::Math::Vector2(500, 500), Core::Physics::ColliderType::RECT))->setSize(Core::Math::Vector2(100,100));
	m_PhysicsWorld.addBody(m_Player);

	m_PhysicsRect->setMass(0);
	m_PhysicsRect->setPosition(Core::Math::Vector2(300,300));
	m_PhysicsRect->setSize(Core::Math::Vector2(40, 80));
	//m_PhysicsRect->setVelocity(Core::Math::Vector2(50, 0));
	m_PhysicsRect->setGravity(Core::Math::Vector2(0, 100));
	m_PhysicsRect->setOnCollisionFunction([&](Core::Physics::Manifold manifold, std::shared_ptr<Core::Physics::PhysicsBody> self)
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
	//m_PhysicsRect->setPosition(m_MousePosition);
	//m_Window->setView(m_MousePosition.x, m_MousePosition.y);
	m_Player->addForce((m_MousePosition - m_Player->getPosition()).normalize() * 1500);
	m_Window->setView(m_Player->getPosition().x, m_Player->getPosition().y);
}

void Game::render()
{
	m_Window->line(900, 100, 300, 800);	

	m_Window->loadSpritesheet("Textures/testcharacter.png");
	m_Window->loadTexture(0, 0, 16, 32);
	m_testSprite.setColor(sf::Color(255, 0, 255, 128));
	m_Window->drawSprite(m_testSprite, 300, 300, 10);

	m_Window->drawSprite(m_testAnimation, 500, 500, 10);

	//m_Window->rect(100, 100, 160, 320);

	m_Player->render(m_Window);

	m_Window->line(400, 500, 600, 300);

	m_Window->text(150, 200, "Hello World!", 24);
}
