#include "AudioManager.hpp"

void Core::AudioManager::loadSound(std::string soundID, std::string path)
{
	sf::SoundBuffer soundBuffer;

	if (!soundBuffer.loadFromFile(path))
	{
		std::cout << "Error: Sound not found";
	}
	else
	{
		m_SoundList.emplace_back(soundID, soundBuffer);
	}
}

void Core::AudioManager::playSound(sf::Sound& sound, std::string soundID)
{
	for (const auto& soundObj : m_SoundList)
	{
		if (std::get<0>(soundObj) == soundID)
		{
			sound.setBuffer(std::get<1>(soundObj));
		}
	}
	sound.play();
}