#pragma once

#include <string>
#include <iostream>
#include <SFML/Audio.hpp>

namespace Core
{
	class AudioManager
	{
	public:
		AudioManager() {};

		void loadSound(std::string soundID, std::string path);
		void playSound(std::string soundID);

	private:

		std::vector<std::tuple<std::string, sf::SoundBuffer, sf::Sound>> m_SoundList;

	};
}