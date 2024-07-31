#pragma once

#include "Core/Math/CoreMath.h"
#include <vector>
#include <functional>
#include <memory>

namespace Core::Physics
{

	enum class ColliderType
	{
		RECT
	};

	struct Manifold;

	class PhysicsBody
	{
		friend class PhysicsWorld;

	public:

		/*struct CollisionData
		{
			std::shared_ptr<PhysicsBody> bodyA;
			std::shared_ptr<PhysicsBody> bodyB;

			float penetration;
			Math::Vector2 normal;
			Math::Vector2 contact;
		};*/

		PhysicsBody();
		PhysicsBody(Math::Vector2 position);
		~PhysicsBody();

		virtual void update(float dt);

		void addForce(Math::Vector2 force);

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

		void setOnCollisionFunction(std::function<void(Manifold data, std::shared_ptr<PhysicsBody> self)> onCollision);

		//Getters
		ColliderType getColliderType();

		Math::Vector2 getGravity();
		Math::Vector2 getBoundingVolume();
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
		Math::Vector2 m_BoundingVolume;

		Math::Vector2 m_Position;
		Math::Vector2 m_Velocity;
		Math::Vector2 m_Acceleration;
		Math::Vector2 m_Force;

		float m_Angle;
		float m_AngularVelocity;
		float m_AngularAcceleration;

		float m_Mass;
		float m_InvMass;
		float m_Inertia;
		float m_InvInertia;

		std::function<void(Manifold m, std::shared_ptr<PhysicsBody> self)> m_OnCollision;
	};

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