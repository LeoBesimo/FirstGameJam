#pragma once
#include "Core/Core.h"


class Player
{
public:
	Player();
	~Player();

	std::shared_ptr<Core::Physics::RectangleShape> getPhysicsBody();
	void setPhysicsBody(std::shared_ptr<Core::Physics::RectangleShape> body);

	void render(std::shared_ptr<Core::Window> window);

	void addForce(Core::Math::Vector2 force);

private:
	std::shared_ptr<Core::Physics::RectangleShape> m_Body;
};
