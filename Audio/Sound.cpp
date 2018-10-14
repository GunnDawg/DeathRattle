#include "Sound.h"

Sound::Sound(const char* filePath) : 
m_chunk(nullptr),
m_soundFilePath(filePath)
{
	
}

Sound::~Sound()
{
	if (m_chunk != nullptr)
	{
		Mix_FreeChunk(m_chunk);
		printf("SOUND UNLOADED: \t---> \t%s\n", m_soundFilePath);
	}
}

Mix_Chunk* Sound::Load(const char* filePath)
{
	m_soundFilePath = filePath;

	m_chunk = Mix_LoadWAV(m_soundFilePath);
	if (m_chunk == nullptr)
	{
		printf("Error loading audio file. Error: %s\n", Mix_GetError());
	}

	return(m_chunk);
}