#include "Window.hpp"

Core::Window::Window(unsigned int width, unsigned int height, std::string title):
	m_Width(width), m_Height(height), m_Window(sf::VideoMode(width,height), title)
{
}

Core::Window::~Window()
{
}

bool Core::Window::isOpen()
{
	return m_Window.isOpen();
}

std::vector<sf::Event> Core::Window::getEvents()
{
	std::vector<sf::Event> events;
	
	sf::Event event;
	while (m_Window.pollEvent(event))
	{
		events.push_back(event)
	}

	return events;
}

void Core::Window::rect(float positionX, float positionY, float width, float height)
{
	m_RectangleShape.setPosition(sf::Vector2f(positionX, positionY));
	m_RectangleShape.setSize(sf::Vector2f(width, height));

	m_Window.draw(m_RectangleShape);
}