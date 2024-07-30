#pragma once

#include "Shapes/Shapes.hpp"

namespace Core::Physics
{
	struct Manifold
	{
		bool colliding;
		std::shared_ptr<PhysicsBody> bodyA;
		std::shared_ptr<PhysicsBody> bodyB;

		float penetration;
		Math::Vector2 normal;
		Math::Vector2 contact;
	};
}