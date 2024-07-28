#include "PhysicsBody.hpp"

Core::Physics::PhysicsBody::PhysicsBody()
{
}

Core::Physics::PhysicsBody::PhysicsBody(Math::Vector2 position)
{
	this->m_Position = position;
}

Core::Physics::PhysicsBody::~PhysicsBody()
{
}

void Core::Physics::PhysicsBody::update(float dt)
{
	m_Velocity += m_Acceleration * dt;
	m_Position += m_Velocity * dt;

	m_AngularVelocity += m_AngularAcceleration * dt;
	m_Angle += m_AngularVelocity * dt;
}
