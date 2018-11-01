#pragma once
#include "Sound.h"
#include "Music.h"
#include <SDL_mixer.h>

class MusicManager
{
	public:
		static MusicManager& getInstance()
		{
			static MusicManager instance;
			return instance;
		}

		MusicManager(const MusicManager&) = delete;
		MusicManager(MusicManager&&) = delete;
		MusicManager& operator=(const MusicManager&) = delete;
		MusicManager& operator=(MusicManager&&) = delete;

		static void Load(Music& m);
		static void Unload(Music& m);
		static void Play(Music& m);
		static void Pause(Music& m);
		static void Stop(Music& m);
		static void Resume(Music& m);
		static void Setvolume(Music& m, int v);
		inline Music* GamePlayMusic() { return &m_GamePlayMusic; }

		static inline Music m_GamePlayMusic            = Music("Assets/Audio/Music/bgmusic.wav");
		static inline Music m_MenuMusic                = Music("Assets/Audio/Music/menumusic.wav");

	private:
		MusicManager()=default;
		~MusicManager();
};