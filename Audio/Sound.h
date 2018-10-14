#pragma once

#include <SDL_mixer.h>
#include <cstdio>

class Sound
{
public:
	Sound()=default;
	Sound(const char* filePath);
	~Sound();

	Mix_Chunk* Load(const char* filePath);
	inline void Unload() { Mix_FreeChunk(m_chunk); printf("Sound Unloaded: %s\n", m_soundFilePath);
	};
	inline void Play() const { Mix_PlayChannel(-1, m_chunk, 0); }
	inline void setVolume(int v) const { Mix_VolumeChunk(m_chunk, MIX_MAX_VOLUME / v); }

private:

	Mix_Chunk* m_chunk;
	const char* m_soundFilePath;
};