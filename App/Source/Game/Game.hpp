#pragma once

#include <Core/Core.h>
#include "Player.hpp"
#include "Level/Wall.hpp"

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
    sf::Sprite m_testAnimation;
    
    std::shared_ptr<Core::Physics::RectangleShape> m_PhysicsRect;
    std::shared_ptr<Player> m_Player = std::make_shared<Player>(Player());
};