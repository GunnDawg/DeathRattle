#pragma once
#include "Texture.h"

class Game;

class Animation
{
public:
	Animation()=default;
	Animation(const char* filePath, unsigned int numFramesX, unsigned int numFramesY, double speed);

	void Load(unsigned int x, unsigned int y, unsigned int w, unsigned int h);
	void Play(double dt);
	void Draw();
	inline void Start() { m_isPlaying = true; }
	inline void Stop() { m_isPlaying = false; }
	inline void Unload() { m_Texture.Unload(); }

private:
	Game* game                           = nullptr;

	Texture m_Texture;
	SDL_Rect m_cropRect                  = { };
	SDL_Rect m_posRect                   = { };

	const unsigned int m_numFramesX      = 0;
	const unsigned int m_numFramesY      = 0;
	unsigned int m_frameWidth            = 0;
	unsigned int m_frameHeight           = 0;
	unsigned int m_currentFrame          = 0;
	const double m_animSpeed             = 0;
	double m_frameTime                   = 0.0;

	bool m_isPlaying                     = true;
};