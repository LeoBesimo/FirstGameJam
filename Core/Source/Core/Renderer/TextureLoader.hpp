#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace Core
{
	class TextureLoader
	{
	public:
		TextureLoader() {};

		void loadSpritesheet(std::string spritesheetID, std::string path);

		sf::Texture getSpritesheet(std::string spritesheetID);
		sf::Sprite getSprite(std::string spritesheetID, int x, int y, int width, int height);

	private:

		std::vector<std::tuple<std::string, sf::Texture>> m_SpritesheetList;

	};
}