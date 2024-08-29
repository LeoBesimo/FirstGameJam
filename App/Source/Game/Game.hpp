#pragma once

#include <Core/Core.hpp>
#include "Player.hpp"
#include "Level/Wall.hpp"
#include "Level/Room.hpp"

class Game
    : public Core::BaseApplication
{
public:
    Game() {}
    ~Game() {}

    void init() override;
    void preUpdate() override;
    void update(float dt) override;
    void render() override;

private:
    sf::Sprite m_testSprite;
    sf::Sprite m_testAnimation;
    
    std::shared_ptr<Core::Physics::RectangleShape> m_PhysicsRect;
    std::shared_ptr<Player> m_Player = std::make_shared<Player>(Player());
    std::shared_ptr<Wall> m_Wall = std::make_shared<Wall>(Wall(Core::Math::Vector2(400,200),Core::Math::Vector2(600,60)));
    Room m_Room;

    float m_Color[3] = { (float)255 / 255,(float)0 / 255, (float)100 / 255 };


    bool playerFollowsMouse = false;
};