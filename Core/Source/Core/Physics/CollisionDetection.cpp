#include "CollisionDetection.hpp"

Core::Math::Vector2 Core::Physics::getContactRectRect(std::shared_ptr<RectangleShape> bodyA, std::shared_ptr<RectangleShape> bodyB)
{
	/*std::shared_ptr<RectangleShape> bodyA = std::dynamic_pointer_cast<RectangleShape>(a);
	std::shared_ptr<RectangleShape> bodyB = std::dynamic_pointer_cast<RectangleShape>(b);*/

	std::vector<Math::Vector2> pointsA = bodyA->getCorners();
	std::vector<Math::Vector2> pointsB = bodyB->getCorners();
	unsigned int contactCount = 0;

	Math::Vector2 contact1;
	Math::Vector2 contact2;

	float minDistSqr = FLT_MAX;

	Math::Vector2 closest;

	for (unsigned int i = 0; i < 4; i++)
	{

		Math::Vector2 p = pointsA[i];

		for (unsigned int j = 0; j < 4; j++)
		{
			Math::Vector2 a = pointsB[j];
			Math::Vector2 b = pointsB[(j + 1) % pointsB.size()];

			float distSqr = Math::distPointToLine(p, a, b, &closest);

			if (Math::nearlyEqual(distSqr, minDistSqr))
			{
				if (!Math::nearlyEqual(closest, contact1))
				{
					contactCount = 2;
					contact2 = closest;
				}
			}
			else if (distSqr < minDistSqr)
			{
				minDistSqr = distSqr;
				contactCount = 1;
				contact1 = closest;
			}
		}

	}

	for (unsigned int i = 0; i < 4; i++)
	{

		Math::Vector2 p = pointsB[i];

		for (unsigned int j = 0; j < 4; j++)
		{
			Math::Vector2 a = pointsA[j];
			Math::Vector2 b = pointsA[(j + 1) % 4];

			float distSqr = Math::distPointToLine(p, a, b, &closest);

			if (Math::nearlyEqual(distSqr, minDistSqr))
			{
				if (!nearlyEqual(closest, contact1))
				{
					contactCount = 2;
					contact2 = closest;
				}
			}
			else if (distSqr < minDistSqr)
			{
				minDistSqr = distSqr;
				contactCount = 1;
				contact1 = closest;
			}
		}
	}

	Math::Vector2 contact = contact1;
	if (contactCount == 2) contact = (contact1 + contact2) / 2;

	return contact;
}

std::vector<Core::Math::Vector2> Core::Physics::getNormals(std::vector<Math::Vector2> corners)
{
    std::vector<Math::Vector2> normals(corners.size());

    for (unsigned int i = 0; i < corners.size(); i++)
    {
        unsigned int j = (i + 1) % corners.size();
        Math::Vector2 edge = corners[j] - corners[i];
        normals[i] = (Math::Vector2(-edge.y, edge.x));
    }
    return normals;
}

Core::Math::Vector2 Core::Physics::getMinMax(std::vector<Math::Vector2> corners, Math::Vector2 normal)
{
    float minProj = Math::dot(corners[0], normal);
    float maxProj = Math::dot(corners[0], normal);

    for (unsigned int i = 1; i < corners.size(); i++)
    {
        float currentProj = Math::dot(corners[i], normal);
        if (currentProj < minProj)
        {
            minProj = currentProj;
        }

        if (currentProj > maxProj)
        {
            maxProj = currentProj;
        }
    }
    return Math::Vector2(minProj, maxProj);
}

Core::Math::Vector2 Core::Physics::getClosestPoint(Math::Vector2 center, std::vector<Math::Vector2> points)
{
    float minDistance = FLT_MAX;
    Math::Vector2 closest;
    Math::Vector2 cp;
    for (unsigned int i = 0; i < points.size(); i++)
    {
        float dist = Math::distPointToLine(center, points[i], points[(i + 1) % points.size()], &cp);
        if (dist < minDistance)
        {
            minDistance = dist;
            closest = cp;
        }
    }

    return closest;
}

