#include "CircleShape.hpp"

Core::Physics::CircleShape::CircleShape() :
	PhysicsBody()
{
	m_BodyType = ColliderType::CIRCLE;
}

Core::Physics::CircleShape::CircleShape(Math::Vector2 position, float radius) :
	PhysicsBody(position)
{
	m_BodyType = ColliderType::CIRCLE;
	m_Radius = radius;
}

Core::Physics::CircleShape::~CircleShape()
{
}

void Core::Physics::CircleShape::setRadius(float radius)
{
	m_Radius = radius;
}

float Core::Physics::CircleShape::getRadius()
{
	return m_Radius;
}

void Core::Physics::CircleShape::update(float dt)
{
	PhysicsBody::update(dt);
}

