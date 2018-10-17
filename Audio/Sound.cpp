#include "Sound.h"

Sound::Sound(const char* filePath) : 
m_chunk(nullptr),
m_soundFilePath(filePath)
{
	
}

Sound::~Sound()
{

}

void Sound::Load()
{
	m_chunk = Mix_LoadWAV(m_soundFilePath);
	if (m_chunk == nullptr)
	{
		printf("Error loading audio file. Error: %s\n", Mix_GetError());
	}
	else
	{
		printf("SOUND LOADED: \t\t---> \t%s\n", m_soundFilePath);
	}
}

void Sound::Unload()
{
	if (m_chunk != nullptr)
	{
		Mix_FreeChunk(m_chunk);
		printf("SOUND UNLOADED: \t---> \t%s\n", m_soundFilePath);
	}
}

void Sound::setVolume(int v) const
{
	assert(v > 0 && "Volume cannot be divided by 0");
	Mix_VolumeChunk(m_chunk, MIX_MAX_VOLUME / v);
}