bool Core::Physics::boundingBoxCollision(std::shared_ptr<PhysicsBody> bodyA, std::shared_ptr<PhysicsBody> bodyB)
{
    bool colliding = true;

    Math::Vector2 boundingVolumeA = bodyA->getBoundingVolume();
    Math::Vector2 boundingVolumeB = bodyB->getBoundingVolume();
    Math::Vector2 minA = bodyA->getPosition() - (boundingVolumeA / 2);
    Math::Vector2 maxA = bodyA->getPosition() + (boundingVolumeA / 2);
    Math::Vector2 minB = bodyB->getPosition() - (boundingVolumeB / 2);
    Math::Vector2 maxB = bodyB->getPosition() + (boundingVolumeB / 2);

    if (maxA.x < minB.x || maxB.x < minA.x || maxA.y < minB.y || minA.y > maxB.y) colliding = false;

    return colliding;
}

Core::Physics::Manifold Core::Physics::rectRectCollision(std::shared_ptr<RectangleShape> bodyA, std::shared_ptr<RectangleShape> bodyB)
{
	Manifold m;

	/*std::shared_ptr<RectangleShape> bodyA = std::dynamic_pointer_cast<RectangleShape>(a);
	std::shared_ptr<RectangleShape> bodyB = std::dynamic_pointer_cast<RectangleShape>(b);*/


	m.bodyA = bodyA;
	m.bodyB = bodyB;

	std::vector<Math::Vector2> normalsPoly1 = getNormals(bodyA->getCorners());
	std::vector<Math::Vector2> normalsPoly2 = getNormals(bodyB->getCorners());

	bool separated = false;

	Math::Vector2 normalA;
	Math::Vector2 normalB;
	Math::Vector2 normal;
	float minDepthA = FLT_MAX;
	float minDepthB = FLT_MAX;
	float minDepth = FLT_MAX;

	for (unsigned int i = 0; i < normalsPoly1.size(); i++)
	{
		Math::Vector2 projectionA = getMinMax(bodyA->getCorners(), normalsPoly1[i]);
		Math::Vector2 projectionB = getMinMax(bodyB->getCorners(), normalsPoly1[i]);

		separated = projectionA.x >= projectionB.y || projectionB.x >= projectionA.y;
		if (separated) break;

		float depth = std::min(projectionB.y - projectionA.x, projectionA.y - projectionB.x);

		if (depth < minDepthA)
		{
			minDepthA = depth;
			normalA = normalsPoly1[i];
		}
	}

	if (!separated)
	{
		for (unsigned int i = 0; i < normalsPoly2.size(); i++)
		{
			Math::Vector2 projectionA = getMinMax(bodyA->getCorners(), normalsPoly2[i]);
			Math::Vector2 projectionB = getMinMax(bodyB->getCorners(), normalsPoly2[i]);


			separated = projectionA.x >= projectionB.y || projectionB.x >= projectionA.y;
			if (separated) break;

			float depth = std::min(projectionB.y - projectionA.x, projectionA.y - projectionB.x);

			if (depth < minDepthB)
			{
				minDepthB = depth;
				normalB = normalsPoly2[i];
			}
		}
	}

	m.colliding = !separated;

	if (!separated)
	{
		float penetrationA = minDepthA / normalA.len();
		float penetrationB = minDepthB / normalB.len();

		if (penetrationA < penetrationB)
		{
			m.penetration = penetrationA;
			normal = normalA;
		}
		else
		{
			m.penetration = penetrationB;
			normal = normalB;
		}

		Math::Vector2 ab = bodyB->getPosition() - bodyA->getPosition();

		if (Math::dot(ab, normal) < 0) normal *= -1;

		//m.penetration = minDepth / normal.len();

		//Math::Vector2 penetration = normal.normalize() * minDepth;

		//m.penetration = penetration.len();

		m.normal = normal.normalize();
		m.contact = getContactRectRect(bodyA, bodyB);
	}

	return m;
}

Core::Physics::Manifold Core::Physics::collide(std::shared_ptr<PhysicsBody> bodyA, std::shared_ptr<PhysicsBody> bodyB)
{
	switch (bodyA->getColliderType())
	{
	case ColliderType::RECT:
		switch (bodyB->getColliderType())
		{
		case ColliderType::RECT:
			return rectRectCollision(std::dynamic_pointer_cast<RectangleShape>(bodyA), std::dynamic_pointer_cast<RectangleShape>(bodyB));
		}
	}

	return Manifold();
}
