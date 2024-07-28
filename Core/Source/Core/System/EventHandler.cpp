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
			mousePressed(event);
			break;

		case sf::Event::MouseButtonReleased:
			mouseReleased(event);
			break;

		case ::sf::Event::MouseMoved:
			mouseMoved(event);
			break;

		default:
			break;
		}
	}


	for (KeyboardState state : m_KeyStates)
	{
		if (state.pressed) 
			state.keyCallback();
	}

	for (MouseState state : m_MouseStates)
	{
		if (state.pressed) state.mouseCallback();
	}
}

void Core::EventHandler::keyPressed(sf::Event event)
{
	for (KeyboardState& state : m_KeyStates)
	{
		if (static_cast<int>(state.key) == event.key.scancode)
			state.pressed = true;
	}
}

void Core::EventHandler::keyReleased(sf::Event event)
{
	for (KeyboardState &state : m_KeyStates)
	{
		if (static_cast<int>(state.key) == event.key.scancode)
			state.pressed = false;
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

void Core::EventHandler::addMouseCallback(Mouse button, std::function<void()> callback, bool execWhileHeld)
{
	m_MouseStates.push_back(MouseState(button, callback, execWhileHeld));
}

void Core::EventHandler::removeMouseCallback(Mouse button)
{
	for (int i = m_MouseStates.size() - 1; i >= 0; i--)
	{
		if (m_MouseStates[i].button == button)
		{
			m_MouseStates.erase(m_MouseStates.begin() + i);
		}
	}
}

void Core::EventHandler::mousePressed(sf::Event event)
{
	for (MouseState &mouseState : m_MouseStates)
	{
		if (static_cast<int>(mouseState.button) == event.mouseButton.button)
		{
			if (!mouseState.whileHeld) mouseState.mouseCallback();
			else mouseState.pressed = true;
		}
	}
}

void Core::EventHandler::mouseReleased(sf::Event event)
{
	for (MouseState &mouseState : m_MouseStates)
	{
		if (static_cast<int>(mouseState.button) == event.mouseButton.button)
		{
			mouseState.pressed = false;
		}
	}
}

void Core::EventHandler::mouseMoved(sf::Event event)
{
	m_MousePosition.x = event.mouseMove.x;
	m_MousePosition.y = event.mouseMove.y;
}
