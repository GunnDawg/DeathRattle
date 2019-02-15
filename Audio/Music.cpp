#include "Music.h"

Music::Music(const char* filePath) :
mMusicFilePath(filePath)
{

}

void Music::Load()
{
	if (mMusic == nullptr)
	{
		mMusic = Mix_LoadMUS(mMusicFilePath);
		if (mMusic == nullptr)
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
	if (mMusic != nullptr)
	{
		Mix_FreeMusic(mMusic);
		mMusic = nullptr;
		GUNN_CORE_INFO("MUSIC UNLOADED: {0}", mMusicFilePath);
	}
}

void Music::SetVolume(int v)
{
	assert(v > 0 && "Volume cannot be divided by 0");
	Mix_VolumeMusic(MIX_MAX_VOLUME / v);
}