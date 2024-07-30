#include "PhysicsBody.hpp"

Core::Physics::PhysicsBody::PhysicsBody()
{
	setMass(1);
	setInertia(1);
}

Core::Physics::PhysicsBody::PhysicsBody(Math::Vector2 position)
{
	this->m_Position = position;
	setMass(1);
	setInertia(1);
}

Core::Physics::PhysicsBody::~PhysicsBody()
{
}

void Core::Physics::PhysicsBody::update(float dt)
{	
	m_Acceleration += m_Gravity * m_InvMass;
	m_Velocity += m_Acceleration * dt;
	m_Position += m_Velocity * dt;

	m_AngularVelocity += m_AngularAcceleration * dt;
	m_Angle += m_AngularVelocity * dt;

	m_Acceleration *= 0;
	m_AngularAcceleration *= 0;
}

void Core::Physics::PhysicsBody::setGravity(Math::Vector2 gravity)
{
	m_Gravity = gravity;
}

void Core::Physics::PhysicsBody::setPosition(Math::Vector2 position)
{
	m_Position = position;
}

void Core::Physics::PhysicsBody::setVelocity(Math::Vector2 velocity)
{
	m_Velocity = velocity;
}

void Core::Physics::PhysicsBody::setAcceleration(Math::Vector2 acceleration)
{
	m_Acceleration = acceleration;
}

void Core::Physics::PhysicsBody::setAngle(float angle)
{
	m_Angle = angle;
}

void Core::Physics::PhysicsBody::setAngularVelocity(float angularVelocity)
{
	m_AngularVelocity = angularVelocity;
}

void Core::Physics::PhysicsBody::setAngularAcceleration(float angularAcceleration)
{
	m_AngularAcceleration = angularAcceleration;
}

void Core::Physics::PhysicsBody::setMass(float mass)
{
	m_Mass = mass;
	if (mass == 0) m_InvMass = 0;
	else m_InvMass = 1 / mass;
}

void Core::Physics::PhysicsBody::setInertia(float inertia)
{
	m_Inertia = inertia;
	if (inertia == 0) m_InvInertia = 0;
	else m_InvInertia = 1 / inertia;
}

void Core::Physics::PhysicsBody::setOnCollisionFunction(std::function<void()> onCollision)
{
	m_OnCollision = onCollision;
}

Core::Physics::ColliderType Core::Physics::PhysicsBody::getColliderType()
{
	return m_BodyType;
}

Core::Math::Vector2 Core::Physics::PhysicsBody::getGravity()
{
	return m_Gravity;
}

Core::Math::Vector2 Core::Physics::PhysicsBody::getBoundingVolume()
{
	return m_BoundingVolume;
}

Core::Math::Vector2 Core::Physics::PhysicsBody::getPosition()
{
	return m_Position;
}

Core::Math::Vector2 Core::Physics::PhysicsBody::getVelocity()
{
	return m_Velocity;
}

Core::Math::Vector2 Core::Physics::PhysicsBody::getAcceleration()
{
	return m_Acceleration;
}

float Core::Physics::PhysicsBody::getAngle()
{
	return m_Angle;
}

float Core::Physics::PhysicsBody::getAngularVelocity()
{
	return m_AngularVelocity;
}

float Core::Physics::PhysicsBody::getAngularAcceleration()
{
	return m_AngularAcceleration;
}

float Core::Physics::PhysicsBody::getMass()
{
	return m_Mass;
}

float Core::Physics::PhysicsBody::getInverseMass()
{
	return m_InvMass;
}

float Core::Physics::PhysicsBody::getInertia()
{
	return m_Inertia;
}

float Core::Physics::PhysicsBody::getInverseInertia()
{
	return m_InvInertia;
}
