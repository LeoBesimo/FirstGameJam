#pragma once

#include <vector>
#include <iostream>

#include "Renderer/Window.hpp"
#include "Renderer/TextureLoader.hpp"
#include "Renderer/AnimationManager.hpp"
#include "Audio/AudioManager.hpp"
#include "System/EventHandler.hpp"
#include "Math/CoreMath.h"
#include "Physics/Physics.hpp"
#include "System/ParticleManager.hpp"

namespace Core
{
	class BaseApplication
	{
	public:
		BaseApplication();
		~BaseApplication();

		virtual void init();
		virtual void update(float dt);
		virtual void render();
		void run();

	protected:

		bool m_RenderPhysicsBodies = true;
		
		std::shared_ptr<Window> m_Window;
		EventHandler m_EventHandler;
		TextureLoader m_TextureLoader;
		AnimationManager m_AnimationManager;
		SoundManager m_SoundManager;

		Math::Vector2 m_MousePosition;

		std::shared_ptr<Physics::PhysicsWorld> m_PhysicsWorld;

		ParticleManager m_ParticleManager;

	private:
		void renderPhysicsBodies();

	};
}