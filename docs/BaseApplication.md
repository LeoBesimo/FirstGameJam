# BaseApplication.hpp

## [Docs](Documentation.md)

## Usage
Create an Application Class which publicly inherits from the BaseApplication class
``` cpp
#include <Core.hpp>

class Application :
    public Core::BaseApplication
{
public:
    Application();

    void init() override;
    void update(float deltaTime) override;
    void render() override;
}

```

## Protected Fields
```cpp
bool m_RenderPhysicsBodies;
std::shared_ptr<Core::Window> m_Window;
Core::EventHandler m_EventHandler;
Core::TextureLoader m_TextureLoader
Core::AnimationManager m_AnimationManager;
Core::SoundManager m_SoundManager;

Core::Math::Vector2 m_MousePosition;

std::shared_ptr<Core::Phyiscs::PhysicsWorld> m_PhysicsWorld;

Core::ParticleManager m_ParticleManager;
````

## Public Functions
The init() function gets called once after the run function gets called;
```cpp
virtual void init();
```

The update() function gets called every Application update;
```cpp
virtual void update(float deltaTime);
```

The render function gets called every Application update after the update function gets called;
```cpp
virtual void render();
```

The run function is the Application entrypoint
```cpp
void run();
```

## Application update order
1. Window Clear
2. Eventhandler update
3. PhysicsWorld update
4. ParticleManager update
5. Update function
6. if enabled Render Physics Bodies
7. Render function
8. Render Particles
