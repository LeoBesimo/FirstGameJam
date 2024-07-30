#include "PhysicsWorld.hpp"

void Core::Physics::PhysicsWorld::update(float dt)
{
	for (std::shared_ptr<PhysicsBody>& body : m_Bodies)
	{
		body->update(dt);
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
