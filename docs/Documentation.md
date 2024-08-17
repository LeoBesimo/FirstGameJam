# This is the Documentation of the Core Library

## [Core](Core.md)
## [Base Application](BaseApplication.md)
## [System](Systems/Systems.md)
## [Renderer](Renderer/Renderer.md)
## [Audio](Audio/Audio.md)
## [Math](Math/CoreMath.md)
## [Physics](Physics/Physics.md)

## Example Program
```cpp
#include <Core.hpp>

class Application :
    public Core::BaseApplication
{
public:
    Application();

    void init() override
    {

    }

    void update(float deltaTime) override
    {

    }

    void render() override
    {
        // Sets the Fillcolor of the Rectangle to Red
        m_Window->fill(255,0,0);
        // Draws a rectangle at 200, 200 with size 100, 100
        m_Window->rect(200,200,100,100);
    }

}

int main()
{
    // Create Application
    Application app;
    // Start the Application
    app.run();

}


```