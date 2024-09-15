#pragma once

#include "PhysicsBody.hpp"

namespace Core::Physics
{
	class CircleShape :
		public PhysicsBody
	{
	public:
		CircleShape();
		CircleShape(Math::Vector2 position, float radius);
		~CircleShape();

		void setRadius(float radius);
		float getRadius();

		void update(float dt) override;

	private:
		float m_Radius;
	};
}