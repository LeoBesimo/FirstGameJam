#include "AudioManager.hpp"

void Core::AudioManager::loadSound(std::string soundID, std::string path)
{
	sf::SoundBuffer soundBuffer;
	sf::Sound sound;

	if (!soundBuffer.loadFromFile(path))
	{
		std::cout << "Error: Sound not found";
	}
	else
	{
		sound.setBuffer(soundBuffer);
		m_SoundList.emplace_back(soundID, soundBuffer, sound);
	}
}

void Core::AudioManager::playSound(std::string soundID)
{
	for (const auto& soundObj : m_SoundList)
	{
		if (std::get<0>(soundObj) == soundID)
		{
			//std::get<2>(soundObj).play();
		}
	}
}