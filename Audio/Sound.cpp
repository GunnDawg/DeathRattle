#include "Sound.h"

Sound::Sound(const char* filePath) : 
m_soundFilePath(filePath)
{
	
}

void Sound::Load()
{
	m_chunk = Mix_LoadWAV(m_soundFilePath);
	if (m_chunk == nullptr)
	{
		GUNN_CORE_ERROR("Error loading audio file: {0}. Error: {1}",m_soundFilePath, Mix_GetError());
	}
	else
	{
		GUNN_CORE_INFO("SOUND LOADED: {0}", m_soundFilePath);
	}
}

void Sound::Unload()
{
	if (m_chunk != nullptr)
	{
		Mix_FreeChunk(m_chunk);
		m_chunk = nullptr;
		GUNN_CORE_INFO("SOUND UNLOADED: {0}", m_soundFilePath);
	}
}

void Sound::setVolume(int v) const
{
	assert(v > 0 && "Volume cannot be divided by 0");
	Mix_VolumeChunk(m_chunk, MIX_MAX_VOLUME / v);
}