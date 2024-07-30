#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <unordered_map>

namespace Core
{
	class Spritesheet
	{
	public:

		Spritesheet(std::string spritesheetID, std::string path);
		~Spritesheet();

		std::string m_SpritesheetID;
		sf::Texture m_Spritesheet;
		std::unordered_map<std::string, sf::IntRect> m_Textures;

	};
	
	class TextureLoader
	{
	public:
		TextureLoader() {};

		void loadSpritesheet(std::string spritesheetID, std::string path);
		void defineTexture(std::string spritesheetID, std::string textureID, int x, int y, int width, int height);

		sf::Sprite setTexture(sf::Sprite& sprite, std::string spritesheetID, std::string textureID);

	private:

		std::vector<Spritesheet*> m_SpritesheetList;

	};
}