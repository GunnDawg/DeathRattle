#pragma once
#include <SDL_mixer.h>

//TODO: Add .MP3 support for a custom music library the engine will poll before game starts (Calvin)

class Music
{
public:
	Music()=default;
	Music(const char* filePath);

	void Load();
	void Unload();
	inline void Play() const { Mix_PlayMusic(mMusic, -1); }
	inline void Pause() const { Mix_PauseMusic(); }
	inline void Stop() const { Mix_HaltMusic(); }
	inline void Resume() const { Mix_ResumeMusic(); }
	void SetVolume(int v);

private:
	Mix_Music* mMusic             = nullptr;
	const char* mMusicFilePath    = nullptr;
};