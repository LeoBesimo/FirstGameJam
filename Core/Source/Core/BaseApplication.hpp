#pragma once

#include <vector>
#include <iostream>

#include "Renderer/Window.hpp"
#include "Renderer/TextureLoader.hpp"
#include "Renderer/AnimationManager.hpp"
#include "Audio/AudioManager.hpp"
#include "System/EventHandler.hpp"
#include "Math/CoreMath.hpp"
#include "Physics/Physics.hpp"
#include "System/ParticleManager.hpp"

#include "Core/ImGui/imgui.h"
#include "Core/ImGui/imgui-SFML.h"

namespace Core
{
	class BaseApplication
	{
	public:
		BaseApplication();
		~BaseApplication();

		virtual void init();
		virtual void preUpdate();
		virtual void update(float dt);
		virtual void render();
		void run();
		void close();

	protected:

		bool m_RenderPhysicsBodies = true;
		bool m_PhysicsWireframe = true;
		
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