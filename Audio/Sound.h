#pragma once
#include <SDL_mixer.h>

class Sound
{
public:
	Sound()=default;
	Sound(const char* filePath);

	void Load();
	void Unload();
	inline void Play() const { Mix_PlayChannel(-1, mChunk, 0); }
	void setVolume(int v) const;

private:
	Mix_Chunk* mChunk                = nullptr;
	const char* mSoundFilePath       = nullptr;
};