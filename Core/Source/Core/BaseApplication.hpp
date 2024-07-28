#pragma once

#include <vector>
#include <iostream>

#include "Renderer/Window.hpp"
#include "System/EventHandler.hpp"
#include "Math/CoreMath.h"

namespace Core
{
	class BaseApplication
	{
	public:
		BaseApplication();
		~BaseApplication();

		virtual void update(float dt);
		virtual void render();
		void run();

	protected:
		
		std::unique_ptr<Window> m_Window;
		EventHandler m_EventHandler;

		Math::Vector2 m_MousePosition;

	};
}