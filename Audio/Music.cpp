#include "Music.h"

Music::Music(const std::string_view filePath) :
m_music(nullptr),
m_musicFilePath(filePath),
m_isMuted(false)
{
	assert(typeid(filePath) == typeid(std::string_view) && !filePath.empty() && "Music filepath cannot have an empty value");
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
	m_music = Mix_LoadMUS(m_musicFilePath.c_str());
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