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

		static void Load(Music& m);
		static void Unload(Music& m);
		static void Play(Music& m);
		static void Pause(Music& m);
		static void Stop(Music& m);
		static void Resume(Music& m);
		static void Setvolume(Music& m, int v);

		inline static Music m_GamePlayMusic            = Music("Assets/Audio/Music/bgmusic.wav");
		inline static Music m_MenuMusic                = Music("Assets/Audio/Music/menumusic.wav");

		MusicManager(MusicManager const&)=delete;
		void operator=(MusicManager const&)=delete;
		~MusicManager();

		//static Sound IntroSound;


	private:
		MusicManager()=default;
};