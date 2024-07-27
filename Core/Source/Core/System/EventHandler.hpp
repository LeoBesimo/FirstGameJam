#pragma once

#include <functional>
#include <SFML/Graphics.hpp>

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
		DELETE= 83
	};

	class EventHandler
	{
		friend class BaseApplication;
	
	private:
		
		struct KeyboardState
		{
			Keyboard key;
			bool pressed;
			std::function<void()> keyCallback;

			KeyboardState(Keyboard key,std::function<void()> callback)
			{
				this->key = key;
				pressed = false;
				keyCallback = callback;
			}

			/*KeyboardState& operator=(const KeyboardState&)
			{
				KeyboardState state(key, keyCallback);
				state.pressed = pressed;
				return state;
			};*/
		};

		std::vector<KeyboardState> m_KeyStates;

		void update(std::vector<sf::Event> events);
		void keyPressed(sf::Event event);
		void keyReleased(sf::Event event);

	public:
		EventHandler();
		~EventHandler();

		void addKeyCallback(Keyboard key, std::function<void()> callback);
		void removeKeyCallback(Keyboard key);
	};

}