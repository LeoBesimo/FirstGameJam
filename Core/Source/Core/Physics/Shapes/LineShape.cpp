#include "LineShape.hpp"

Core::Physics::LineShape::LineShape()
{
}

Core::Physics::LineShape::LineShape(Math::Vector2 p1, Math::Vector2 p2) :
	PhysicsBody((p2 + p1) / 2)
{
	m_P1 = p1;
	m_P2 = p2;
	m_BodyType = ColliderType::LINE;
	m_BoundingVolume = p2 - p1;
	m_Length = m_BoundingVolume.len();
	m_BoundingVolume.x = std::max(m_BoundingVolume.x, 2.f);
	m_BoundingVolume.y = std::max(m_BoundingVolume.y, 2.f);
	m_Angle = atan(m_BoundingVolume.y / m_BoundingVolume.x);
	setMass(0);
	setInertia(0);
}

Core::Physics::LineShape::LineShape(Math::Vector2 p1, float length, float angle) :
	PhysicsBody()
{
	m_BodyType = ColliderType::LINE;
	m_P1 = p1;
	m_Length = length;
	m_Angle = angle;
	m_P2 = Math::Vector2(cos(angle), sin(angle)) * length + p1;
	m_Position = (m_P2 - p1) / 2;
}

Core::Physics::LineShape::~LineShape()
{
}

Core::Math::Vector2 Core::Physics::LineShape::getStart()
{
	return m_P1;
}

Core::Math::Vector2 Core::Physics::LineShape::getEnd()
{
	return m_P2;
}

void Core::Physics::LineShape::setStart(Math::Vector2 p1)
{
	m_P1 = p1;
}

void Core::Physics::LineShape::setEnd(Math::Vector2 p2)
{
	m_P2 = p2;
}

void Core::Physics::LineShape::calculatePoints()
{

	m_P1 = m_Position + Math::Vector2(cos(m_Angle), sin(m_Angle)) * (m_Length / 2);
	m_P2 = m_Position - Math::Vector2(cos(m_Angle), sin(m_Angle)) * (m_Length / 2);
}

void Core::Physics::LineShape::update(float dt)
{
	PhysicsBody::update(dt);
	//calculatePoints();
}
