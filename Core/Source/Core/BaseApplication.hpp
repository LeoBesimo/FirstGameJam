#pragma once

#include <vector>
#include <iostream>

#include "Renderer/Window.hpp"
#include "Renderer/TextureLoader.hpp"	
#include "System/EventHandler.hpp"
#include "Math/CoreMath.h"
#include "Physics/Physics.hpp"

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
		TextureLoader m_TextureLoader;

		Math::Vector2 m_MousePosition;

		Physics::PhysicsWorld m_PhysicsWorld;

	};
}