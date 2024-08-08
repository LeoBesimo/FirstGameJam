#include "Window.hpp"

Core::Window::Window(unsigned int width, unsigned int height, std::string title):
	m_Width(width), m_Height(height), m_Window(sf::VideoMode(width,height), title)
{

	m_Window.setFramerateLimit(60);
	m_Font.loadFromFile("Fonts/Roboto-Regular.ttf");
}

Core::Window::~Window()
{
}

bool Core::Window::isOpen()
{
	return m_Window.isOpen();
}

std::vector<sf::Event> Core::Window::getEvents()
{
	std::vector<sf::Event> events;
	
	sf::Event event;
	while (m_Window.pollEvent(event))
	{
		events.push_back(event);
	}

	return events;
}

void Core::Window::rect(float x, float y, float width, float height)
{
	m_RectangleShape.setPosition(sf::Vector2f(x, y));
	m_RectangleShape.setSize(sf::Vector2f(width, height));
	m_RectangleShape.setFillColor(m_FillColor);
	m_RectangleShape.setOutlineColor(m_StrokeColor);

	m_Window.draw(m_RectangleShape);
}

void Core::Window::line(float x1, float y1, float x2, float y2)
{
	m_Line[0] = sf::Vertex(sf::Vector2f(x1, y1), m_StrokeColor);
	m_Line[1] = sf::Vertex(sf::Vector2f(x2, y2), m_StrokeColor);

	m_Window.draw(m_Line, 2, sf::Lines);
}

void Core::Window::circle(float x, float y, float radius)
{
	m_CircleShape.setPosition(sf::Vector2f(x, y));
	m_CircleShape.setRadius(radius);
	m_CircleShape.setFillColor(m_FillColor);
	m_CircleShape.setOutlineColor(m_StrokeColor);

	m_Window.draw(m_CircleShape);
}

void Core::Window::drawSprite(sf::Sprite& sprite, float x, float y, float scaleFactor)
{
	sprite.setPosition(x, y);
	sprite.setScale(scaleFactor, scaleFactor);
	
	m_Window.draw(sprite);
}

void Core::Window::text(float x, float y, std::string text, unsigned int size)
{
	m_Text.setFont(m_Font);
	m_Text.setPosition(sf::Vector2f(x, y));
	m_Text.setCharacterSize(size);
	m_Text.setFillColor(m_FillColor);
	m_Text.setString(text);

	m_Window.draw(m_Text);
}

void Core::Window::fill(int r, int g, int b, int alpha)
{
	sf::Color fillColor(r, g, b, alpha);
	m_FillColor = fillColor;
}

void Core::Window::noFill()
{
	sf::Color fillColor(0, 0, 0, 0);
	m_FillColor = fillColor;
}

void Core::Window::stroke(int r, int g, int b, int alpha)
{
	sf::Color strokeColor(r, g, b, alpha);
	m_StrokeColor = strokeColor;
}

void Core::Window::noStroke()
{
	sf::Color strokeColor(0, 0, 0, 0);
	m_StrokeColor = strokeColor;
}

void Core::Window::loadSpritesheet(std::string path)
{
	m_Spritesheet.loadFromFile(path);
}

void Core::Window::loadTexture(int x, int y, int width, int height)
{
	sf::IntRect area(x, y, width, height);
	m_Texture.loadFromImage(m_Spritesheet, area);
}

void Core::Window::clear()
{
	m_Window.clear(m_ClearColor);
}

void Core::Window::setClearColor(int r, int g, int b, int alpha)
{
	sf::Color clearColor(r, g, b, alpha);
	m_ClearColor = clearColor;
}

void Core::Window::display()
{
	m_Window.display();
}

void Core::Window::close()
{
	m_Window.close();
}

void Core::Window::zoomView(float zoomFactor)
{
	m_View.zoom(zoomFactor);
	m_Window.setView(m_View);
}

void Core::Window::moveView(float offsetX, float offsetY)
{
	m_View.move(offsetX, offsetY);
	m_Window.setView(m_View);
}

void Core::Window::setView(float x, float y)
{
	m_View.setCenter(x, y);
	m_Window.setView(m_View);
}

void Core::Window::draw(std::vector<sf::Vertex> vertexArray, sf::PrimitiveType type)
{
	m_Window.draw(&vertexArray[0], vertexArray.size(), type);
}

Core::Math::Vector2 Core::Window::mapPixelToCoords(float x, float y)
{
	sf::Vector2f temp = m_Window.mapPixelToCoords(sf::Vector2i(x,y));
	return Core::Math::Vector2(temp.x,temp.y);
}

Core::Math::Vector2 Core::Window::mapPixelToCoords(Math::Vector2 point)
{
	return mapPixelToCoords(point.x, point.y);
}
