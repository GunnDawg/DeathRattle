#pragma once
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

		void Load(Music& m);
		void Unload(Music& m);
		void Play(Music& m);
		void Pause(Music& m);
		void Stop(Music& m);
		void Resume(Music& m);
		void Setvolume(Music& m, int v);

		Music GamePlayMusic            = Music("Assets/Audio/Music/bgmusic.wav");
		Music MenuMusic                = Music("Assets/Audio/Music/menumusic.wav");

	private:
		MusicManager()=default;
		~MusicManager()=default;
};