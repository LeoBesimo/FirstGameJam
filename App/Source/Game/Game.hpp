#pragma once

#include <Core/Core.h>

class Game
    : public Core::BaseApplication
{
public:
    Game();
    ~Game();

    void update(float dt) override;
};