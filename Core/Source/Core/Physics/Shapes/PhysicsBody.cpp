#include "PhysicsBody.hpp"

Core::Physics::PhysicsBody::PhysicsBody()
{
	setMass(1);
	setInertia(1);
	m_OnCollision = [&](Manifold m, std::shared_ptr<PhysicsBody> self) {};
}

Core::Physics::PhysicsBody::PhysicsBody(Math::Vector2 position)
{
	this->m_Position = position;
	setMass(1);
	setInertia(1);
	m_OnCollision = [&](Manifold m, std::shared_ptr<PhysicsBody> self) {};
}

Core::Physics::PhysicsBody::~PhysicsBody()
{
}

void Core::Physics::PhysicsBody::update(float dt)
{	
	m_Force += m_Gravity;
	m_Acceleration += m_Force * m_InvMass;
	m_Velocity += m_Acceleration * dt;
	m_Position += m_Velocity * dt;

	m_AngularVelocity += m_AngularAcceleration * dt;
	m_Angle += m_AngularVelocity * dt;

	m_Force *= 0;
	m_Acceleration *= 0;
	m_AngularAcceleration *= 0;
}

void Core::Physics::PhysicsBody::addForce(Math::Vector2 force)
{
	m_Force += force;
}

void Core::Physics::PhysicsBody::setTag(Tag tag)
{
	m_Tag = tag;
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

void Core::Physics::PhysicsBody::setTrigger(bool isTrigger)
{
	m_IsTrigger = isTrigger;
}

void Core::Physics::PhysicsBody::setOnCollisionFunction(std::function<void(Manifold m, std::shared_ptr<PhysicsBody> self)> onCollision)
{
	m_OnCollision = onCollision;
}

void Core::Physics::PhysicsBody::setColor(Math::Vector4 color)
{
	m_Color = color;
}

Core::Physics::Tag Core::Physics::PhysicsBody::getTag()
{
	return m_Tag;
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

bool Core::Physics::PhysicsBody::isTrigger()
{
	return m_IsTrigger;
}

Core::Math::Vector4 Core::Physics::PhysicsBody::getColor()
{
	return m_Color;
}

std::string Core::Physics::PhysicsBody::serialize()
{
	enterSubField("PhysicsBody");
	serializeData("ColliderType", (int)m_BodyType);
	serializeData("Gravity", m_Gravity);
	serializeData("Bounding Volume", m_BoundingVolume);
	serializeData("Position", m_Position);
	serializeData("Velocity", m_Velocity);
	serializeData("Acceleration", m_Acceleration);
	serializeData("Force", m_Force);
	serializeData("Angle", m_Angle);
	serializeData("Angular Velocity", m_AngularVelocity);
	serializeData("Angular Acceleration", m_AngularAcceleration);
	enterSubField("Tag");
	serializeData("Tag ID", m_Tag.tagId);
	serializeData("Tag Name", m_Tag.tagName);
	serializeData("Tag Group", m_Tag.tagGroup);
	exitSubField();
	serializeData("Mass", m_Mass);
	serializeData("Inertia", m_Inertia);
	serializeData("Is Trigger", m_IsTrigger);
	serializeData("Color", m_Color);

	return m_Data.str();
}
