#pragma once

#include <Core/Core.h>
#include "Wall.hpp"

class Room
{
public:
	Room();
	Room(Core::Math::Vector2 position, Core::Math::Vector2 size, std::shared_ptr<Core::Physics::PhysicsWorld> physicsWorld);

private:
	Core::Math::Vector2 m_Positon, m_Size;
	std::vector < std::shared_ptr<Core::Physics::PhysicsBody>> m_PhysicsObjects;
};