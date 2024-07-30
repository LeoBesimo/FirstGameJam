#include "RectangleShape.hpp"

Core::Physics::RectangleShape::RectangleShape() :
	PhysicsBody()
{
}

Core::Physics::RectangleShape::RectangleShape(Math::Vector2 position, Math::Vector2 size) :
	PhysicsBody(position)
{
	m_BodyType = ColliderType::RECT;
	m_Size = size;
	calculateCorners();
}

Core::Physics::RectangleShape::~RectangleShape()
{
}

void Core::Physics::RectangleShape::setSize(Math::Vector2 size)
{
	m_Size = size;
	calculateCorners();
}

std::vector<Core::Math::Vector2> Core::Physics::RectangleShape::getCorners()
{
	return m_Corners;
}

void Core::Physics::RectangleShape::update(float dt)
{
	PhysicsBody::update(dt);
	calculateCorners();
}

void Core::Physics::RectangleShape::calculateCorners()
{
	m_Corners.clear();
	Math::Vector2 corner1 = m_Position - (m_Size / 2);
	Math::Vector2 corner2 = Math::Vector2(m_Position.x + m_Size.x / 2, m_Position.y - m_Size.y / 2);
	Math::Vector2 corner3 = m_Position + (m_Size / 2);
	Math::Vector2 corner4 = Math::Vector2(m_Position.x - m_Size.x / 2, m_Position.y + m_Size.y / 2);

	m_Corners.push_back(corner1);
	m_Corners.push_back(corner2);
	m_Corners.push_back(corner3);
	m_Corners.push_back(corner4);
}
