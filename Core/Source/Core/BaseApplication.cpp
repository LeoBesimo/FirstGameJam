#include "BaseApplication.hpp"

Core::BaseApplication::BaseApplication()
{
}

Core::BaseApplication::~BaseApplication()
{
}

void Core::BaseApplication::update(float dt)
{
	//std::cout << dt << "\n";
}

void Core::BaseApplication::render()
{
}

void Core::BaseApplication::run()
{
	m_Window = std::unique_ptr<Core::Window>(new Core::Window(1000, 1000, "Test"));
	sf::Clock deltaClock;
	float deltaTime = 1.f;

	while (m_Window->isOpen())
	{
		std::vector<sf::Event> events = m_Window->getEvents();

		for (sf::Event& event : events)
		{
			if (event.type == sf::Event::Closed)
			{
				m_Window->close();
			}
		}

		m_Window->setClearColor();

		m_Window->clear();

		m_EventHandler.update(events);
		m_MousePosition = m_Window->mapPixelToCoords(m_EventHandler.m_MousePosition);
		m_Window->stroke(0, 0, 0, 255);
		m_PhysicsWorld.update(deltaTime);
		m_ParticleManager.update(deltaTime);
		update(deltaTime);
		if (m_RenderPhysicsBodies) renderPhysicsBodies();
		render();
		m_ParticleManager.render(m_Window);

		m_Window->display();

		deltaTime = deltaClock.restart().asSeconds();
	}
}

void Core::BaseApplication::renderPhysicsBodies()
{
	std::vector<std::shared_ptr<Physics::PhysicsBody>> bodies = m_PhysicsWorld.getBodies();

	for (std::shared_ptr<Physics::PhysicsBody> body : bodies)
	{
		switch (body->getColliderType())
		{
		case Physics::ColliderType::RECT:
		{
			std::vector<Math::Vector2> corners = std::dynamic_pointer_cast<Physics::RectangleShape>(body)->getCorners();
			for (unsigned int i = 0; i < corners.size(); i++)
			{
				m_Window->line(corners[i].x, corners[i].y, corners[(i + 1) % corners.size()].x, corners[(i + 1) % corners.size()].y);
			}
			break;
		}

		default:
			break;
		}
	}
}
