#pragma once

#include <Core/Core.h>
#include "Player.hpp"

class Game
    : public Core::BaseApplication
{
public:
    Game();
    ~Game();

    void update(float dt) override;
    void render() override;

private:
    sf::Sprite m_testSprite;
    
    std::shared_ptr<Core::Physics::RectangleShape> m_PhysicsRect;
    Player m_Player;
};