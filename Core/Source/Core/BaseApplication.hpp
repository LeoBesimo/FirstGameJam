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

		virtual void update(float dt);
		virtual void run();

	private:
		
		std::unique_ptr<Window> m_Window;

	};
}