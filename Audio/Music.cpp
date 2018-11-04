#include "Music.h"

Music::Music(const char* filePath) :
m_musicFilePath(filePath)
{

}

void Music::Load()
{
	if (m_music == nullptr)
	{
		m_music = Mix_LoadMUS(m_musicFilePath);
		if (m_music == nullptr)
		{
			printf("Error loading music file. Error: %s\n", Mix_GetError());
		}
		else
		{
			printf("MUSIC LOADED: \t\t---> \t%s\n", m_musicFilePath);
			Mix_VolumeMusic(MIX_MAX_VOLUME / 4);
		}
	}
}

void Music::Unload()
{
	if (m_music != nullptr)
	{
		Mix_FreeMusic(m_music);
		m_music = nullptr;
		printf("MUSIC UNLOADED: \t---> \t%s\n", m_musicFilePath);
	}
}

void Music::SetVolume(int v)
{
	assert(v > 0 && "Volume cannot be divided by 0");
	Mix_VolumeMusic(MIX_MAX_VOLUME / v);
}