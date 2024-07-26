#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace Core 
{
	class Window 
	{
	public:
		Window(unsigned int width = 100, unsigned int height = 100, std::string title = "Window");
		~Window();

		bool isOpen();

		std::vector<sf::Event> getEvents();

		void rect(float x, float y, float width, float height);
		void line(float x1, float y1, float x2, float y2);
		void circle(float x, float y, float radius);

		void fill(int r = 0, int g = 0, int b = 0, int alpha = 1);

		void clear(int r = 255, int g = 255, int b = 255, int alpha = 1);
		void display();
		void close();

	private:
		unsigned int m_Width, m_Height;

		sf::Color m_ClearColor;
		sf::Color m_StrokeColor;
		sf::Color m_FillColor;

		sf::RenderWindow m_Window;
		sf::CircleShape m_CircleShape;
		sf::RectangleShape m_RectangleShape;
		sf::Vertex m_Line[2];

	};
}
