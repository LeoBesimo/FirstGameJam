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
