#pragma once

#include <SDL_mixer.h>
#include <cassert>
#include <cstdio>
#include <string>

//TODO: Add .MP3 support for a custom music library the engine will poll before game starts (Calvin)

class Music
{
public:
	Music()=default;
	Music(const char* filePath);
	~Music();

	void Load();
	inline void Play() const { Mix_PlayMusic(m_music, -1); }
	inline void Pause() const { Mix_PauseMusic(); }
	inline void Resume() const { Mix_ResumeMusic(); }
	inline void Stop() const { Mix_HaltMusic(); }
	void Mute();
	void Unmute();

	inline bool isMuted() const { return m_isMuted; }

private:
	Music(const Music& obj)=delete;
	Music& operator=(const Music&)=delete;


	Mix_Music* m_music             = nullptr;
	const char* m_musicFilePath    = nullptr;

	bool m_isMuted                 = false;
};