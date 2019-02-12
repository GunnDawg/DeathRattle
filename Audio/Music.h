#pragma once

#include <SDL_mixer.h>
#include <cassert>
#include <string>
#include "Log/Log.h"

//TODO: Add .MP3 support for a custom music library the engine will poll before game starts (Calvin)

class Music
{
public:
	Music()=default;
	Music(const char* filePath);

	void Load();
	void Unload();
	inline void Play() const { Mix_PlayMusic(m_music, -1); }
	inline void Pause() const { Mix_PauseMusic(); }
	inline void Stop() const { Mix_HaltMusic(); }
	inline void Resume() const { Mix_ResumeMusic(); }
	void SetVolume(int v);

private:
	Mix_Music* m_music             = nullptr;
	const char* m_musicFilePath    = nullptr;
};