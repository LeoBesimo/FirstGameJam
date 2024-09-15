#include "CollisionSolver.hpp"

void Core::Physics::CollisionSolver::resolveStatic(Manifold m)
{
	Math::Vector2 normal = m.normal;
	//m.bodyA->move(-normal * m.penetration / 2);
	//m.bodyB->move(normal * m.penetration / 2);
	m.bodyA->setPosition(m.bodyA->getPosition() - m.normal * m.penetration * m.bodyA->getInverseMass());
	m.bodyB->setPosition(m.bodyB->getPosition() + m.normal * m.penetration * m.bodyB->getInverseMass());
}

void Core::Physics::CollisionSolver::resolveDynamic(Manifold m)
{
	std::shared_ptr<PhysicsBody> bodyA = m.bodyA;
	std::shared_ptr<PhysicsBody> bodyB = m.bodyB;

	Math::Vector2 normal = m.normal;
	Math::Vector2 contact = m.contact;

	Math::Vector2 ra = contact - bodyA->getPosition();
	Math::Vector2 rb = contact - bodyB->getPosition();

	Math::Vector2 raPerp(-ra.y, ra.x);
	Math::Vector2 rbPerp(-rb.y, rb.x);

	Math::Vector2 rv = (bodyB->getVelocity() + rbPerp * bodyB->getAngularVelocity()) - (bodyA->getVelocity() + raPerp * bodyA->getAngularVelocity());

	float contactVelMag = Math::dot(rv, normal);
	if (contactVelMag > 0)
		return;

	float e = std::min(bodyA->getMaterial().restitution, bodyB->getMaterial().restitution);

	float denom1 = bodyA->getInverseMass() + bodyB->getInverseMass();
	float denom2 = Math::square(Math::dot(raPerp, normal)) * bodyA->getInverseInertia();
	float denom3 = Math::square(Math::dot(rbPerp, normal)) * bodyB->getInverseInertia();

	float j = -(1 + e) * contactVelMag;
	j /= (denom1 + denom2 + denom3);

	Math::Vector2 impulse = normal * j;

	bodyA->setVelocity(bodyA->getVelocity() - impulse * bodyA->getInverseMass());
	bodyB->setVelocity(bodyB->getVelocity() + impulse * bodyB->getInverseMass());

	float omegaA = bodyA->getAngularVelocity() - Math::cross(ra, impulse) * bodyA->getInverseInertia();
	float omegaB = bodyB->getAngularVelocity() + Math::cross(rb, impulse) * bodyB->getInverseInertia();

	bodyA->setAngularVelocity(omegaA);
	bodyB->setAngularVelocity(omegaB);
}

void Core::Physics::CollisionSolver::resolveDynamicWithFriction(Manifold m)
{
	std::shared_ptr<PhysicsBody> bodyA = m.bodyA;
	std::shared_ptr<PhysicsBody> bodyB = m.bodyB;

	Math::Vector2 normal = m.normal;
	Math::Vector2 contact = m.contact;

	Math::Vector2 ra = contact - bodyA->getPosition();
	Math::Vector2 rb = contact - bodyB->getPosition();

	Math::Vector2 raPerp(-ra.y, ra.x);
	Math::Vector2 rbPerp(-rb.y, rb.x);

	Math::Vector2 rv = (bodyB->getVelocity() + rbPerp * bodyB->getAngularVelocity()) - (bodyA->getVelocity() + raPerp * bodyA->getAngularVelocity());

	float contactVelMag = Math::dot(rv, normal);
	if (contactVelMag > 0)
		return;

	float e = std::min(bodyA->getMaterial().restitution, bodyB->getMaterial().restitution);

	float denom1 = bodyA->getInverseMass() + bodyB->getInverseMass();
	float denom2 = Math::square(Math::dot(raPerp, normal)) * bodyA->getInverseInertia();
	float denom3 = Math::square(Math::dot(rbPerp, normal)) * bodyB->getInverseInertia();

	float j = -(1 + e) * contactVelMag;
	j /= (denom1 + denom2 + denom3);

	Math::Vector2 impulse = normal * j;

	bodyA->setVelocity(bodyA->getVelocity() - impulse * bodyA->getInverseMass());
	bodyB->setVelocity(bodyB->getVelocity() + impulse * bodyB->getInverseMass());

	float omegaA = bodyA->getAngularVelocity() - Math::cross(ra, impulse) * bodyA->getInverseInertia();
	float omegaB = bodyB->getAngularVelocity() + Math::cross(rb, impulse) * bodyB->getInverseInertia();

	bodyA->setAngularVelocity(omegaA);
	bodyB->setAngularVelocity(omegaB);


	//Friction
	Math::Vector2 tangent = rv - (normal * contactVelMag);

	if (Math::nearlyEqual(tangent, Math::Vector2())) return;

	tangent.normalize();

	float den1 = bodyA->getInverseMass() + bodyB->getInverseMass();
	float den2 = Math::square(Math::dot(raPerp, tangent)) * bodyA->getInverseInertia();
	float den3 = Math::square(Math::dot(rbPerp, tangent)) * bodyB->getInverseInertia();

	float jt = -Math::dot(rv, tangent);
	jt /= (den1 + den2 + den3);

	Math::Vector2 frictionImpulse = tangent * jt;

	float sf = (bodyA->getMaterial().staticFriction + bodyB->getMaterial().staticFriction) / 2;//sqrt(bodyA->getMaterial().staticFriction * bodyB->getMaterial().staticFriction);
	float df = (bodyA->getMaterial().dynamicFriction + bodyB->getMaterial().dynamicFriction) / 2;//sqrt(bodyA->getMaterial().dynamicFriction * bodyB->getMaterial().dynamicFriction);

	if (abs(jt) <= j * sf)
		frictionImpulse = tangent * jt;
	else
		frictionImpulse = tangent * -j * df;

	bodyA->setVelocity(bodyA->getVelocity() - frictionImpulse * bodyA->getInverseMass());
	bodyB->setVelocity(bodyB->getVelocity() + frictionImpulse * bodyB->getInverseMass());

	float omegaAT = bodyA->getAngularVelocity() - Math::cross(ra, frictionImpulse) * bodyA->getInverseInertia();
	float omegaBT = bodyB->getAngularVelocity() + Math::cross(rb, frictionImpulse) * bodyB->getInverseInertia();

	bodyA->setAngularVelocity(omegaAT);
	bodyB->setAngularVelocity(omegaBT);
}
