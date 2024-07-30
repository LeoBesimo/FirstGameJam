#pragma once

#include <Core/Core.h>

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
    sf::Sound m_testSound;
    
    std::shared_ptr<Core::Physics::RectangleShape> m_PhysicsRect;
};