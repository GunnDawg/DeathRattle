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

		static void Load();
		static void Play();
		static void Pause();
		static void Resume();
		static void Update();

		static bool isMenuMusic;
		static bool isGamePlayMusic;

		static Music m_music;

		MusicManager(MusicManager const&) = delete;
		void operator=(MusicManager const&) = delete;
		~MusicManager();

		static Sound IntroSound;


	private:
		MusicManager() {};
};