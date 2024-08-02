#include "Player.hpp"

Player::Player() :
	Core::Physics::RectangleShape(Core::Math::Vector2(400, 400), Core::Math::Vector2(64, 128))
{
}

Player::~Player()
{
}


void Player::render(std::shared_ptr<Core::Window> window)
{
	window->circle(m_Position.x - 16, m_Position.y - 16, 16);
}

