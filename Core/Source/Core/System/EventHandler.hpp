#pragma once

#include <functional>
#include <SFML/Graphics.hpp>
#include "Core/Math/CoreMath.h"
#include <iostream>

namespace Core
{
	enum class Keyboard
	{
		A = 0, 
		B = 1, 
		C = 2, 
		D = 3, 
		E, 
		F, 
		G, 
		H, 
		I, 
		J, 
		K, 
		L,
		M,
		N,
		O,
		P,
		Q,
		R,
		S,
		T,
		U,
		V,
		W,
		X,
		Y,
		Z = 25,
		NUM1 = 26,
		NUM2,
		NUM3,
		NUM4,
		NUM5,
		NUM6,
		NUM7,
		NUM8,
		NUM9,
		NUM0 = 35,
		SPACE = 40,
		ESCAPE = 37,
		BACKSPACE = 38,
		ENTER = 36,
		TAB = 39,
		LSHIFT = 128,
		LCTRL = 127,
		RSHIFT = 132,
		RCTRL = 131,
		ALT = 129,
		ALTGR = 133,
		CAPSLOCK = 76,
		DELETE = 83
	};

	enum class Mouse
	{
		LEFT = 0,
		RIGHT = 1,
		MIDDLE = 2
	};

	class EventHandler
	{
		friend class BaseApplication;
	
	private:
		
		struct KeyboardState
		{
			Keyboard key;
			bool pressed;
			bool whileHeld;
			std::function<void()> keyCallback;

			KeyboardState(Keyboard key,std::function<void()> callback, bool execWhileHeld = true)
			{
				this->key = key;
				pressed = false;
				this->whileHeld = execWhileHeld;
				keyCallback = callback;
			}
		};

		struct MouseState
		{
			Mouse button;
			bool pressed;
			bool whileHeld;
			std::function<void()> mouseCallback;

			MouseState(Mouse button, std::function<void()> callback, bool execWhileHeld = false)
			{
				this->button = button;
				this->pressed = false;
				this->whileHeld = execWhileHeld;
				this->mouseCallback = callback;
			}
		};

		std::vector<KeyboardState> m_KeyStates;
		std::vector<MouseState> m_MouseStates;

		Math::Vector2 m_MousePosition;

		void update(std::vector<sf::Event> events);
		void keyPressed(sf::Event event);
		void keyReleased(sf::Event event);
		void mousePressed(sf::Event event);
		void mouseReleased(sf::Event event);
		void mouseMoved(sf::Event event);

	public:
		EventHandler();
		~EventHandler();

		void addKeyCallback(Keyboard key, std::function<void()> callback, bool execWhileHeld = true);
		void removeKeyCallback(Keyboard key);
		void addMouseCallback(Mouse button, std::function<void()> callback, bool execWhileHeld = false);
		void removeMouseCallback(Mouse button);
	};

}