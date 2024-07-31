#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace Core
{
	class AnimationManager
	{
	public:

		AnimationManager() {};
		~AnimationManager() {};

		void update(std::string animationID, sf::Sprite& sprite);

		void loadAnimationsheet(std::string animationsheetID, std::string path);
		void addAnimation(std::string animationID, std::string animationsheetID, sf::Vector2u sheetSize, sf::Vector2u frameSize, sf::Vector2u currentFrame, sf::Vector2u startingFrame, sf::Vector2u endingFrame, int frameRate);

	private:

		std::map<std::string, sf::Texture> m_Animationsheets;
		
		std::map<std::string, std::string> m_Animations;

		std::map<std::string, sf::Vector2u> m_CurrentFrames;
		std::map<std::string, sf::Vector2u> m_StartingFrames;
		std::map<std::string, sf::Vector2u> m_EndingFrames;

		std::map<std::string, sf::Vector2u> m_SheetSizes;
		std::map<std::string, sf::Vector2u> m_FrameSizes;

		std::map<std::string, int> m_FrameRates;

		std::map<std::string, int> m_TimesUpdated;

	};
}