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
		std::shared_ptr<PhysicsBody> getBodyByTagID(int id);
		std::shared_ptr<PhysicsBody> getBodyByTagName(std::wstring tagName);

		bool removeBodyByTagID(int id);
		bool removeBodyByTagName(std::wstring tagName);

		std::vector<std::shared_ptr<PhysicsBody>> getBodies();

	private:
		std::vector<std::shared_ptr<PhysicsBody>> m_Bodies;
		CollisionSolver m_Solver;
	};
}