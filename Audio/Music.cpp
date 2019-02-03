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
			GUNN_CORE_ERROR("Error loading music file: {0}. Error: {1}",m_musicFilePath, Mix_GetError());
		}
		else
		{
			GUNN_CORE_INFO("MUSIC LOADED: {0}", m_musicFilePath);
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
		GUNN_CORE_INFO("MUSIC UNLOADED: {0}", m_musicFilePath);
	}
}

void Music::SetVolume(int v)
{
	assert(v > 0 && "Volume cannot be divided by 0");
	Mix_VolumeMusic(MIX_MAX_VOLUME / v);
}