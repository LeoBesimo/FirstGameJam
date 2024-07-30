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
		void playSound(sf::Sound sound, std::string soundID);

	private:

		std::vector<std::tuple<std::string, sf::SoundBuffer>> m_SoundList;

	};
}