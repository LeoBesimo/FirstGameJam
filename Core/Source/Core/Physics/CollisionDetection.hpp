#pragma once

#include "Manifold.hpp"
#include "Shapes/Shapes.hpp"

namespace Core::Physics
{
	Math::Vector2 getContactRectRect(std::shared_ptr<RectangleShape> bodyA, std::shared_ptr<RectangleShape> bodyB);
	
	std::vector<Math::Vector2> getNormals(std::vector<Math::Vector2> corners);
	Math::Vector2 getMinMax(std::vector<Math::Vector2> corners, Math::Vector2 normal);
	Math::Vector2 getClosestPoint(Math::Vector2 center, std::vector<Math::Vector2> points);


	bool boundingBoxCollision(std::shared_ptr<PhysicsBody> bodyA, std::shared_ptr<PhysicsBody> bodyB);
	Manifold rectRectCollision(std::shared_ptr<RectangleShape> bodyA, std::shared_ptr<RectangleShape> bodyB);

	Manifold collide(std::shared_ptr<PhysicsBody> bodyA, std::shared_ptr<PhysicsBody> bodyB);
}