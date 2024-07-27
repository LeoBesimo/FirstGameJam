#include "EventHandler.hpp"

void Core::EventHandler::update(std::vector<sf::Event> events)
{

	for (sf::Event event : events)
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			keyPressed(event);
			break;

		case sf::Event::KeyReleased:
			keyReleased(event);
			break;

		case sf::Event::MouseButtonPressed:
			break;

		case sf::Event::MouseButtonReleased:
			break;

		case ::sf::Event::MouseMoved:
			break;

		default:
			break;
		}
	}


	for (unsigned int i = 0; i < m_KeyStates.size(); i++)
	{
		if (m_KeyStates[i].pressed) 
			m_KeyStates[i].keyCallback();
	}
}

void Core::EventHandler::keyPressed(sf::Event event)
{
	for (unsigned int i = 0; i < m_KeyStates.size(); i++)
	{
		if (static_cast<int>(m_KeyStates[i].key) == event.key.scancode)
			m_KeyStates[i].pressed = true;
	}
}

void Core::EventHandler::keyReleased(sf::Event event)
{
	for (unsigned int i = 0; i < m_KeyStates.size(); i++)
	{
		if (static_cast<int>(m_KeyStates[i].key) == event.key.scancode)
			m_KeyStates[i].pressed = false;
	}
}

Core::EventHandler::EventHandler()
{
}

Core::EventHandler::~EventHandler()
{
}

void Core::EventHandler::addKeyCallback(Keyboard key, std::function<void()> callback)
{
	m_KeyStates.push_back(KeyboardState(key, callback));
}

void Core::EventHandler::removeKeyCallback(Keyboard key)
{
	for (int i = m_KeyStates.size() - 1; i >= 0; i--)
	{
		if (m_KeyStates[i].key == key)
		{
			m_KeyStates.erase(m_KeyStates.begin() + i);
		}
	}
}
