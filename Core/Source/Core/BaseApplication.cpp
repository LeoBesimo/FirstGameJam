#include "BaseApplication.hpp"

Core::BaseApplication::BaseApplication()
{
}

Core::BaseApplication::~BaseApplication()
{
}

void Core::BaseApplication::update(float dt)
{
	std::cout << dt << "\n";
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

		for (sf::Event event : events)
		{
			if (event.type == sf::Event::Closed)
			{
				m_Window->close();
			}
		}

		m_Window->setClearColor();

		m_Window->clear();

		update(deltaTime);
		render();

		m_Window->display();

		deltaTime = deltaClock.restart().asSeconds();
	}
}
