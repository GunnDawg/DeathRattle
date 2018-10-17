#pragma once
#include <SDL_mixer.h>
#include <cstdio>
#include <cassert>

class Sound
{
public:
	Sound()=default;
	Sound(const char* filePath);
	~Sound();

	void Load();
	void Unload();
	inline void Play() const { Mix_PlayChannel(-1, m_chunk, 0); }
	void setVolume(int v) const;

private:

	Mix_Chunk* m_chunk;
	const char* m_soundFilePath;
};