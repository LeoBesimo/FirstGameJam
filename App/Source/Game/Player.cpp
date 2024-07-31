#include "Player.hpp"

Player::Player()
{
	//m_Body = std::make_shared<Core::Physics::PhysicsBody>(Core::Physics::RectangleShape(Core::Math::Vector2(100, 100), Core::Math::Vector2(64, 128)));
}

Player::~Player()
{
}

std::shared_ptr<Core::Physics::RectangleShape> Player::getPhysicsBody()
{
	return m_Body;
}

void Player::setPhysicsBody(std::shared_ptr<Core::Physics::RectangleShape> body)
{
	m_Body = body;
}

void Player::render(std::shared_ptr<Core::Window> window)
{
	window->circle(m_Body->getPosition().x - 8, m_Body->getPosition().y - 8, 16);
}

void Player::addForce(Core::Math::Vector2 force)
{
	m_Body->addForce(force);
}
