#include "CollisionDetection.hpp"

Core::Physics::Manifold Core::Physics::boundingBoxCollision(std::shared_ptr<PhysicsBody> bodyA, std::shared_ptr<PhysicsBody> bodyB)
{
    Manifold manifold;

    manifold.bodyA = bodyA;
    manifold.bodyB = bodyB;
    manifold.colliding = true;

    Math::Vector2 boundingVolumeA = bodyA->getBoundingVolume();
    Math::Vector2 boundingVolumeB = bodyB->getBoundingVolume();
    Math::Vector2 minA = bodyA->getPosition() - (boundingVolumeA / 2);
    Math::Vector2 maxA = bodyA->getPosition() + (boundingVolumeA / 2);
    Math::Vector2 minB = bodyB->getPosition() - (boundingVolumeB / 2);
    Math::Vector2 maxB = bodyB->getPosition() + (boundingVolumeB / 2);

    if (maxA.x < minB.x || maxB.x < minA.x || maxA.y < minB.y || minA.y > maxB.y) manifold.colliding = false;

    return manifold;
}
