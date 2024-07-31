#include "AnimationManager.hpp"

void Core::AnimationManager::loadAnimationsheet(std::string animationsheetID, std::string path)
{
	sf::Texture animationsheet;
	animationsheet.loadFromFile(path);

	m_Animationsheets[animationsheetID] = animationsheet;
}

void Core::AnimationManager::addAnimation(std::string animationID, std::string animationsheetID, sf::Vector2u sheetSize, sf::Vector2u frameSize, sf::Vector2u currentFrame, sf::Vector2u startingFrame, sf::Vector2u endingFrame, int frameRate)
{
	m_Animations[animationID] = animationsheetID;

	m_SheetSizes[animationID].x = sheetSize.x;
	m_SheetSizes[animationID].y = sheetSize.y;

	m_FrameSizes[animationID].x = frameSize.x;
	m_FrameSizes[animationID].y = frameSize.y;

	m_CurrentFrames[animationID].x = currentFrame.x;
	m_CurrentFrames[animationID].y = currentFrame.y;

	m_StartingFrames[animationID].x = startingFrame.x;
	m_StartingFrames[animationID].y = startingFrame.y;

	m_EndingFrames[animationID].x = endingFrame.x;
	m_EndingFrames[animationID].y = endingFrame.y;

	m_FrameRates[animationID] = frameRate;
}

void Core::AnimationManager::update(std::string animationID, sf::Sprite& sprite)
{

}