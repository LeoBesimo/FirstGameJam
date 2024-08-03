#include "Player.hpp"

Player::Player() :
	Core::Physics::RectangleShape(Core::Math::Vector2(400, 400), Core::Math::Vector2(64, 128))
{
	m_Tag.tagName = L"Player";
}

Player::~Player()
{
}

void Player::update(float dt)
{
	RectangleShape::update(dt);
	m_Velocity *= 0.999;
	m_Velocity.limit(150);
}


void Player::render(std::shared_ptr<Core::Window> window)
{
	window->circle(m_Position.x - 16, m_Position.y - 16, 16);
}

