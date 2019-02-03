#pragma once
#include <SDL_mixer.h>
#include <cassert>
#include "Log/Log.h"

class Sound
{
public:
	Sound()=default;
	Sound(const char* filePath);
	~Sound()=default;

	void Load();
	void Unload();
	inline void Play() const { Mix_PlayChannel(-1, m_chunk, 0); }
	void setVolume(int v) const;

private:
	Sound(const Sound& obj)=delete;
	Sound& operator=(const Sound&)=delete;

	Mix_Chunk* m_chunk                = nullptr;
	const char* m_soundFilePath       = nullptr;
};