#pragma once

#include <vector>

#include "Renderer/Window.hpp"

namespace Core
{
	class BaseApplication
	{
	public:
		BaseApplication();
		~BaseApplication();

		void run();

	private:
		
		Window m_Window;

	};
}