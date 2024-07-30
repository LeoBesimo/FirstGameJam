#pragma once

#include <vector>
#include <memory>

#include "Shapes/Shapes.hpp"
#include "CollisionDetection.hpp"
#include "CollisionSolver.hpp"

namespace Core::Physics
{
	class PhysicsWorld
	{
	public:
		PhysicsWorld() {}
		~PhysicsWorld() {}

		void update(float dt);

		std::shared_ptr<PhysicsBody> addBody(Math::Vector2 position, ColliderType type);
		void addBody(std::shared_ptr<PhysicsBody> body);

		std::vector<std::shared_ptr<PhysicsBody>> getBodies();

	private:
		std::vector<std::shared_ptr<PhysicsBody>> m_Bodies;
		CollisionSolver m_Solver;
	};
}