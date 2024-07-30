#pragma once

#include "Core/Math/CoreMath.h"
#include <vector>

namespace Core::Physics
{

	enum class ColliderType
	{
		RECT
	};


	class PhysicsBody
	{
	public:
		PhysicsBody();
		PhysicsBody(Math::Vector2 position);
		~PhysicsBody();

		void update(float dt);

		//Setters
		void setGravity(Math::Vector2 gravity);
		void setPosition(Math::Vector2 position);
		void setVelocity(Math::Vector2 velocity);
		void setAcceleration(Math::Vector2 acceleration);

		void setAngle(float angle);
		void setAngularVelocity(float angularVelocity);
		void setAngularAcceleration(float angularAcceleration);

		void setMass(float mass);
		void setInertia(float inertia);

		//Getters

		Math::Vector2 getGravity();
		Math::Vector2 getPosition();
		Math::Vector2 getVelocity();
		Math::Vector2 getAcceleration();

		float getAngle();
		float getAngularVelocity();
		float getAngularAcceleration();

		float getMass();
		float getInverseMass();
		float getInertia();
		float getInverseInertia();
		

	protected:
		ColliderType m_BodyType;

		Math::Vector2 m_Gravity;

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