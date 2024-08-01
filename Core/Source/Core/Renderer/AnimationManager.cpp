#include "AnimationManager.hpp"
#include <iostream>

void Core::AnimationManager::loadAnimationsheet(std::string animationsheetID, std::string path)
{
	sf::Texture animationsheet;
	animationsheet.loadFromFile(path);

	m_Animationsheets[animationsheetID] = animationsheet;
}

void Core::AnimationManager::addAnimation(std::string animationID, std::string animationsheetID, sf::Vector2i sheetSize, sf::Vector2i frameSize, sf::Vector2i currentFrame, int frameRate)
{
	m_Animations[animationID] = animationsheetID;

	m_SheetSizes[animationID].x = sheetSize.x;
	m_SheetSizes[animationID].y = sheetSize.y;

	m_FrameSizes[animationID].x = frameSize.x;
	m_FrameSizes[animationID].y = frameSize.y;

	m_CurrentFrames[animationID].x = currentFrame.x;
	m_CurrentFrames[animationID].y = currentFrame.y;

	m_FrameRates[animationID] = frameRate;
}

void Core::AnimationManager::update(std::string animationID, sf::Sprite& sprite)
{
	if (m_SheetSizes[animationID] != sf::Vector2i(0, 0)) {
		
		int positionX = m_FrameSizes[animationID].x * m_CurrentFrames[animationID].x;
		int positionY = m_FrameSizes[animationID].y * m_CurrentFrames[animationID].y;

		sf::IntRect frameRect(positionX, positionY, m_FrameSizes[animationID].x, m_FrameSizes[animationID].y);

		sprite.setTexture(m_Animationsheets[m_Animations[animationID]]);
		sprite.setTextureRect(frameRect);

		if (m_CurrentFrames[animationID].x < m_SheetSizes[animationID].x - 1) {
			m_CurrentFrames[animationID].x++;
		}
		else {
			if (m_CurrentFrames[animationID].y < m_SheetSizes[animationID].y - 1) {
				m_CurrentFrames[animationID].x = 0;
				m_CurrentFrames[animationID].y++;
			}
			else {
				m_CurrentFrames[animationID].x = 0;
				m_CurrentFrames[animationID].y = 0;
			}
		}

	} else {
		std::cout << "Failed updating " << animationID << std::endl;
	}
}