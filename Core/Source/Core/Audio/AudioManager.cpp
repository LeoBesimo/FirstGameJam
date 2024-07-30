#include "AudioManager.hpp"

Core::GameSound::GameSound(std::string soundID, std::string path) {
	m_SoundID = soundID;
	m_Buffer.loadFromFile(path);
	m_Sound.setBuffer(m_Buffer);
}

Core::GameSound::~GameSound() {

}

Core::SoundManager::~SoundManager() {
	while (!m_SoundList.empty()) {
		m_SoundList.pop_back();
	}
}

void Core::SoundManager::addSound(std::string soundID, std::string path, int amount) {
	for (int i = 0; i != amount; i++) {
		GameSound* gameSound = new GameSound(soundID, path);
		m_SoundList.push_back(gameSound);
	}
}

bool Core::SoundManager::playSound(std::string soundID) {
	for (std::vector<int>::size_type i = 0; i != m_SoundList.size(); i++) {
		if (m_SoundList[i]->m_SoundID == soundID && m_SoundList[i]->m_Sound.getStatus() == sf::SoundSource::Status::Stopped) {
			m_SoundList[i]->m_Sound.play();
			return true;
		}
	}

	return false;
}

bool Core::SoundManager::loadMusic(std::string musicID, std::string path) {
	if (!m_Music.openFromFile(path)) {
		return false;
	}

	m_MusicList.emplace_back(musicID, path);
	return true;
}

void Core::SoundManager::playMusic(std::string musicID) {
	for (const auto& musicObj : m_MusicList)
	{
		if (std::get<0>(musicObj) == musicID)
		{
			m_Music.openFromFile(std::get<1>(musicObj));
		}
	}

	m_Music.play();
}

void Core::SoundManager::setMusicVolume(float volume) {
	m_Music.setVolume(volume);
}

void Core::SoundManager::pauseMusic() {
	m_Music.pause();
}

void Core::SoundManager::stopMusic() {
	m_Music.stop();
}