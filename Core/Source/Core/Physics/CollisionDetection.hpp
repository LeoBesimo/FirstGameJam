#pragma once

#include "Shapes/Shapes.hpp"

namespace Core::Physics
{
	
	//Contact Generation Rectangle
	Math::Vector2 getContactRectRect(std::shared_ptr<RectangleShape> bodyA, std::shared_ptr<RectangleShape> bodyB);
	Math::Vector2 getContactLineRect(std::shared_ptr<RectangleShape> bodyA, std::shared_ptr<LineShape> bodyB);
	Math::Vector2 getContactCircleRect(std::shared_ptr<RectangleShape> bodyA, std::shared_ptr<CircleShape> bodyB);

	//Contact Generation Circle
	Math::Vector2 getContactLineCircle(std::shared_ptr<LineShape> bodyA, std::shared_ptr<CircleShape> bodyB);
	
	std::vector<Math::Vector2> getNormals(std::vector<Math::Vector2> corners);
	Math::Vector2 getMinMax(std::vector<Math::Vector2> corners, Math::Vector2 normal);
	Math::Vector2 getMinMaxCircle(Math::Vector2 center, float radius, Math::Vector2 normal);
	
	Math::Vector2 getClosestPoint(Math::Vector2 center, std::vector<Math::Vector2> points);


	bool boundingBoxCollision(std::shared_ptr<PhysicsBody> bodyA, std::shared_ptr<PhysicsBody> bodyB);
	Manifold rectRectCollision(std::shared_ptr<RectangleShape> bodyA, std::shared_ptr<RectangleShape> bodyB);
	Manifold rectLineCollision(std::shared_ptr<RectangleShape> bodyA, std::shared_ptr<LineShape> bodyB);
	Manifold rectCircleCollision(std::shared_ptr<RectangleShape> bodyA, std::shared_ptr<CircleShape> bodyB);
	Manifold lineCircleCollision(std::shared_ptr<LineShape> bodyA, std::shared_ptr<CircleShape> bodyB);
	Manifold circleCircleCollision(std::shared_ptr<CircleShape> bodyA, std::shared_ptr<CircleShape> bodyB);

	Manifold collide(std::shared_ptr<PhysicsBody> bodyA, std::shared_ptr<PhysicsBody> bodyB);
}