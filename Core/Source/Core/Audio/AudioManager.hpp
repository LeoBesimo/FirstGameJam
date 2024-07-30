#pragma once

#include <string>
#include <iostream>
#include <SFML/Audio.hpp>

namespace Core
{
	class GameSound
	{
	public:

		GameSound(std::string soundID, std::string path);
		~GameSound();

		std::string m_SoundID;
		sf::SoundBuffer m_Buffer;
		sf::Sound m_Sound;

	};

	class SoundManager
	{
	public:

		SoundManager() {};
		~SoundManager();

		bool playSound(std::string soundID);
		void addSound(std::string soundID, std::string path, int amount = 1);

		std::vector<GameSound*> m_SoundList;

	};
}