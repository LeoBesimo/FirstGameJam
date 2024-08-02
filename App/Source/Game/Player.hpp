#pragma once
#include "Core/Core.h"


class Player:
	public Core::Physics::RectangleShape
{
public:
	Player();
	~Player();

	void render(std::shared_ptr<Core::Window> window);

private:
};
