#include "TextureLoader.hpp"
#include <iostream>

Core::Spritesheet::Spritesheet(std::string spritesheetID, std::string path) 
{
	m_SpritesheetID = spritesheetID;
	m_Spritesheet.loadFromFile(path);
}

Core::Spritesheet::~Spritesheet()
{
}

void Core::TextureLoader::loadSpritesheet(std::string spritesheetID, std::string path)
{
	Spritesheet* spritesheet = new Spritesheet(spritesheetID, path);
	m_SpritesheetList.push_back(spritesheet);
}

void Core::TextureLoader::defineTexture(std::string spritesheetID, std::string textureID, int x, int y, int width, int height) {
	sf::IntRect textureRect(x, y, width, height);
	
	for (std::vector<int>::size_type i = 0; i != m_SpritesheetList.size(); i++) {
		if (m_SpritesheetList[i]->m_SpritesheetID == spritesheetID) {
			m_SpritesheetList[i]->m_Textures[textureID] = textureRect;
		}
	}
}

sf::Sprite Core::TextureLoader::setTexture(sf::Sprite& sprite, std::string spritesheetID, std::string textureID)
{
	for (std::vector<int>::size_type i = 0; i != m_SpritesheetList.size(); i++) {
		if (m_SpritesheetList[i]->m_SpritesheetID == spritesheetID) {
			sprite.setTexture(m_SpritesheetList[i]->m_Spritesheet);
			sprite.setTextureRect(m_SpritesheetList[i]->m_Textures.at(textureID));
		}
	}

	return sprite;
}