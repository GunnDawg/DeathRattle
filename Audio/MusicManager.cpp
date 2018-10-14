#include "MusicManager.h"

bool MusicManager::isGamePlayMusic = true;
bool MusicManager::isMenuMusic = true;
Music MusicManager::m_music = Music("Assets/Audio/Music/bgmusic.wav");

MusicManager::~MusicManager()
{

}

void MusicManager::Load()
{
	m_music.Load();
}

void MusicManager::Play()
{
	m_music.Play();
}

void MusicManager::Update()
{
	if (!isMenuMusic)
	{
		m_music.Pause();
	}
	else if (isMenuMusic)
	{
		m_music.Resume();
	}
}