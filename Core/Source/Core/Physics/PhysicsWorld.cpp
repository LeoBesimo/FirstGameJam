#include "PhysicsWorld.hpp"

void Core::Physics::PhysicsWorld::update(float dt)
{
	for (unsigned int i = 0; i < m_Bodies.size(); i++)
	{
		m_Bodies[i]->update(dt);
		for (unsigned int j = 0; j < m_Bodies.size(); j++)
		{
			if (i == j) continue;

			if (boundingBoxCollision(m_Bodies[i], m_Bodies[j]))
			{
				Manifold m = collide(m_Bodies[i], m_Bodies[j]);
				if (m.colliding)
				{
					if (!m.bodyA->isTrigger() && !m.bodyB->isTrigger())
						m_Solver.resolveStatic(m);
					m.bodyA->m_OnCollision(m, m.bodyA);
					m.bodyB->m_OnCollision(m, m.bodyB);
				}
			}
		}
	}
}

std::shared_ptr<Core::Physics::PhysicsBody> Core::Physics::PhysicsWorld::addBody(Math::Vector2 position, ColliderType type)
{
	std::shared_ptr<PhysicsBody> body;

	switch (type)
	{
	case ColliderType::RECT:
		body = std::make_shared<RectangleShape>(RectangleShape(position));
		m_Bodies.push_back(body);
		return body;

	default:
		return nullptr;
	}

	return nullptr;
}

void Core::Physics::PhysicsWorld::addBody(std::shared_ptr<PhysicsBody> body)
{
	m_Bodies.push_back(body);
}

std::shared_ptr<Core::Physics::PhysicsBody> Core::Physics::PhysicsWorld::getBodyByTagID(int id)
{
	for (std::shared_ptr<PhysicsBody>& body : m_Bodies)
	{
		if (body->getTag().tagId == id)
			return body;
	}

	return nullptr;
}

std::shared_ptr<Core::Physics::PhysicsBody> Core::Physics::PhysicsWorld::getBodyByTagName(std::wstring tagName)
{
	for (std::shared_ptr<PhysicsBody>& body : m_Bodies)
	{
		if (body->getTag().tagName == tagName)
			return body;
	}

	return nullptr;
}

std::vector<std::shared_ptr<Core::Physics::PhysicsBody>> Core::Physics::PhysicsWorld::getBodiesByTagID(int id)
{
	std::vector<std::shared_ptr<PhysicsBody>> bodies;

	for (std::shared_ptr<PhysicsBody>& body : m_Bodies)
	{
		if (body->getTag().tagId == id)
			bodies.push_back(body);
	}

	return bodies;
}

std::vector<std::shared_ptr<Core::Physics::PhysicsBody>> Core::Physics::PhysicsWorld::getBodiesByTagName(std::wstring tagName)
{
	std::vector<std::shared_ptr<PhysicsBody>> bodies;

	for (std::shared_ptr<PhysicsBody>& body : m_Bodies)
	{
		if (body->getTag().tagName == tagName)
			bodies.push_back(body);
	}

	return bodies;
}

std::vector<std::shared_ptr<Core::Physics::PhysicsBody>> Core::Physics::PhysicsWorld::getBodiesByTagGroup(std::wstring tagGroup)
{
	std::vector<std::shared_ptr<PhysicsBody>> bodies;

	for (std::shared_ptr<PhysicsBody>& body : m_Bodies)
	{
		if (body->getTag().tagGroup == tagGroup)
			bodies.push_back(body);
	}

	return bodies;
}

bool Core::Physics::PhysicsWorld::removeBodyByTagID(int id)
{
	for (int i = m_Bodies.size() - 1; i >= 0; i--)
	{
		if (m_Bodies[i]->getTag().tagId == id)
		{
			m_Bodies.erase(m_Bodies.begin() + i);
			return true;
		}
	}
	return false;
}

bool Core::Physics::PhysicsWorld::removeBodyByTagName(std::wstring tagName)
{
	for (int i = m_Bodies.size() - 1; i >= 0; i--)
	{
		if (m_Bodies[i]->getTag().tagName == tagName)
		{
			m_Bodies.erase(m_Bodies.begin() + i);
			return true;
		}
	}
	return false;
}

std::vector<std::shared_ptr<Core::Physics::PhysicsBody>> Core::Physics::PhysicsWorld::getBodies()
{
	return m_Bodies;
}


