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

Core::Math::Vector2 Core::Physics::getContactLineRect(std::shared_ptr<RectangleShape> bodyA, std::shared_ptr<LineShape> bodyB)
{
	std::vector<Math::Vector2> pointsA;// = bodyA->getCorners();
	pointsA.push_back(bodyB->getStart());
	pointsA.push_back(bodyB->getEnd());
	std::vector<Math::Vector2> pointsB = bodyA->getCorners();
	unsigned int contactCount = 0;

	Math::Vector2 contact1;
	Math::Vector2 contact2;

	float minDistSqr = FLT_MAX;

	Math::Vector2 closest;

	for (unsigned int i = 0; i < pointsA.size(); i++)
	{

		Math::Vector2 p = pointsA[i];

		for (unsigned int j = 0; j < pointsB.size(); j++)
		{
			Math::Vector2 a = pointsB[j];
			Math::Vector2 b = pointsB[(j + 1) % pointsB.size()];

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

	for (unsigned int i = 0; i < pointsB.size(); i++)
	{

		Math::Vector2 p = pointsB[i];


		Math::Vector2 a = pointsA[0];
		Math::Vector2 b = pointsA[1];

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

	Math::Vector2 contact = contact1;
	if (contactCount == 2) contact = (contact1 + contact2) / 2;

	return contact;
}

Core::Math::Vector2 Core::Physics::getContactCircleRect(std::shared_ptr<RectangleShape> bodyA, std::shared_ptr<CircleShape> bodyB)
{
	std::vector<Math::Vector2> corners = bodyA->getCorners();
	Math::Vector2 pCenter = bodyB->getPosition();
	Math::Vector2 cCenter = bodyA->getPosition();
	float radius = bodyB->getRadius();
	Math::Vector2 cp;

	float minDistSqr = FLT_MAX;

	for (unsigned int i = 0; i < corners.size(); i++)
	{
		int j = (i + 1) % corners.size();
		Math::Vector2 va = corners[i];
		Math::Vector2 vb = corners[j];

		Math::Vector2 contact;
		float distSqr = Math::distPointToLine(cCenter, va, vb, &contact);
		if (distSqr < minDistSqr)
		{
			cp = contact;
			minDistSqr = distSqr;
		}
	}

	return cp;
}

Core::Math::Vector2 Core::Physics::getContactLineCircle(std::shared_ptr<LineShape> bodyA, std::shared_ptr<CircleShape> bodyB)
{
	Math::Vector2 pCenter = bodyA->getPosition();
	Math::Vector2 cCenter = bodyB->getPosition();
	float radius = bodyB->getRadius();
	Math::Vector2 cp;

	float minDistSqr = FLT_MAX;


	Math::Vector2 va = bodyA->getStart();
	Math::Vector2 vb = bodyA->getEnd();

	Math::Vector2 contact;
	float distSqr = Math::distPointToLine(cCenter, va, vb, &contact);
	if (distSqr < minDistSqr)
	{
		cp = contact;
		minDistSqr = distSqr;
	}

	return cp;
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

Core::Math::Vector2 Core::Physics::getMinMaxCircle(Math::Vector2 center, float radius, Math::Vector2 normal)
{
	Math::Vector2 direction = normal;
	direction.normalize();
	direction *= radius;

	Math::Vector2 p1 = center + direction;
	Math::Vector2 p2 = center - direction;

	float min = Math::dot(normal, p1);
	float max = Math::dot(normal, p2);

	if (min > max)
	{
		float t = min;
		min = max;
		max = t;
	}

	return Math::Vector2(min, max);
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

Core::Physics::Manifold Core::Physics::rectLineCollision(std::shared_ptr<RectangleShape> bodyA, std::shared_ptr<LineShape> bodyB)
{
	Manifold m;
	m.bodyA = bodyA;
	m.bodyB = bodyB;

	std::vector<Math::Vector2> normalsPoly = getNormals(bodyA->getCorners());
	Math::Vector2 lineVector = bodyB->getEnd() - bodyB->getStart();
	Math::Vector2 normalLine = Math::Vector2(-lineVector.y, lineVector.x);

	bool separated = false;

	Math::Vector2 normal;
	float minDepth = FLT_MAX;

	for (unsigned int i = 0; i < normalsPoly.size(); i++)
	{
		Math::Vector2 projectionA = getMinMax(bodyA->getCorners(), normalsPoly[i]);
		float dotLineA = Math::dot(bodyB->getStart(), normalsPoly[i]);
		float dotLineB = Math::dot(bodyB->getEnd(), normalsPoly[i]);
		Math::Vector2 projectionB = Math::Vector2(std::min(dotLineA, dotLineB), std::max(dotLineA, dotLineB));//getMinMax(bodyB->getCorners(), normalsPoly1[i]);

		separated = projectionA.x >= projectionB.y || projectionB.x >= projectionA.y;
		if (separated) break;

		float depth = std::min(projectionB.y - projectionA.x, projectionA.y - projectionB.x);

		if (depth < minDepth)
		{
			minDepth = depth;
			normal = normalsPoly[i];
		}
	}

	if (!separated)
	{
		Math::Vector2 projectionA = getMinMax(bodyA->getCorners(), normalLine);
		float dotLineA = Math::dot(bodyB->getStart(), normalLine);
		float dotLineB = Math::dot(bodyB->getEnd(), normalLine);
		Math::Vector2 projectionB = Math::Vector2(std::min(dotLineA, dotLineB), std::max(dotLineA, dotLineB));//getMinMax(bodyB->getCorners(), normalsPoly1[i]);

		separated = projectionA.x >= projectionB.y || projectionB.x >= projectionA.y;

		float depth = std::min(projectionB.y - projectionA.x, projectionA.y - projectionB.x);

		if (depth < minDepth)
		{
			minDepth = depth;
			normal = normalLine;
		}
	}

	m.colliding = !separated;

	if (!separated)
	{
		Math::Vector2 ab = bodyB->getPosition() - bodyA->getPosition();

		if (Math::dot(ab, normal) < 0) normal *= -1;

		m.penetration = minDepth / normal.len();
		m.normal = normal.normalize();
		m.contact = getContactLineRect(bodyA, bodyB);
	}

	return m;
}

Core::Physics::Manifold Core::Physics::rectCircleCollision(std::shared_ptr<RectangleShape> bodyA, std::shared_ptr<CircleShape> bodyB)
{
	Manifold m;

	m.bodyA = bodyA;
	m.bodyB = bodyB;

	std::vector<Math::Vector2> normalsPoly = getNormals(bodyA->getCorners());

	bool separated = false;

	Math::Vector2 normal;
	float minDepth = FLT_MAX;

	for (unsigned int i = 0; i < normalsPoly.size(); i++)
	{
		Math::Vector2 projectionA = getMinMaxCircle(bodyA->getPosition(), bodyB->getRadius(), normalsPoly[i]);
		Math::Vector2 projectionB = getMinMax(bodyA->getCorners(), normalsPoly[i]);

		separated = projectionA.x >= projectionB.y || projectionB.x >= projectionA.y;
		if (separated) break;

		float depth = std::min(projectionB.y - projectionA.x, projectionA.y - projectionB.x);

		if (depth < minDepth)
		{
			minDepth = depth;
			normal = normalsPoly[i];
		}
	}

	Math::Vector2 closestPoint = getClosestPoint(bodyB->getPosition(), bodyA->getCorners());
	Math::Vector2 axis = closestPoint - bodyB->getPosition();

	Math::Vector2 projectionA = getMinMaxCircle(bodyB->getPosition(), bodyB->getRadius(), axis);
	Math::Vector2 projectionB = getMinMax(bodyA->getCorners(), axis);

	separated = (projectionA.x >= projectionB.y || projectionB.x >= projectionA.y);

	if (separated)
	{
		m.colliding = false;
		return m;
	}

	float depth = std::min(projectionB.y - projectionA.x, projectionA.y - projectionB.x);

	if (depth < minDepth)
	{
		minDepth = depth;
		normal = axis;
	}

	m.colliding = !separated;
	if (!separated)
	{
		Math::Vector2 ab = bodyB->getPosition() - bodyA->getPosition();

		if (Math::dot(ab, normal) < 0) normal *= -1;

		m.penetration = minDepth / normal.len();
		m.normal = normal.normalize();
		m.contact = getContactCircleRect(bodyA, bodyB);
	}

	return m;
}

Core::Physics::Manifold Core::Physics::lineCircleCollision(std::shared_ptr<LineShape> bodyA, std::shared_ptr<CircleShape> bodyB)
{
	return Manifold();
}

Core::Physics::Manifold Core::Physics::circleCircleCollision(std::shared_ptr<CircleShape> bodyA, std::shared_ptr<CircleShape> bodyB)
{
	Manifold manifold;

	Math::Vector2 distanceVector = (bodyB->getPosition() - bodyA->getPosition());
	float distance = distanceVector.lenSqr();
	float radii = bodyA->getRadius() + bodyB->getRadius();

	if (distance >= (radii * radii))
	{
		manifold.colliding = false;
		return manifold;
	}

	manifold.colliding = true;
	manifold.bodyA = bodyA;
	manifold.bodyB = bodyB;
	manifold.penetration = radii - distanceVector.len();
	manifold.normal = distanceVector.normalize();
	manifold.contact = bodyA->getPosition() + (manifold.normal * (bodyA->getRadius() - manifold.penetration));

	return manifold;
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
		case ColliderType::LINE:
			return rectLineCollision(std::dynamic_pointer_cast<RectangleShape>(bodyA), std::dynamic_pointer_cast<LineShape>(bodyB));
		case ColliderType::CIRCLE:
			return rectCircleCollision(std::dynamic_pointer_cast<RectangleShape>(bodyA), std::dynamic_pointer_cast<CircleShape>(bodyB));
		}
		break;


	case ColliderType::LINE:
		switch (bodyB->getColliderType())
		{
		case ColliderType::RECT:
			return rectLineCollision(std::dynamic_pointer_cast<RectangleShape>(bodyB), std::dynamic_pointer_cast<LineShape>(bodyA));
		case ColliderType::CIRCLE:
			return lineCircleCollision(std::dynamic_pointer_cast<LineShape>(bodyA), std::dynamic_pointer_cast<CircleShape>(bodyB));
		case ColliderType::LINE:
			return Manifold();
		}
		break;

	case ColliderType::CIRCLE:
		switch (bodyB->getColliderType())
		{
		case ColliderType::RECT:
			return rectCircleCollision(std::dynamic_pointer_cast<RectangleShape>(bodyB), std::dynamic_pointer_cast<CircleShape>(bodyA));
		case ColliderType::CIRCLE:
			return circleCircleCollision(std::dynamic_pointer_cast<CircleShape>(bodyA), std::dynamic_pointer_cast<CircleShape>(bodyB));
		case ColliderType::LINE:
			return lineCircleCollision(std::dynamic_pointer_cast<LineShape>(bodyB), std::dynamic_pointer_cast<CircleShape>(bodyA));
		}
		break;

	default:
		return Manifold();
	}
}
