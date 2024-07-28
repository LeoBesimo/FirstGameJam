#pragma once

#include "Core/Math/CoreMath.h"
#include <vector>

namespace Core
{
	namespace Physics
	{
		class PhysicsBody
		{
		public:
			PhysicsBody();
			PhysicsBody(Math::Vector2 position);
			~PhysicsBody();

			void update(float dt);

		private:
			Math::Vector2 m_Position;
			Math::Vector2 m_Velocity;
			Math::Vector2 m_Acceleration;

			float m_Angle;
			float m_AngularVelocity;
			float m_AngularAcceleration;

			float m_Mass;
			float m_InvMass;
			float m_Inertia;
			float m_InvInertia;
		};
	}
}