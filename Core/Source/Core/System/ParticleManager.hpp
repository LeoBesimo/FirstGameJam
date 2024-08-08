#pragma once
#include <Core/Renderer/Window.hpp>
#include <Core/Math/CoreMath.h>
#include <iostream>

namespace Core
{
	struct Particle
	{
		Math::Vector2 position;
		Math::Vector2 size;
		Math::Vector2 velocity;
		int age = 0;
		int maxAge;
		sf::Color color;
	};

	class ParticleManager
	{
	private:
		std::vector<Particle> m_Particles;
	
		std::vector<sf::Vertex> m_RenderParticles;

	public:
		ParticleManager() {}
		
		void addParticle(Particle particle);
		void addParticle(Math::Vector2 position, int maxAge, sf::Color color = sf::Color::Black, Math::Vector2 size = Math::Vector2(3,3), Math::Vector2 velocity = Math::Vector2(100,0));

		void update(float dt);
		void render(std::shared_ptr<Window> window);
	};
}