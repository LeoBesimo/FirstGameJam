#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Core/Math/CoreMath.hpp"

namespace Core 
{
	class Window 
	{
		friend class ParticleManager;

	public:
		Window(unsigned int width = 100, unsigned int height = 100, std::string title = "Window");
		~Window();

		bool isOpen();

		std::vector<sf::Event> getEvents();

		void rect(float x, float y, float width, float height);
		void line(float x1, float y1, float x2, float y2);
		void circle(float x, float y, float radius);
		void drawSprite(sf::Sprite& sprite, float x, float y, float scaleFactor);

		void text(float x, float y, std::string text, unsigned int size);

		void fill(int r = 0, int g = 0, int b = 0, int alpha = 255);
		void noFill();
		void stroke(int r = 0, int g = 0, int b = 0, int alpha = 255);
		void noStroke();

		void loadSpritesheet(std::string path);
		void loadTexture(int x, int y, int width, int height);

		void clear();
		void setClearColor(int r = 255, int g = 255, int b = 255, int alpha = 255);
		void display();
		void close();

		void zoomView(float zoomFactor);
		void moveView(float offsetX, float offsetY);
		void setView(float x, float y);
		void setViewSize(uint16_t width, uint16_t height);

		void draw(std::vector<sf::Vertex> vertexArray, sf::PrimitiveType type);
		void setFullscreen(bool fullScreen);
		void setResolution(unsigned int width, unsigned int height);

		bool isFullscreen();

		Math::Vector2 mapPixelToCoords(float x, float y);
		Math::Vector2 mapPixelToCoords(Math::Vector2 point);

		sf::RenderWindow& getSFMLWindow();

		sf::Color getStrokeColor();
		sf::Color getFillColor();

	private:
		unsigned int m_Width, m_Height;

		sf::Color m_ClearColor;
		sf::Color m_StrokeColor;
		sf::Color m_FillColor;

		sf::RenderWindow m_Window;
		sf::CircleShape m_CircleShape;
		sf::RectangleShape m_RectangleShape;
		sf::Vertex m_Line[2];
		sf::Sprite m_Sprite;

		sf::Image m_Spritesheet;
		sf::Texture m_Texture;

		sf::View m_View = m_Window.getDefaultView();

		sf::Text m_Text;
		sf::Font m_Font;

		std::string m_Title;

		bool m_Fullscreen = false;
	};
}
