#include "CollisionSolver.hpp"

void Core::Physics::CollisionSolver::resolveStatic(Manifold m)
{
	Math::Vector2 normal = m.normal;
	//m.bodyA->move(-normal * m.penetration / 2);
	//m.bodyB->move(normal * m.penetration / 2);
	m.bodyA->setPosition(m.bodyA->getPosition() - m.normal * m.penetration * m.bodyA->getInverseMass());
	m.bodyB->setPosition(m.bodyB->getPosition() + m.normal * m.penetration * m.bodyB->getInverseMass());
}
