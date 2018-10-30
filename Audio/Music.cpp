#include "Music.h"

Music::Music(const char* filePath) :
m_musicFilePath(filePath)
{

}

Music::~Music()
{
	if (m_music != nullptr)
	{
		Mix_FreeMusic(m_music);
	}
}

void Music::Load()
{
	m_music = Mix_LoadMUS(m_musicFilePath);
	if (m_music == nullptr)
	{
		printf("Error loading music file. Error: %s\n", Mix_GetError());
	}

	Mix_VolumeMusic(MIX_MAX_VOLUME / 4);
}

void Music::Mute()
{
	Mix_VolumeMusic(MIX_MAX_VOLUME - MIX_MAX_VOLUME);
	m_isMuted = true;
}

void Music::Unmute()
{
	Mix_VolumeMusic(MIX_MAX_VOLUME / 4);
	m_isMuted = false;
}