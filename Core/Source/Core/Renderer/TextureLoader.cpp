#include "TextureLoader.hpp"
#include <iostream>

void Core::TextureLoader::loadSpritesheet(std::string spritesheetID, std::string path)
{
	sf::Texture spritesheet;

	if (!spritesheet.loadFromFile(path))
	{
		std::cout << "Error: Texture not found";
	}
	else
	{
		m_SpritesheetList.emplace_back(spritesheetID, spritesheet);
		//m_SpriteSheets.push_back({ spritesheetID,spritesheet });
	}

}

sf::Texture Core::TextureLoader::getSpritesheet(std::string spritesheetID)
{
	sf::Texture spritesheet;

	for (const auto& spritesheetObj : m_SpritesheetList)
	{
		if (std::get<0>(spritesheetObj) == spritesheetID)
		{
			spritesheet = std::get<1>(spritesheetObj);
		}
	}

	return spritesheet;
}

sf::Sprite Core::TextureLoader::getSprite(sf::Sprite& sprite, std::string spritesheetID, int x, int y, int width, int height)
{
	//sf::Texture spritesheet;
	////sf::Sprite sprite;
	sf::IntRect textureRect(x, y, width, height);

	for (const auto& spritesheetObj : m_SpritesheetList) {
		if (std::get<0>(spritesheetObj) == spritesheetID) {
			//spritesheet = std::get<1>(spritesheetObj);
			sprite.setTexture(std::get<1>(spritesheetObj));
		}
	}

	/*for (SheetIdentifier& sheet : m_SpriteSheets)
	{
		if(sheet.id == spritesheetID)
		{
			sprite.setTexture(sheet.texture);
		}
	}*/

	sprite.setTextureRect(textureRect);

	return sprite;
}