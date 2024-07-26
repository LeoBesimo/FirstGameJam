#pragma once

#include <vector>
#include <iostream>

#include "Renderer/Window.hpp"

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

	};
}