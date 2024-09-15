#include "BaseApplication.hpp"

Core::BaseApplication::BaseApplication()
{
}

Core::BaseApplication::~BaseApplication()
{
}

void Core::BaseApplication::init()
{
}

void Core::BaseApplication::preUpdate()
{
}

void Core::BaseApplication::update(float dt)
{
	//std::cout << dt << "\n";
}

void Core::BaseApplication::render()
{
}

void Core::BaseApplication::run()
{
	m_Window = std::unique_ptr<Core::Window>(new Core::Window(1000, 1000, "Test"));
	m_PhysicsWorld = std::make_shared<Physics::PhysicsWorld>(Physics::PhysicsWorld());
	sf::Clock deltaClock;
	sf::Time sfTime = deltaClock.restart();
	float deltaTime = 1.f;

	if (!ImGui::SFML::Init(m_Window->getSFMLWindow())) return;

	init();

	while (m_Window->isOpen())
	{
		std::vector<sf::Event> events = m_Window->getEvents();

		for (sf::Event& event : events)
		{
			ImGui::SFML::ProcessEvent(event);
			if (event.type == sf::Event::Closed)
			{
				m_Window->close();
			}
		}

		m_Window->setClearColor();

		m_Window->clear();

		preUpdate();

		ImGui::SFML::Update(m_Window->getSFMLWindow(), sfTime);

		m_EventHandler.update(events);
		m_MousePosition = m_Window->mapPixelToCoords(m_EventHandler.m_MousePosition);
		m_PhysicsWorld->update(deltaTime);
		m_ParticleManager.update(deltaTime);
		update(deltaTime);
		if (m_RenderPhysicsBodies) renderPhysicsBodies();
		render();
		m_ParticleManager.render(m_Window);
		ImGui::SFML::Render(m_Window->getSFMLWindow());
		m_Window->display();

		sfTime = deltaClock.restart();
		deltaTime = sfTime.asSeconds();
	}

	ImGui::SFML::Shutdown();
}

void Core::BaseApplication::close()
{
	m_Window->close();
}

void Core::BaseApplication::renderPhysicsBodies()
{
	std::vector<std::shared_ptr<Physics::PhysicsBody>> bodies = m_PhysicsWorld->getBodies();
	std::vector<sf::Vertex> vertecies;

	for (std::shared_ptr<Physics::PhysicsBody> body : bodies)
	{
		switch (body->getColliderType())
		{
		case Physics::ColliderType::RECT:
		{
			sf::Vertex vertex;
			Math::Vector4 color = body->getColor();
			std::vector<Math::Vector2> corners = std::dynamic_pointer_cast<Physics::RectangleShape>(body)->getCorners();
			for (unsigned int i = 0; i < corners.size(); i++)
			{
				if (m_PhysicsWireframe)
				{
					vertex.position.x = corners[i].x;
					vertex.position.y = corners[i].y;
					vertex.color = m_Window->getStrokeColor();
					vertecies.push_back(vertex);
					vertex.position.x = corners[(i + 1) % corners.size()].x;
					vertex.position.y = corners[(i + 1) % corners.size()].y;
					vertecies.push_back(vertex);
					//m_Window->line(corners[i].x, corners[i].y, corners[(i + 1) % corners.size()].x, corners[(i + 1) % corners.size()].y);
				}
				else
				{
					vertex.position.x = corners[i].x;
					vertex.position.y = corners[i].y;
					vertex.color = m_Window->getStrokeColor();//sf::Color(color.x, color.y, color.z, color.w);
					vertecies.push_back(vertex);
				}
			}
			break;
		}

		case Physics::ColliderType::CIRCLE:
		{
			float radius = std::dynamic_pointer_cast<Physics::CircleShape>(body)->getRadius();
			m_Window->circle(body->getPosition().x, body->getPosition().y, radius);
			break;
		}
		

		default:
			break;
		}
	}
	if (!vertecies.empty() && !m_PhysicsWireframe)
		m_Window->draw(vertecies, sf::Quads);
	else if (!vertecies.empty() && m_PhysicsWireframe)
		m_Window->draw(vertecies, sf::Lines);
}
