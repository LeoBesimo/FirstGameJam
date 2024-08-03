#include "Wall.hpp"

Wall::Wall(Core::Math::Vector2 position, Core::Math::Vector2 size) :
	Core::Physics::RectangleShape(position, size)
{
	setMass(0);
	setInertia(0);
	m_Tag.tagName = L"Wall";
}

Wall::~Wall()
{
}
