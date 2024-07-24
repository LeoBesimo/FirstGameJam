#pragma once

#include <string>
#include <SFML/Graphics.hpp>

namespace Core 
{
	class Window 
	{
	public:
		Window(unsigned int width, unsigned int height, std::string title);
		~Window();

		bool isOpen();



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
