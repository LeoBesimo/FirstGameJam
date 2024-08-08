#include "ParticleManager.hpp"

void Core::ParticleManager::addParticle(Particle particle)
{
	m_Particles.push_back(particle);
}

void Core::ParticleManager::addParticle(Math::Vector2 position, int maxAge, sf::Color color, Math::Vector2 size, Math::Vector2 velocity)
{
	Particle p;
	p.position = position;
	p.maxAge = maxAge;
	p.color = color;
	p.size = size;
	p.velocity = velocity;

	m_Particles.push_back(p);
}

void Core::ParticleManager::update(float dt)
{
	m_RenderParticles.clear();
	for (int i = m_Particles.size() - 1; i >= 0; i--)
	{
		if (m_Particles[i].age >= m_Particles[i].maxAge)
			m_Particles.erase(m_Particles.begin() + i);
	}

	sf::Vertex vertex;

	for (Particle& particle : m_Particles)
	{
		particle.position += particle.velocity * dt;
		particle.age++;
		vertex.color = particle.color;
		vertex.color.a = 255 - floor(((float)particle.age / (float)particle.maxAge) * 255.f);
		vertex.position.x = particle.position.x;
		vertex.position.y = particle.position.y;
		m_RenderParticles.push_back(vertex);
		vertex.position.x = particle.position.x + particle.size.x;
		vertex.position.y = particle.position.y;
		m_RenderParticles.push_back(vertex);
		vertex.position.x = particle.position.x + particle.size.x;
		vertex.position.y = particle.position.y + particle.size.y;
		m_RenderParticles.push_back(vertex);
		vertex.position.x = particle.position.x;
		vertex.position.y = particle.position.y + particle.size.y;
		m_RenderParticles.push_back(vertex);
	}
}

void Core::ParticleManager::render(std::shared_ptr<Window> window)
{
	if (m_RenderParticles.size() > 0)
		window->draw(m_RenderParticles, sf::Quads);
}
