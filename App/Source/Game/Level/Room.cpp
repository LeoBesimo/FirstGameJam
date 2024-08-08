#include "Room.hpp"


Room::Room()
{
}

Room::Room(Core::Math::Vector2 position, Core::Math::Vector2 size, std::shared_ptr<Core::Physics::PhysicsWorld> physicsWorld)
{
	using namespace Core;

	m_Positon = position;
	m_Size = size;
	int wallThickness = 32;
	
	Wall wallUp(position - Math::Vector2(0,size.y / 2 - wallThickness), Math::Vector2(size.x, wallThickness));
	Wall wallDown(position + Math::Vector2(0,size.y / 2 - wallThickness), Math::Vector2(size.x, wallThickness));
	Wall wallLeft(position - Math::Vector2(size.x / 2 - wallThickness,0), Math::Vector2(wallThickness, size.y));
	Wall wallRight(position + Math::Vector2(size.x / 2 - wallThickness,0), Math::Vector2(wallThickness, size.y));

	m_PhysicsObjects.push_back(std::make_shared<Wall>(wallUp));
	m_PhysicsObjects.push_back(std::make_shared<Wall>(wallDown));
	m_PhysicsObjects.push_back(std::make_shared<Wall>(wallLeft));
	m_PhysicsObjects.push_back(std::make_shared<Wall>(wallRight));

	for (std::shared_ptr<Physics::PhysicsBody>& body : m_PhysicsObjects)
	{
		physicsWorld->addBody(body);
	}

}
