#include "BaseApplication.hpp"

Core::BaseApplication::BaseApplication()
{
}

Core::BaseApplication::~BaseApplication()
{
}

void Core::BaseApplication::update(float dt)
{
	std::cout << "From Base Class" << "\n";
}

void Core::BaseApplication::run()
{
	m_Window = std::unique_ptr<Core::Window>(new Core::Window(1000, 1000, "Test"));

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

		update(1);
		m_Window->clear(0,0,0, 255);

		m_Window->rect(100, 100, 100, 100);

		m_Window->line(400, 500, 600, 300);

		m_Window->display();
	}
}
