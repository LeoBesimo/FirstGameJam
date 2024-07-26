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
		void run();

	private:
		
		std::unique_ptr<Window> m_Window;

	};
}