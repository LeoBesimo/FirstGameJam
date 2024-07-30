#pragma once

#include "Shapes/Shapes.hpp"
#include "Manifold.hpp"

namespace Core::Physics
{
	Manifold boundingBoxCollision(std::shared_ptr<PhysicsBody> bodyA, std::shared_ptr<PhysicsBody> bodyB);
}