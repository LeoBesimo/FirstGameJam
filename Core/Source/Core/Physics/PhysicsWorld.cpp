#include "PhysicsWorld.hpp"

void Core::Physics::PhysicsWorld::update(float dt)
{
	for (unsigned int i = 0; i < m_Bodies.size(); i++)
	{
		m_Bodies[i]->update(dt);
		for (unsigned int j = i + 1; j < m_Bodies.size(); j++)
		{
			if (boundingBoxCollision(m_Bodies[i], m_Bodies[j]))
			{
				Manifold m = collide(m_Bodies[i], m_Bodies[j]);
				if (m.colliding)
				{
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
	m_Bodies.push_back(std::move(body));
}

std::vector<std::shared_ptr<Core::Physics::PhysicsBody>> Core::Physics::PhysicsWorld::getBodies()
{
	return m_Bodies;
}
