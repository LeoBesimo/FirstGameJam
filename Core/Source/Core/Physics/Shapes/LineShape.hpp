#pragma once

#include "PhysicsBody.hpp"

namespace Core::Physics
{
	class LineShape :
		public PhysicsBody
	{
	public:
		LineShape();
		LineShape(Math::Vector2 p1, Math::Vector2 p2);
		LineShape(Math::Vector2 p1, float length, float angle);
		~LineShape();

		Math::Vector2 getStart();
		Math::Vector2 getEnd();
		void setStart(Math::Vector2 p1);
		void setEnd(Math::Vector2 p2);

		void update(float dt) override;

	private:
		Math::Vector2 m_P1;
		Math::Vector2 m_P2;
		float m_Length;

		void calculatePoints();
	};
}