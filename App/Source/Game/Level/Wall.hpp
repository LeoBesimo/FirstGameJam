#pragma once
#include "Core/Core.hpp"


class Wall :
	public Core::Physics::RectangleShape
{
public:
	Wall(Core::Math::Vector2 position, Core::Math::Vector2 size);
	~Wall();

private:

};