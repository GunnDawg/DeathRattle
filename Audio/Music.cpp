#include "Music.h"

Music::Music(const char* filePath) :
m_musicFilePath(filePath)
{

}

void Music::Load()
{
	m_music = Mix_LoadMUS(m_musicFilePath);
	if (m_music == nullptr)
	{
		printf("Error loading music file. Error: %s\n", Mix_GetError());
	}

	printf("MUSIC LOADED: \t\t---> \t%s\n", m_musicFilePath);

	Mix_VolumeMusic(MIX_MAX_VOLUME / 4);
}

void Music::Unload()
{
	Mix_FreeMusic(m_music);
	printf("MUSIC UNLOADED: \t---> \t%s\n", m_musicFilePath);
}

void Music::SetVolume(int v)
{
	assert(v > 0 && "Volume cannot be divided by 0");
	Mix_VolumeMusic(MIX_MAX_VOLUME / v);
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